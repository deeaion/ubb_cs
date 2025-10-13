#ifndef SEQUENTIALMETHOD_H
#define SEQUENTIALMETHOD_H

#include "Utils/ConvolutionItems.h"
#include <string>

class SequentialMethod {
public:
    SequentialMethod(const std::string &inputFile, const std::string &outputFile);

    // Applies the convolution sequentially and returns the time in milliseconds
    double applySequentialConvolution();

    // Returns the result matrix for external access
    void getResult(std::vector<std::vector<int>> &result);

private:
    ConvolutionItems items;
    std::string inputFile;
    std::string outputFile;

    // Applies convolution in-place on items.matrix
    void applyInPlaceConvolution();
};

#endif // SEQUENTIALMETHOD_H
