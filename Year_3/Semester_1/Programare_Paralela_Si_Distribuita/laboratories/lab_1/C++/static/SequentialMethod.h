#ifndef SEQUENTIALMETHOD_H
#define SEQUENTIALMETHOD_H

#include "Utils/ConvolutionItems.h"
#include <string>

class SequentialMethod
{
public:
    SequentialMethod(const std::string &inputFile, const std::string &outputFile);
    long applySequentialConvolution();
    void getResult(int[MAX_N][MAX_M]); // Returnăm un pointer dublu către matrice

private:
    ConvolutionItems items;
    std::string inputFile;
    std::string outputFile;
};

#endif // SEQUENTIALMETHOD_H
