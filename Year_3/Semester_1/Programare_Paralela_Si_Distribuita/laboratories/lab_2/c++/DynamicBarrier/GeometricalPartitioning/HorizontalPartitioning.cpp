#include "HorizontalPartitioning.h"
#include "../Utils/FileManager.h"
#include "../MyThread.h"
#include <chrono>
#include <iostream>
#include "../Utils/VerifyResult.h"
#include <cassert>
#include <barrier>
#include <atomic>

HorizontalPartitioning::HorizontalPartitioning(const std::string &inputFile,
                                               const std::string &outputFile,
                                               int numberOfThreads, VariantType variantType)
        : inputFile(inputFile),
          outputFile(outputFile),
          numberOfThreads(numberOfThreads),
          variantType(variantType)
{
}

double HorizontalPartitioning::applyHorizontalPartitioningConvolution()
{
    if (inputFile.empty())
    {
        std::cerr << "Please provide an input file" << std::endl;
        return -1;
    }

    FileManager fileManager(inputFile, outputFile);
    fileManager.readInput(convolutionItems);

    int linesPerThread = convolutionItems.n / numberOfThreads;
    int rest = convolutionItems.n % numberOfThreads;
    std::vector<std::thread> threads;

    int start = 0;
    int end = linesPerThread;

    std::unique_ptr<std::barrier<>> barrier = nullptr;
    std::vector<std::unique_ptr<std::atomic<bool>>> flags;

    // Initialize barrier or flags as per variant type
    if (variantType == VariantType::VARIANTA_1B || variantType == VariantType::VARIANTA_2B) {
        barrier = std::make_unique<std::barrier<>>(numberOfThreads);
    } else if (variantType == VariantType::VARIANTA_1F || variantType == VariantType::VARIANTA_2F) {
        flags.resize(numberOfThreads);
        for (auto &flag : flags) {
            flag = std::make_unique<std::atomic<bool>>(false); // Initialize each flag to false
        }
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    // Create and start each thread, passing the appropriate barrier or flags
    for (int i = 0; i < numberOfThreads; i++)
    {
        if (rest > 0)
        {
            end++;
            rest--;
        }

        threads.emplace_back(&MyThread::run,
                             MyThread(convolutionItems, start, end, 0, convolutionItems.m,
                                      barrier.get(), flags, variantType, i));

        start = end;
        end = start + linesPerThread;
    }

    // Join all threads
    for (auto &t : threads) {
        t.join();
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();

    fileManager.writeOutput(convolutionItems);

    assert(VerifyResult::verify(inputFile, outputFile));
    return duration;
}
