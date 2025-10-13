#pragma once
#include <string>
#include <vector>

class Variant3Async
{
	int argc;
	char** argv;
	std::string path_first_number;
	std::string path_second_number;
	std::string resultFile;
public:
	Variant3Async(int argc, char** argv, const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile);
	double determineSum();
	int sumaADouaNumere(std::vector<int> &	 first_number, std::vector<int>& second_number, std::vector<int>& local_result,bool & seeOverflow);
	int adaugaCarry(std::vector<int>& numar);
};

