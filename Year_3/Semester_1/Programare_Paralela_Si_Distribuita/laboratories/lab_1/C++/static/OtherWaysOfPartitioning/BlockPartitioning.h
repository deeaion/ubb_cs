//
// Created by Deea on 10/20/2024.
//

#ifndef BLOCKPARTITIONING_H
#define BLOCKPARTITIONING_H

#include "../Utils/ConvolutionItems.h"
#include <thread>
#include <string>
#include <vector>

class BlockPartitioning {
public:
    BlockPartitioning(const std::string& inputFile,
                      const std::string& outputFile, int numberOfThreads);
    double applyBlockPartitioningConvolution();

private:
    ConvolutionItems convolutionItems;
    std::string inputFile;
    std::string outputFile;
    int numberOfThreads;
};

#endif // BLOCKPARTITIONING_H
