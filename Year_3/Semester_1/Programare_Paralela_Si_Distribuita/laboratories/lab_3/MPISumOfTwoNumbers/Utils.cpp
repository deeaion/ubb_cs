#include "Utils.h"

/*
 *	std::vector<int> read_chunk(std::ifstream& file, int chunk_size);
	std::vector<int> read_file(std::ifstream& file);
	int read_number_of_digits(std::ifstream& file);
	void write_result(std::ofstream& file, const std::vector<int>& result);
 *
 */
int* Utils::read_chunk(std::ifstream& file, int chunk_size)
{
	int* chunk = new int[chunk_size];
	char digit;
	for (int i = 0; i < chunk_size; i++)
	{
		file.get(digit);
		chunk[i] = digit - '0';
	}
	return chunk;
}

std::vector<int> Utils::read_chunk_v(std::ifstream& file, int chunk_size)
{
	std::vector<int> chunk = std::vector<int>(chunk_size);
	char digit;
	for (int i = 0; i < chunk_size; i++)
	{
		file.get(digit);
		chunk[i] = digit - '0';
	}
	return chunk;
}
int* Utils::read_file(std::ifstream& file,int size)
{

	int* number = new int[size];
	char digit;
	// s-ar putea sa primesc un size mai mare ca nr de cifre din file
	// in acest caz completez cu 0
	for (int i = 0; i < size; i++)
	{
		if (file.get(digit))
		{
			number[i] = digit - '0';
		}
		else
		{
			number[i] = 0;
		}
	}
	return number;
}


int Utils::read_number_of_digits(std::ifstream& file)
{
	int number = 0;
	char digit;
	//try and get the number
	while (file.get(digit))
	{
		if (digit == '\n')
		{
			break;
		}
		number = number * 10 + (digit - '0');
	}
	return number;

}

void Utils::write_result(std::ofstream& file, const int* result, int size)
{
	for (int i = 0; i < size; i++)
	{
		file << result[i];
	}
	file << std::endl;
}
