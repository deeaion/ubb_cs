////
//// Created by Deea on 10/20/2024.
////
//
//#include "VerticalPartitioning.h"
//#include "../Utils/FileManager.h"
//#include "../Utils/MatrixOperations.h"
//#include "../MyThread.h"
//#include "../Utils/VerifyResult.h"
//#include <chrono>
//#include <iostream>
//#include <cassert>
//
//VerticalPartitioning::VerticalPartitioning(const std::string &inputFile, const std::string &outputFile, int numberOfThreads)
//    : inputFile(inputFile), outputFile(outputFile), numberOfThreads(numberOfThreads)
//{
//}
//
//double VerticalPartitioning::applyVerticalPartitioningConvolution()
//{
//    if (inputFile.empty())
//    {
//        std::cerr << "Please provide an input file" << std::endl;
//        return -1;
//    }
//
//    // citesc
//    FileManager fileManager(inputFile, outputFile);
//    fileManager.readInput(convolutionItems);
//
//    // impart
//    int columnsPerThread = convolutionItems.m / numberOfThreads;
//    int rest = convolutionItems.m % numberOfThreads;
//
//    std::vector<std::thread> threads;
//
//    int start = 0;
//    int end = columnsPerThread;
//
//    // timp
//    auto startTime = std::chrono::high_resolution_clock::now();
//
//    for (int i = 0; i < numberOfThreads; i++)
//    {
//        if (rest > 0)
//        {
//            end++;
//            rest--;
//        }
//
//        // creez + pornesc thread
//        threads.emplace_back(&MyThread::run, MyThread(convolutionItems, 0, convolutionItems.n, start, end));
//
//        start = end;
//        end = start + columnsPerThread;
//    }
//
//    // wait
//    for (auto &t : threads)
//    {
//        t.join();
//    }
//
//    auto endTime = std::chrono::high_resolution_clock::now();
//
//    // timp
//    double duration = std::chrono::duration<double, std::milli>(endTime - startTime).count();
//    // rez
//    fileManager.writeOutput(convolutionItems);
//    // verificare rezultat
//    assert(VerifyResult::verify(inputFile, outputFile));
//
//    return duration;
//}
