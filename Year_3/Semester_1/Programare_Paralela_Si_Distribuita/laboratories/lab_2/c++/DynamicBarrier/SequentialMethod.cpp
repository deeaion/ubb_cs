#include "SequentialMethod.h"
#include "Utils/FileManager.h"
#include "Utils/MatrixOperations.h"
#include <chrono>
#include <iostream>

SequentialMethod::SequentialMethod(const std::string &inputFile, const std::string &outputFile)
        : inputFile(inputFile), outputFile(outputFile) {}

double SequentialMethod::applySequentialConvolution()
{
    if (inputFile.empty())
    {
        std::cerr << "Please provide an input file" << std::endl;
        return -1;
    }

    // Citește matricea de intrare
    FileManager fileManager(inputFile, outputFile);
    fileManager.readInput(items);

    auto startTime = std::chrono::high_resolution_clock::now();

    // Aplică convoluția in-place
    applyInPlaceConvolution();

    auto endTime = std::chrono::high_resolution_clock::now();

    // Scrie rezultatul final în fișierul de ieșire
    fileManager.writeOutput(items);

    // Salvează și pentru validare
    std::string validOutputFile = "./verified_output/output_" + outputFile.substr(outputFile.find_last_of("/\\") + 1);
    FileManager validationFileManager(inputFile, validOutputFile);
    validationFileManager.writeOutput(items);

    double duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    return duration;
}

void SequentialMethod::applyInPlaceConvolution()
{
    int n = items.n;
    int m = items.m;
    auto &matrix = items.matrix;

    // Bufferi temporari pentru a stoca rezultatele convoluției
    std::vector<int> tempRow(m);  // Rezultatele convoluției pe rândul curent
    std::vector<int> prevRow(m);  // Rezultatele convoluției pe rândul anterior

    // Initializează `prevRow` cu rezultatele convoluției pentru primul rând
    for (int j = 0; j < m; j++) {
        prevRow[j] = MatrixOperations::convolution(items, 0, j);
    }

    // Procesează fiecare rând următor
    for (int i = 1; i < n; i++) {
        // Calculează rezultatele convoluției pentru rândul curent
        for (int j = 0; j < m; j++) {
            tempRow[j] = MatrixOperations::convolution(items, i, j);
        }

        // Copiază rândul procesat din `prevRow` în matrice pentru rândul anterior
        for (int j = 0; j < m; j++) {
            matrix[i - 1][j] = prevRow[j];
        }

        // Schimbă referințele între `tempRow` și `prevRow` pentru iterația următoare
        std::swap(tempRow, prevRow);
    }

    // Copiază rezultatele convoluate din `prevRow` în ultima linie a matricei
    for (int j = 0; j < m; j++) {
        matrix[n - 1][j] = prevRow[j];
    }
}

void SequentialMethod::getResult(std::vector<std::vector<int>> &result)
{
    result = items.matrix;
}
