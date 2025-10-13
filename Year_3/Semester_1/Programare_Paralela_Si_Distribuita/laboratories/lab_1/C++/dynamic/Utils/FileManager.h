#ifndef SOLUTION_FILEMANAGER_H
#define SOLUTION_FILEMANAGER_H

#include "ConvolutionItems.h"
#include <string>
#include <fstream>
#include "ArrayConvolutionItems.h"
class FileManager
{
public:
    FileManager(const std::string &inputFile, const std::string &outputFile);
    void readInput(ConvolutionItems &items);
    void writeOutput(const ConvolutionItems &items);
    bool checkIfTwoFilesAreEqual(const std::string &file1, const std::string &file2);
    void readInput(ArrayConvolutionItems &items);
    void writeOutput(const ArrayConvolutionItems &items);
    static std::vector<std::vector<int>> readMatrix(std::ifstream &infile, int rows, int cols);

private:
    std::string inputFile;
    std::string outputFile;
    void readKernel(std::ifstream &infile, std::vector<std::vector<int>> &kernel, int rows, int cols);
    void readMatrixAsArray(std::ifstream &infile, std::vector<int> &matrix, int rows, int cols);
};
;

#endif // SOLUTION_FILEMANAGER_H