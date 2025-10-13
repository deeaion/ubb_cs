#include "DeltaPartitioning.h"
#include "../Utils/FileManager.h"
#include "../Utils/MatrixOperations.h"
#include "../MyDistributionThread.h"
#include "../SequentialMethod.h"
#include "../Utils/VerifyResult.h"
#include <chrono>
#include <iostream>
#include <cmath>
#include <cassert>

DeltaPartitioning::DeltaPartitioning(const std::string &inputFile,
                                     const std::string &outputFile,
                                     int numberOfThreads,
                                     const std::string &distributionType)
    : inputFile(inputFile), outputFile(outputFile),
      numberOfThreads(numberOfThreads),
      distributionType(distributionType)
{
}

double DeltaPartitioning::applyDeltaPartitioningConvolution()
{
    if (inputFile.empty())
    {
        std::cerr << "Please provide an input file" << std::endl;
        return -1;
    }

    // citire date
    FileManager fileManager(inputFile, outputFile);
    fileManager.readInput(convolutionItems);
    // threads
    std::vector<std::thread> threads(numberOfThreads);

    // start
    auto startTime = std::chrono::high_resolution_clock::now();

    // tip specific
    if (distributionType.compare("CYCLIC") == 0)
    {
        distributeCyclic(threads);
    }
    else if (distributionType.compare("LINEAR") == 0)
    {
        distributeLinear(threads);
    }
    else
    {
        std::cerr << "Invalid distribution type" << std::endl;
        return -1;
    }

    // wait
    for (auto &t : threads)
    {
        t.join();
    }

    // time
    auto endTime = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();

    // write to file
    fileManager.writeOutput(convolutionItems);
    // verificare rezultat
    assert(VerifyResult::verify(inputFile, outputFile));
    return duration;
}

void DeltaPartitioning::distributeCyclic(std::vector<std::thread> &threads)
{
    int step = numberOfThreads;
    int totalElements = convolutionItems.n * convolutionItems.m;

    int start = 0;
    int end = totalElements / numberOfThreads;
    int rest = totalElements % numberOfThreads;

    // init threads
    for (int i = 0; i < numberOfThreads; i++)
    {
        if (rest > 0)
        {
            end++;
            rest--;
        }

        MyDistributionThread thread(convolutionItems,
                                    step, numberOfThreads, i, totalElements, i);
        threads[i] = std::thread(&MyDistributionThread::run, thread);

        start = end;
        end = start + totalElements / numberOfThreads;
    }
}

void DeltaPartitioning::distributeLinear(std::vector<std::thread> &threads)
{
    int totalElements = convolutionItems.n * convolutionItems.m;
    int elementsPerThread = totalElements / numberOfThreads;
    int remainder = totalElements % numberOfThreads;

    int start = 0;
    int end = elementsPerThread;

    // Init threads
    for (int i = 0; i < numberOfThreads; ++i)
    {
        if (remainder > 0)
        {
            end++;
            remainder--;
        }
        threads[i] = std::thread([this, start, end, i]()
                                 {
            MyDistributionThread thread( convolutionItems,1,
                                         numberOfThreads, start, end, i);
            thread.run(); });

        start = end;
        end = start + elementsPerThread;
    }
}
