#pragma once
#include <string>

class Variant2Scatter
{
	int argc;
	char** argv;
	std::string path_first_number;
	std::string path_second_number;
	std::string resultFile;
public:
	Variant2Scatter(int argc, char** argv, const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile);
	double determineSum();
	int sumaADouaNumere(int* first_number, int* second_number, int first_size, int second_size, int* local_result);
	int adaugaCarry(int* numar, int size);
};

