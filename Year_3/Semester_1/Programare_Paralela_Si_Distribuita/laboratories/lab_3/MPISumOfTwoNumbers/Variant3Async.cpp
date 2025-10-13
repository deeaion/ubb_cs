#include "Variant3Async.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <mpi.h>
#include <vector>
#include "Utils.h"

Variant3Async::Variant3Async(int argc, char** argv, const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile)
    : argc(argc), argv(argv), path_first_number(path_first_number), path_second_number(path_second_number), resultFile(resultFile)
{
}

int Variant3Async::sumaADouaNumere(std::vector<int>& first_number, std::vector<int>& second_number, std::vector<int>& local_result, bool& almostOverflow) {
    int carry = 0;
    int pos = 0;
    almostOverflow = true; // Assume almost overflow until proven otherwise

    // Add corresponding digits in the chunks, up to the size of the smaller chunk
    while (pos < first_number.size() && pos < second_number.size()) {
        int sum = first_number[pos] + second_number[pos] + carry;
        carry = sum / 10;
        local_result[pos] = sum % 10;
        if (local_result[pos] != 9) {
            almostOverflow = false; // Reset if any non-9 digit is found
        }
        pos++;
    }

    // If there are remaining digits in the larger chunk, continue with carry
    while (pos < first_number.size()) {
        int sum = first_number[pos] + carry;
        carry = sum / 10;
        local_result[pos] = sum % 10;
        if (local_result[pos] != 9) {
            almostOverflow = false;
        }
        pos++;
    }

    return carry; // Return the carry out from this addition
}

int Variant3Async::adaugaCarry(std::vector<int>& numar) {
    int carry = 1; // Start with the carry of 1 to add
    int pos = 0;
    while (pos < numar.size() && carry > 0) {
        numar[pos] += carry;
        carry = numar[pos] / 10;
        numar[pos] = numar[pos] % 10;
        pos++;
    }
    return carry; // Return any overflow carry left
}

