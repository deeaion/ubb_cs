//
// Created by Deea on 10/20/2024.
//

#include "BlockPartitioning.h"
#include "../Utils/FileManager.h"
#include "../MyThread.h"
#include "../Utils/VerifyResult.h"
#include <chrono>
#include <iostream>
#include <cmath>
#include <cassert>

BlockPartitioning::BlockPartitioning(const std::string &inputFile, const std::string &outputFile, int numberOfThreads)
    : inputFile(inputFile), outputFile(outputFile), numberOfThreads(numberOfThreads)
{
}

double BlockPartitioning::applyBlockPartitioningConvolution()
{
    if (inputFile.empty())
    {
        std::cerr << "Please provide an input file" << std::endl;
        return -1;
    }

    // citesc
    FileManager fileManager(inputFile, outputFile);
    fileManager.readInput(convolutionItems);

    // nr blocuri
    int numBlocksPerRow = static_cast<int>(std::ceil(std::sqrt(numberOfThreads)));
    int numBlocksPerColumn = numBlocksPerRow;

    int blockRows = convolutionItems.n / numBlocksPerRow;
    int blockColumns = convolutionItems.m / numBlocksPerColumn;

    int remainingRows = convolutionItems.n % numBlocksPerRow;
    int remainingColumns = convolutionItems.m % numBlocksPerColumn;

    std::vector<std::thread> threads;
    int index = 0;

    // Start time measurement
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numBlocksPerRow; i++)
    {
        int rowStart = i * blockRows;
        int rowEnd = rowStart + blockRows;

        if (i == numBlocksPerRow - 1)
        {
            rowEnd = convolutionItems.n;
        }
        else if (i < remainingRows)
        {
            rowEnd++;
        }

        for (int j = 0; j < numBlocksPerColumn; j++)
        {
            int columnStart = j * blockColumns;
            int columnEnd = columnStart + blockColumns;

            if (j == numBlocksPerColumn - 1)
            {
                columnEnd = convolutionItems.m;
            }
            else if (j < remainingColumns)
            {
                columnEnd++;
            }

            threads.emplace_back(&MyThread::run, MyThread(convolutionItems, rowStart, rowEnd, columnStart, columnEnd));
            index++;
        }
    }
    // wait
    for (auto &t : threads)
    {
        t.join();
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    // durata
    double duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();

    // rez
    fileManager.writeOutput(convolutionItems);
    // verificare rezultat
    assert(VerifyResult::verify(inputFile, outputFile));

    return duration;
}
