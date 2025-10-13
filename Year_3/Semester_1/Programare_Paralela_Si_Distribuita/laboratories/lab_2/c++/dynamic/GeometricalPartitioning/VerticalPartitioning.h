//
// Created by Deea on 10/20/2024.
//

#ifndef VERTICALPARTITIONING_H
#define VERTICALPARTITIONING_H

#include "../Utils/ConvolutionItems.h"
#include <thread>
#include <string>
#include <vector>

class VerticalPartitioning {
public:
    VerticalPartitioning(const std::string& inputFile, const std::string& outputFile, int numberOfThreads);
    double applyVerticalPartitioningConvolution();

private:
    ConvolutionItems convolutionItems;
    std::string inputFile;
    std::string outputFile;
    int numberOfThreads;
};

#endif // VERTICALPARTITIONING_H
