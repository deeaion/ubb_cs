#ifndef SOLUTION_FILEMANAGER_H
#define SOLUTION_FILEMANAGER_H

#include "ConvolutionItems.h"
#include <string>
#include <fstream>
#include "ArrayConvolutionItems.h"

class FileManager
{
private:
    std::string inputFile;
    std::string outputFile;

public:
    FileManager(const std::string &inputFile, const std::string &outputFile);

    void readInput(ConvolutionItems &items);
    void writeOutput(const ConvolutionItems &items);
    bool checkIfTwoFilesAreEqual(const std::string &file1, const std::string &file2);
    void readInput(ArrayConvolutionItems &items);
    void writeOutput(const ArrayConvolutionItems &items);

private:
    void readMatrix(std::ifstream &infile, int matrix[MAX_N][MAX_M], int rows, int cols);
    void readKernel(std::ifstream &infile, int kernel[MAX_K][MAX_K], int rows, int cols);
    void readMatrixAsArray(std::ifstream &infile, int matrix[MAX_N * MAX_M], int rows, int cols);
};

#endif // SOLUTION_FILEMANAGER_Hs