double Variant3Async::determineSum() {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    std::chrono::duration<double> elapsed_seconds;
    const int parent = 0;
    int N_Mare, N_Mic, N_1, N_2, chunk_size;
    int lastProcess = size - 1;
    MPI_Request send_carry,get_query;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    if (rank == parent) {
        start = std::chrono::system_clock::now();
        std::ifstream file1(path_first_number);
        std::ifstream file2(path_second_number);
        if (!file1.is_open() || !file2.is_open()) {
            std::cerr << "Error opening files" << std::endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
            return -1;
        }

        Utils utils;
        N_1 = utils.read_number_of_digits(file1);
        N_2 = utils.read_number_of_digits(file2);
        N_Mare = std::max(N_1, N_2);
        N_Mic = std::min(N_1, N_2);

        std::ifstream& biggerNumber = N_1 > N_2 ? file1 : file2;
        std::ifstream& smallerNumber = N_1 > N_2 ? file2 : file1;

        chunk_size = N_Mare / lastProcess;
        int rest_chunk_size = N_Mare % lastProcess;
        int poz_current = 0;

        // Arrays to store async send requests
        MPI_Request* send1SizeRequests = new MPI_Request[size];
        MPI_Request* send2SizeRequests = new MPI_Request[size];
        MPI_Request* send1DigitsRequests = new MPI_Request[size];
        MPI_Request* send2DigitsRequests = new MPI_Request[size];
        MPI_Request* receiveDigitsRequests = new MPI_Request[size];

        std::vector<int> result(N_Mare); // Space for the main result
        int finalCarry = 0;
        int pos = 0;
        int current_chunk_size;

        // Send chunks to each worker
        for (int current_process_id = 1; current_process_id < size; current_process_id++) {
            current_chunk_size = chunk_size + (rest_chunk_size-- > 0 ? 1 : 0);

            std::vector<int> first_chunk = utils.read_chunk_v(biggerNumber, current_chunk_size);
            int currentSmallSize = std::min(current_chunk_size, N_Mic - poz_current);
            std::vector<int> second_chunk = currentSmallSize > 0 ? utils.read_chunk_v(smallerNumber, currentSmallSize) : std::vector<int>();

            MPI_Isend(&current_chunk_size, 1, MPI_INT, current_process_id, 0, MPI_COMM_WORLD, &send1SizeRequests[current_process_id - 1]);
            MPI_Isend(first_chunk.data(), current_chunk_size, MPI_INT, current_process_id, 1, MPI_COMM_WORLD, &send1DigitsRequests[current_process_id - 1]);

            MPI_Isend(&currentSmallSize, 1, MPI_INT, current_process_id, 2, MPI_COMM_WORLD, &send2SizeRequests[current_process_id - 1]);
            if (currentSmallSize > 0) {
                MPI_Isend(second_chunk.data(), currentSmallSize, MPI_INT, current_process_id, 3, MPI_COMM_WORLD, &send2DigitsRequests[current_process_id - 1]);
            }

            poz_current += current_chunk_size;
        }

        file1.close();
        file2.close();

        // Receive result chunks from each worker
        rest_chunk_size = N_Mare % (size - 1);
        for (int i = 1; i < size; i++) {
            int currentChunk = chunk_size + (rest_chunk_size-- > 0 ? 1 : 0);
            MPI_Irecv(result.data() + pos, currentChunk, MPI_INT, i, 4, MPI_COMM_WORLD, &receiveDigitsRequests[i - 1]);
            pos += currentChunk;
        }

        // Wait for the final carry from the last process
        MPI_Recv(&finalCarry, 1, MPI_INT, lastProcess, 5, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Write the result to file, with carry handling for overflow
        std::ofstream file(resultFile);

        // If there is an overflow carry, write it at the beginning of the file
        for (int i = 0; i < N_Mare; i++) file << result[i];
        if (finalCarry > 0) {
            file << finalCarry;
        }
        file.close();

        // Wait for all asynchronous sends to complete
        for (int i = 1; i < size; i++) {
            MPI_Wait(&send1SizeRequests[i - 1], MPI_STATUS_IGNORE);
            MPI_Wait(&send1DigitsRequests[i - 1], MPI_STATUS_IGNORE);
            MPI_Wait(&send2SizeRequests[i - 1], MPI_STATUS_IGNORE);
            MPI_Wait(&send2DigitsRequests[i - 1], MPI_STATUS_IGNORE);
            MPI_Wait(&receiveDigitsRequests[i - 1], MPI_STATUS_IGNORE);
        }

        delete[] send1SizeRequests;
        delete[] send2SizeRequests;
        delete[] send1DigitsRequests;
        delete[] send2DigitsRequests;
        delete[] receiveDigitsRequests;
        elapsed_seconds = std::chrono::system_clock::now() - start;
        std::cout << elapsed_seconds.count();
    }
    else {
        int local_bigger_number_size, local_smaller_number_size;
        std::vector<int> local_bigger_number;
        std::vector<int> local_smaller_number;
        int carry_returnat = 0;
        bool almostOverflow = false;

        MPI_Recv(&local_bigger_number_size, 1, MPI_INT, parent, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        local_bigger_number.resize(local_bigger_number_size);
        MPI_Recv(local_bigger_number.data(), local_bigger_number_size, MPI_INT, parent, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        MPI_Recv(&local_smaller_number_size, 1, MPI_INT, parent, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        local_smaller_number.resize(local_smaller_number_size);
        if (local_smaller_number_size > 0) {
            MPI_Recv(local_smaller_number.data(), local_smaller_number_size, MPI_INT, parent, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // Calculate local sum and determine if there's an "almost overflow" scenario
        int carry_primit = 0;
    	MPI_Irecv(&carry_primit, 1, MPI_INT, rank - 1, 5, MPI_COMM_WORLD, &get_query);

    	carry_returnat = sumaADouaNumere(local_bigger_number, local_smaller_number, local_bigger_number, almostOverflow);

        // Handle carry received from the previous process
        if (rank != 1) {

			MPI_Wait(&get_query, MPI_STATUS_IGNORE);
            if (carry_primit || almostOverflow) {
                int old_carry = carry_primit;
                carry_returnat = adaugaCarry(local_bigger_number);
                if (old_carry == 1) {
                    carry_returnat = 1;
                }
            }
        }

        // Send carry to the next process, if not the last process
        if (rank != lastProcess) {
            MPI_Isend(&carry_returnat, 1, MPI_INT, rank + 1, 5, MPI_COMM_WORLD, &send_carry);
            MPI_Wait(&send_carry, MPI_STATUS_IGNORE);
        }

        // Send the local result back to the parent
        MPI_Send(local_bigger_number.data(), local_bigger_number_size, MPI_INT, parent, 4, MPI_COMM_WORLD);

        // If this is the last process, also send the final carry to the parent
        if (rank == lastProcess) {
            MPI_Send(&carry_returnat, 1, MPI_INT, parent, 5, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return elapsed_seconds.count();
}
