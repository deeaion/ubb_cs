#ifndef SEQUENTIALMETHOD_H
#define SEQUENTIALMETHOD_H

#include "Utils/ConvolutionItems.h"
#include <string>

class SequentialMethod {
public:
    SequentialMethod(const std::string& inputFile, const std::string& outputFile);
    double applySequentialConvolution();
    void getResult(std::vector<std::vector<int>> & result);

private:
    ConvolutionItems items;
    std::string inputFile;
    std::string outputFile;

};

#endif // SEQUENTIALMETHOD_H
