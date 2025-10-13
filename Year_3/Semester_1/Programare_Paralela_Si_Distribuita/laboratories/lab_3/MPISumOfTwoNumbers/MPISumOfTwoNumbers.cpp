#include <iostream>
#include <mpi.h>
#include <ostream>
#include "Variant2Scatter.h"
#include "SequentialVariant0.h"
#include "Variant1.h"
#include "Variant3Async.h"

#include <fstream>
#include <string>

bool areFilesEqual(const std::string& filePath1, const std::string& filePath2) {
	std::ifstream file1(filePath1, std::ios::binary);
	std::ifstream file2(filePath2, std::ios::binary);

	// Check if files were successfully opened
	if (!file1.is_open() || !file2.is_open()) {
		return false; // If either file can't be opened, consider them not equal
	}

	// Compare files byte by byte
	char ch1, ch2;
	while (file1.get(ch1) && file2.get(ch2)) {
		if (ch1 != ch2) {
			return false; // Files differ at some byte
		}
	}


	// Check if both files have reached EOF
	return file1.eof() && file2.eof();
}
void generateRandomNumber(int size, std::string filename) {

	std::ofstream file(filename);
	file << size << std::endl;
	for (int i = 0; i < size; i++) {
		file << rand() % 10;
	}
	file.close();
}
void generateFiles()
{
	// test 2
	std::string path = "./2/";
	std::string number1 = "first_number.txt";
	std::string number2 = "second_number.txt";
	generateRandomNumber(1000, path + number1);
	generateRandomNumber(1000, path + number2);
	// test 3
	path = "./3/";
	generateRandomNumber(100, path + number1);
	generateRandomNumber(10000, path + number2);

}

int main(int argc, char** argv)
{



	// t1
	//SequentialVariant0 seq = SequentialVariant0("1/first_number.txt", "1/second_number.txt", "1/seq_result.txt");
	//std::cout << seq.determineSum();
	//Variant1 var1 = Variant1(argc, argv, "1/first_number.txt", "1/second_number.txt", "1/var1_result.txt");
	//std::cout << var1.determineSum() << std::endl;
	//areFilesEqual("1/seq_result.txt", "1/var1_result.txt");

	//Variant2Scatter var2 = Variant2Scatter(argc, argv, "1/first_number.txt", "1/second_number.txt", "1/var2_result.txt");
	//std::cout << var2.determineSum() << std::endl;
	//areFilesEqual("1/seq_result.txt", "1/var2_result.txt");

	/*Variant3Async var3 = Variant3Async(argc, argv, "1/first_number.txt", "1/second_number.txt", "1/var3_result.txt");
	var3.determineSum();
	areFilesEqual("1/seq_result.txt", "1/var3_result.txt");*/


	//// t2
	//SequentialVariant0 seq2 = SequentialVariant0("2/first_number.txt", "2/second_number.txt", "2/seq_result.txt");
	//std::cout << seq2.determineSum() << std::endl;

	/*Variant1 var12 = Variant1(argc, argv, "3/first_number.txt", "3/second_number.txt", "3/var1_result.txt");
	std::cout << var12.determineSum() << std::endl;
	areFilesEqual("2/seq_result.txt", "2/var1_result.txt");*/

	//Variant2Scatter var22 = Variant2Scatter(argc, argv, "2/first_number.txt", "2/second_number.txt", "2/var2_result.txt");
	//std::cout << var22.determineSum() << std::endl;
	//areFilesEqual("2/seq_result.txt", "2/var2_result.txt");


	//Variant3Async var32 = Variant3Async(argc, argv, "2/first_number.txt", "2/second_number.txt", "2/var3_result.txt");
	//var32.determineSum();
	//areFilesEqual("2/seq_result.txt", "2/var3_result.txt");

	//// t3
	///
	//SequentialVariant0 seq3 = SequentialVariant0("3/first_number.txt", "3/second_number.txt", "3/seq_result.txt");
	//std::cout << seq3.determineSum() << std::endl;
	//Variant1 var13 = Variant1(argc, argv, "3/first_number.txt", "3/second_number.txt", "3/var1_result.txt");
	//std::cout << var13.determineSum();
	//if (!areFilesEqual("3/seq_result.txt", "3/var1_result.txt")) std::cout << "FALSE";


	//Variant2Scatter var23 = Variant2Scatter(argc, argv, "3/first_number.txt", "3/second_number.txt", "3/var2_result.txt");
	//std::cout << var23.determineSum() << std::endl;
	//areFilesEqual("3/seq_result.txt", "3/var2_result.txt");

	/*Variant3Async var33 = Variant3Async(argc, argv, "3/first_number.txt", "3/second_number.txt", "3/var3_result.txt");
	var33.determineSum();
	areFilesEqual("3/seq_result.txt", "3/var3_result.txt");*/

	////// t4
	//SequentialVariant0 seq4 = SequentialVariant0("4/first_number.txt", "4/second_number.txt", "4/seq_result.txt");
	//std::cout << seq4.determineSum() << std::endl;

	//Variant1 var14 = Variant1(argc, argv, "4/first_number.txt", "4/second_number.txt", "4/var1_result.txt");
	//std::cout << var14.determineSum() << std::endl;
	//areFilesEqual("4/seq_result.txt", "4/var1_result.txt");

	//Variant2Scatter var24 = Variant2Scatter(argc, argv, "4/first_number.txt", "4/second_number.txt", "4/var2_result.txt");
	//std::cout << var24.determineSum() << std::endl;
	//areFilesEqual("4/seq_result.txt", "4/var2_result.txt");

	Variant3Async var34 = Variant3Async(argc, argv, "4/first_number.txt", "4/second_number.txt", "4/var3_result.txt");
	var34.determineSum();
	areFilesEqual("4/seq_result.txt", "4/var3_result.txt");


	return 0;
}
