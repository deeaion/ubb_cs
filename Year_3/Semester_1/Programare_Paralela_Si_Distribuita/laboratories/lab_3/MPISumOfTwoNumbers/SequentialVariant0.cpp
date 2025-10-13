#include "SequentialVariant0.h"

#include <chrono>
#include <iostream>
#include <fstream>

#include "Utils.h"

SequentialVariant0::SequentialVariant0(const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile)
{
	this->path_first_number = path_first_number;
	this->path_second_number = path_second_number;
	this->resultFile = resultFile;
}

double SequentialVariant0::determineSum()
{
	std::ifstream first_number_file(path_first_number);
	std::ifstream second_number_file(path_second_number);
	int first_number_size, second_number_size;
	Utils utils;
	first_number_size = utils.read_number_of_digits(first_number_file);
	second_number_size = utils.read_number_of_digits(second_number_file);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	int max_size = std::max(first_number_size, second_number_size);
	int* first_number = utils.read_file(first_number_file, first_number_size);
	int* second_number = utils.read_file(second_number_file, second_number_size);
	int* result = new int[max_size + 1]();  // Initialize to zero, with extra space for carry

	int carry = 0;
	int posBig = 0;
	int posSmall = 0;
	int posResult = 0;;

	// Add corresponding digits from the least significant (rightmost) to the most significant

	while (posBig < first_number_size && posSmall < second_number_size) {
		int sum = first_number[posBig] + second_number[posSmall] + carry;
		carry = sum / 10;
		result[posResult] = sum % 10;
		posBig++;
		posSmall++;
		posResult++;
	}

	// If there are remaining digits in the larger number, continue with carry
	while (posBig < first_number_size) {
		int sum = first_number[posBig] + carry;
		carry = sum / 10;
		result[posResult] = sum % 10;
		posBig++;
		posResult++;
	}

	// If there are remaining digits in the smaller number, continue with carry
	while (posSmall < second_number_size) {
		int sum = second_number[posSmall] + carry;
		carry = sum / 10;
		result[posResult] = sum % 10;
		posSmall++;
		posResult++;
	}

	// If there is a carry left over, add it to the result
	result[posResult] = carry;


	// Open result file and write result
	std::ofstream resultFileStream(resultFile);
	if (result[max_size] != 0) {
		utils.write_result(resultFileStream, result, max_size + 1);
	}
	else {
		utils.write_result(resultFileStream, result + 1, max_size);
	}


	// Clean up dynamically allocated memory
	delete[] first_number;
	delete[] second_number;
	delete[] result;

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
	double time = elapsed.count();
	return time;
}
