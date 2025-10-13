//
// Created by Deea on 10/20/2024.
//

#ifndef HORIZONTALPARTITIONING_H
#define HORIZONTALPARTITIONING_H

#include "../Utils/ConvolutionItems.h"
#include <thread>
#include <string>
#include <vector>

class HorizontalPartitioning {
public:

    HorizontalPartitioning(const std::string& inputFile,
                           const std::string& outputFile,
                           int numberOfThreads);
    double applyHorizontalPartitioningConvolution();

private:

    ConvolutionItems convolutionItems;
    std::string inputFile;
    std::string outputFile;
    int numberOfThreads;
};

#endif // HORIZONTALPARTITIONING_H
