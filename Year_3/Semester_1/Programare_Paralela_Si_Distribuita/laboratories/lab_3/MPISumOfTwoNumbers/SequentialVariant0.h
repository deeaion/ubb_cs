#pragma once
#include <string>
#include <vector>

class SequentialVariant0
{
public:
	// declare input output paths
	std::string path_first_number;
	std::string path_second_number;
	std::string resultFile;

	// constructor
	SequentialVariant0(const std::string& path_first_number, const std::string& path_second_number, const std::string& resultFile);
	double determineSum();
};

