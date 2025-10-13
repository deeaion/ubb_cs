//
// Created by Deea on 10/20/2024.
//

#include "FileManager.h"
#include <fstream>
#include <iostream>

// Constructor
FileManager::FileManager(const std::string &inputFile, const std::string &outputFile)
{
    this->inputFile = inputFile;
    this->outputFile = outputFile;
}

void FileManager::readInput(ConvolutionItems &items)
{
    std::ifstream infile(inputFile);
    if (!infile.is_open())
    {
        std::cerr << "Eroare la deschiderea fișierului: " << inputFile << std::endl;
        return;
    }

    int n, m;
    infile >> n >> m;
    items.n = n;
    items.m = m;
    items.result.resize(n, std::vector<int>(m, 0));
    items.matrix = readMatrix(infile, n, m);

    int k;
    infile >> k;
    items.k = k;

    items.kernel = readMatrix(infile, k, k);

    infile.close();
}
void FileManager::readInput(ArrayConvolutionItems &items)
{
    std::ifstream infile(inputFile);
    if (!infile.is_open())
    {
        std::cerr << "Eroare la deschiderea fișierului: " << inputFile << std::endl;
        return;
    }
    int n, m;
    infile >> n >> m;
    items.n = n;
    items.m = m;
    readMatrixAsArray(infile, items.matrix, n, m);
    int k;
    infile >> k;
    items.k = k;
    readKernel(infile, items.kernel, k, k);
    infile.close();
    items.result.resize(n, std::vector<int>(m, 0));
}
void FileManager::readMatrixAsArray(std::ifstream &infile, std::vector<int> &matrix, int rows, int cols)
{
    for (int i = 0; i < rows * cols; ++i)
    {
        int value;
        infile >> value;
        matrix.push_back(value);
    }
}
void FileManager::writeOutput(const ArrayConvolutionItems &items)
{
    std::ofstream outfile(outputFile);
    if (!outfile.is_open())
    {
        std::cerr << "Nu pot deschide output File! " << outputFile << std::endl;
        return;
    }

    for (int i = 0; i < items.n; ++i)
    {
        for (int j = 0; j < items.m; ++j)
        {
            outfile << items.result[i][j] << " ";
        }
        outfile << std::endl;
    }

    outfile.close();
}
void FileManager::writeOutput(const ConvolutionItems &items)
{
    std::ofstream outfile(outputFile);
    if (!outfile.is_open())
    {
        std::cerr << "Eroare la deschiderea fișierului pentru scriere: " << outputFile << std::endl;
        return;
    }

    for (int i = 0; i < items.n; ++i)
    {
        for (int j = 0; j < items.m; ++j)
        {
            outfile << items.result[i][j] << " ";
        }
        outfile << std::endl;
    }

    outfile.close();
}
std::vector<std::vector<int>> FileManager::readMatrix(std::ifstream &infile, int rows, int cols)
{
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < rows; ++i)
    {
        std::vector<int> row;
        for (int j = 0; j < cols; ++j)
        {
            int value;
            infile >> value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    return matrix;
}
bool FileManager::checkIfTwoFilesAreEqual(const std::string &file1, const std::string &file2)
{
    std::ifstream infile1(file1);
    std::ifstream infile2(file2);

    if (!infile1.is_open() || !infile2.is_open())
    {
        std::cerr << "Eroare la deschiderea fișierelor: " << file1 << " sau " << file2 << std::endl;
        return false;
    }

    int a, b;
    while (infile1 >> a && infile2 >> b)
    {
        if (a != b)
        {
            infile1.close();
            infile2.close();
            return false;
        }
    }

    infile1.close();
    infile2.close();
    return true;
}
void FileManager::readKernel(std::ifstream &infile, std::vector<std::vector<int>> &kernel, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        std::vector<int> row;
        for (int j = 0; j < cols; ++j)
        {
            int value;
            infile >> value;
            row.push_back(value);
        }
        kernel.push_back(row);
    }
}