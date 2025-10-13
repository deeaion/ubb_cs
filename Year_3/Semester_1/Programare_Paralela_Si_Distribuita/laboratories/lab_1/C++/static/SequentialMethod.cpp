#include "SequentialMethod.h"
#include "Utils/FileManager.h"
#include "Utils/MatrixOperations.h"
#include <chrono>
#include <iostream>

// Constructor pentru inițializare
SequentialMethod::SequentialMethod(const std::string &inputFile, const std::string &outputFile)
    : inputFile(inputFile), outputFile(outputFile) {}

// Metoda pentru aplicarea convoluției secvențial
long SequentialMethod::applySequentialConvolution()
{
    if (inputFile.empty())
    {
        std::cerr << "Please provide an input file" << std::endl;
        return -1;
    }

    FileManager fileManager(inputFile, outputFile);
    fileManager.readInput(items);

    auto start = std::chrono::high_resolution_clock::now();
    MatrixOperations::applyConvolution(items, 0, items.n, 0, items.m);
    auto end = std::chrono::high_resolution_clock::now();

    fileManager.writeOutput(items);
    std::string outputFileName = outputFile.substr(outputFile.find_last_of("/\\") + 1);
    FileManager fileManager2(inputFile, ".\\verified_output\\" + outputFileName);
    fileManager2.writeOutput(items);

    double duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    return duration;
}

// Returnează matricea rezultată ca pointer dublu
void SequentialMethod::getResult(int result[MAX_N][MAX_M])
{
    for (int i = 0; i < items.n; ++i)
    {
        for (int j = 0; j < items.m; ++j)
        {
            result[i][j] = items.result[i][j];
        }
    }
}
