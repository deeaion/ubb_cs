#pragma once
#include <fstream>
#include <vector>

class Utils
{
public:
	int* read_chunk(std::ifstream& file, int chunk_size);
	std::vector<int> read_chunk_v(std::ifstream& file, int chunk_size);
	int* read_file(std::ifstream& file,int size);
	int read_number_of_digits(std::ifstream& file);
	void write_result(std::ofstream& file, const int* result, int size);
};

