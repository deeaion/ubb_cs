#include "Variant2Scatter.h"

#include <chrono>
#include <iostream>
#include <mpi.h>
#include <ostream>
#include <vector>

#include "Utils.h"

/*
 *class Variant2Scatter
{
	int argc;
	char** argv;
	std::string path_first_number;
	std::string path_second_number;
	std::string resultFile;
public:
	Variant2Scatter(int argc, char** argv, const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile);
	double determineSum();
};

*/
int Variant2Scatter::sumaADouaNumere(int* first_number, int* second_number, int first_size, int second_size, int* local_result) {
	int carry = 0;
	int pos = 0;

	// Add corresponding digits in the chunks, up to the size of the smaller chunk
	while (pos < first_size && pos < second_size) {
		int sum = first_number[pos] + second_number[pos] + carry;
		carry = sum / 10;
		local_result[pos] = sum % 10;
		pos++;
	}

	// If there are remaining digits in the larger chunk, continue with carry
	while (pos < first_size) {
		int sum = first_number[pos] + carry;
		carry = sum / 10;
		local_result[pos] = sum % 10;
		pos++;
	}

	return carry;
}

int Variant2Scatter::adaugaCarry(int* numar, int size) {
	int carry = 1;
	int pos = 0;
	while (pos < size && carry > 0) {
		numar[pos] += carry;
		carry = numar[pos] / 10;
		numar[pos] = numar[pos] % 10;
		pos++;
	}
	return carry;
}
Variant2Scatter::Variant2Scatter(int argc, char** argv, const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile)
	: argc(argc), argv(argv), path_first_number(path_first_number), path_second_number(path_second_number), resultFile(resultFile)
{
}

double Variant2Scatter::determineSum()
{
	

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current process id
	MPI_Comm_size(MPI_COMM_WORLD, &size); // get number of processes
	MPI_Status stauts;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//parent
	const int parrent = 0;
	int N; // number of digits
	int N_1;
	int N_2;
	int chunk_size;
	const int last_process = size - 1;
	/*
	 *parinte -> proces 0 citeste numerele le pune in tablouri
	 *mai multe cifre -> adaug cifre nesemnificative
	 *distribui numerele catre procese cu scatter , daca nu merge
	 *p/n maresc N astfel incat sa fie divizibil cu p
	 *asteapta rezultatele de la copii -> gather
	 *scrie rezultatul in fisier
	 */
	int* first_number = nullptr;
	int* second_number = nullptr;
	int* result = nullptr;
	if (rank == parrent)
	{
		//citesc numarul de cifre
		std::ifstream file1(path_first_number);
		std::ifstream file2(path_second_number);
		if (!file1.is_open() || !file2.is_open())
		{
			std::cerr << "Error opening files" << std::endl;
			MPI_Abort(MPI_COMM_WORLD, 1);
			return -1;
		}
		//citesc numarul de cifre
		Utils utils;
		N_1 = utils.read_number_of_digits(file1);
		N_2 = utils.read_number_of_digits(file2);
		// verific cat ar trebui sa fie N
		N = N_1 > N_2 ? N_1 : N_2;
		//daca N nu e divizibil cu p maresc N
		if (N % (last_process) != 0)
		{
			N += (last_process - N % last_process);
		}
		//declar rez
		result = new int[N + 1]();  // Initialize to zero, with extra space for carry
		//citesc numerele
		first_number = utils.read_file(file1, N);
		second_number = utils.read_file(file2, N);
		//inchid fisierele
		file1.close();
		file2.close();
		//calculez chunk size
		chunk_size = N / (size);
	}
	/*
	 *copil-> suma cifrelor si calc carry
	 *fiecare proces in afara de ultimul trimit carry la urmatorul
	 *rez trimit prin gather la parinte
	 */
	 // trimit N la toate procesele
	MPI_Bcast(&chunk_size, 1, MPI_INT, parrent, MPI_COMM_WORLD);

	int local_f_n_size = chunk_size;
	int local_s_n_size = chunk_size;
	int* local_f_n = new int[chunk_size];
	int* local_s_n = new int[chunk_size];
	int* local_res = new int[chunk_size];

	MPI_Scatter(first_number, chunk_size, MPI_INT, local_f_n, chunk_size, MPI_INT, parrent, MPI_COMM_WORLD);
	MPI_Scatter(second_number, chunk_size, MPI_INT, local_s_n, chunk_size, MPI_INT, parrent, MPI_COMM_WORLD);

	int carry_trimis = sumaADouaNumere(local_f_n, local_s_n, local_f_n_size, local_s_n_size, local_res);
	int carry_primit;
	// verific dupa ranks -> orice rank in afara de parinte
	if(rank!=0)
	{
		MPI_Recv(&carry_primit, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if (carry_trimis > 0)
		{
			int carry_vechi = carry_trimis;
			carry_trimis = adaugaCarry(local_res, chunk_size);
			if (carry_vechi > 0)
			{
				carry_trimis = 1;
			}

		}
	}
	if (rank < last_process)
	{
		MPI_Send(&carry_trimis, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
	}
	MPI_Gather(local_res, chunk_size, MPI_INT, result, chunk_size, MPI_INT, parrent, MPI_COMM_WORLD);
	if(rank==last_process)
	{
		MPI_Send(&carry_trimis, 1, MPI_INT, parrent, 0, MPI_COMM_WORLD);
	}
	if (rank == parrent)
	{
		MPI_Recv(&carry_primit, 1, MPI_INT, last_process, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		//scot extra zerouriile de la sf -> las doar unul in caz ca e carry
		while (result[N] == 0)
		{
			N--;
		}
		if (carry_primit > 0)
		{
			N++;
			result[N] = carry_primit;
		}
		//scriu rezultatul
		std::ofstream file(resultFile);
		for (int i = 0; i <= N; i++)
		{
			file << result[i];
		}
		file.close();
		
	}
	
	delete[] first_number;
	delete[] second_number;
	delete[] result;
	delete[] local_f_n;
	delete[] local_s_n;
	delete[] local_res;
	MPI_Finalize();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
	double time = elapsed.count();
	return time;


}