#include "Variant1.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <mpi.h>
#include <vector>
#include "Utils.h"

Variant1::Variant1(int argc, char** argv, const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile)
    : argc(argc), argv(argv), path_first_number(path_first_number), path_second_number(path_second_number), resultFile(resultFile)
{
}

int Variant1::sumaADouaNumere(std::vector<int>& first_number, std::vector<int>& second_number, std::vector<int>& local_result) {
    int carry = 0;
    size_t pos = 0;

    // Add corresponding digits in the chunks, up to the size of the smaller chunk
    while (pos < first_number.size() && pos < second_number.size()) {
        int sum = first_number[pos] + second_number[pos] + carry;
        carry = sum / 10;
        local_result[pos] = sum % 10;
        pos++;
    }

    // If there are remaining digits in the larger chunk, continue with carry
    while (pos < first_number.size()) {
        int sum = first_number[pos] + carry;
        carry = sum / 10;
        local_result[pos] = sum % 10;
        pos++;
    }

    return carry;
}

int Variant1::adaugaCarry(std::vector<int>& numar) {
    int carry = 1;
    size_t pos = 0;
    while (pos < numar.size() && carry > 0) {
        numar[pos] += carry;
        carry = numar[pos] / 10;
        numar[pos] %= 10;
        pos++;
    }
    return carry;
}

double Variant1::determineSum() {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int parent = 0;
    int N_Mare, N_Mic, N_1, N_2, chunk_size;
    int lastProcess = size - 1;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    if (rank == parent) {
        std::ifstream file1(path_first_number);
        std::ifstream file2(path_second_number);
        if (!file1.is_open() || !file2.is_open()) {
            std::cerr << "Error opening files" << std::endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
            return -1;
        }
        std::cout << "HERE";

        Utils utils;
        N_1 = utils.read_number_of_digits(file1);
        N_2 = utils.read_number_of_digits(file2);
        N_Mare = std::max(N_1, N_2);
        N_Mic = std::min(N_1, N_2);

        std::ifstream& biggerNumber = N_1 > N_2 ? file1 : file2;
        std::ifstream& smallerNumber = N_1 > N_2 ? file2 : file1;

        chunk_size = N_Mare / (size - 1);
        int rest_chunk_size = N_Mare % (size - 1);

        int current_process_id = 1;
        int poz_current = 0;

        while (current_process_id < size) {
            int current_chunk_size = chunk_size + (rest_chunk_size > 0 ? 1 : 0);
            if (rest_chunk_size > 0) rest_chunk_size--;

            std::vector<int> first_chunk = utils.read_chunk_v(biggerNumber, current_chunk_size);
            int currentSmallSize = std::min(current_chunk_size, N_Mic - poz_current);
            std::vector<int> second_chunk = currentSmallSize > 0 ? utils.read_chunk_v(smallerNumber, currentSmallSize) : std::vector<int>();

            MPI_Send(&current_chunk_size, 1, MPI_INT, current_process_id, 0, MPI_COMM_WORLD);
            MPI_Send(first_chunk.data(), current_chunk_size, MPI_INT, current_process_id, 0, MPI_COMM_WORLD);
            MPI_Send(&currentSmallSize, 1, MPI_INT, current_process_id, 0, MPI_COMM_WORLD);
            if (currentSmallSize > 0) {
                MPI_Send(second_chunk.data(), currentSmallSize, MPI_INT, current_process_id, 0, MPI_COMM_WORLD);
            }

            current_process_id++;
            poz_current += current_chunk_size;
        }

        biggerNumber.close();
        smallerNumber.close();

        std::vector<int> result(N_Mare);
        int carry = 0;
        int pos = 0;
        rest_chunk_size = N_Mare % (size - 1);

        for (int i = 1; i < size; i++) {
            int currentChunk = chunk_size + (rest_chunk_size > 0 ? 1 : 0);
            if (rest_chunk_size > 0) rest_chunk_size--;

            MPI_Recv(result.data() + pos, currentChunk, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            pos += currentChunk;
        }

        MPI_Recv(&carry, 1, MPI_INT, lastProcess, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::ofstream file(resultFile);

        for (int digit : result) file << digit;
        if (carry > 0) file << carry;
        file.close();

    }
    else {
        int local_bigger_number_size, local_smaller_number_size;
        std::vector<int> local_bigger_number;
        std::vector<int> local_smaller_number;
        int carry_returnat = 0;

        MPI_Recv(&local_bigger_number_size, 1, MPI_INT, parent, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        local_bigger_number.resize(local_bigger_number_size);
        MPI_Recv(local_bigger_number.data(), local_bigger_number_size, MPI_INT, parent, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        MPI_Recv(&local_smaller_number_size, 1, MPI_INT, parent, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (local_smaller_number_size > 0) {
            local_smaller_number.resize(local_smaller_number_size);
            MPI_Recv(local_smaller_number.data(), local_smaller_number_size, MPI_INT, parent, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        std::vector<int> local_result(local_bigger_number_size, 0);
        carry_returnat = sumaADouaNumere(local_bigger_number, local_smaller_number, local_result);

        if (rank != 1) {
            int carry_primit = 0;
            MPI_Recv(&carry_primit, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if (carry_primit) {
                int old_carry = carry_returnat;
                carry_returnat = adaugaCarry(local_result);
                if (old_carry > 0) {
                    carry_returnat = 1;
                }
            }
        }

        if (rank != lastProcess) {
            MPI_Send(&carry_returnat, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        }

        MPI_Send(local_result.data(), local_result.size(), MPI_INT, parent, 0, MPI_COMM_WORLD);
        if (rank == lastProcess) {
            MPI_Send(&carry_returnat, 1, MPI_INT, parent, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
    double time = elapsed.count();
    return time;
}
