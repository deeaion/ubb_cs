//
// Created by Deea on 10/20/2024.
//

#ifndef DELTAPARTITIONING_H
#define DELTAPARTITIONING_H

#include "../Utils/ConvolutionItems.h"
#include <thread>
#include <string>
#include <vector>
#include "../Utils/ArrayConvolutionItems.h"

class DeltaPartitioning
{
public:
    DeltaPartitioning(const std::string &inputFile,
                      const std::string &outputFile,
                      int numberOfThreads,
                      const std::string &distributionType);
    double applyDeltaPartitioningConvolution();
    int *matrix;

private:
    void distributeCyclic(std::vector<std::thread> &threads);
    void distributeLinear(std::vector<std::thread> &threads);

    ArrayConvolutionItems convolutionItems;
    std::string inputFile;
    std::string outputFile;
    int numberOfThreads;

    std::string distributionType;
};

#endif // DELTAPARTITIONING_H
