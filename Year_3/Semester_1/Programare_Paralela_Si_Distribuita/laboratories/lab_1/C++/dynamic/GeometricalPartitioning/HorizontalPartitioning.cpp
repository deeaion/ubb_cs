//
// Created by Deea on 10/20/2024.
//

#include "HorizontalPartitioning.h"
#include "../Utils/FileManager.h"
#include "../MyThread.h"
#include <chrono>
#include <iostream>
#include "../Utils/VerifyResult.h"
#include <cassert>
HorizontalPartitioning::HorizontalPartitioning(const std::string &inputFile,
                                               const std::string &outputFile,
                                               int numberOfThreads)
    : inputFile(inputFile),
      outputFile(outputFile),
      numberOfThreads(numberOfThreads)
{
}

double HorizontalPartitioning::applyHorizontalPartitioningConvolution()
{
    if (inputFile.empty())
    {
        std::cerr << "Please provide an input file" << std::endl;
        return -1;
    }
    // citesc
    FileManager fileManager(inputFile, outputFile);
    fileManager.readInput(convolutionItems);

    // impart matricea pe linii
    int linesPerThread = convolutionItems.n / numberOfThreads;
    int rest = convolutionItems.n % numberOfThreads;

    std::vector<std::thread> threads;

    int start = 0;
    int end = linesPerThread;

    // inceput
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numberOfThreads; i++)
    {
        if (rest > 0)
        {
            end++;
            rest--;
        }

        // creez+pornesc thread
        threads.emplace_back(&MyThread::run,
                             MyThread(convolutionItems, start, end, 0, convolutionItems.m));

        start = end;
        end = start + linesPerThread;
    }

    // wait
    for (auto &t : threads)
    {
        t.join();
    }

    auto endTime = std::chrono::high_resolution_clock::now();

    // timp exec
    double duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();

    // fisier
    fileManager.writeOutput(convolutionItems);
    // verific
    assert(VerifyResult::verify(inputFile, outputFile));
    return duration;
}
