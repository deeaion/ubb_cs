//
// Created by Deea on 10/20/2024.
//

#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include "ConvolutionItems.h"

class MatrixOperations {
public:
    static int convolution(const ConvolutionItems& items, int x, int y, int lineOffset, int columnOffset);

    static void applyConvolution(ConvolutionItems& items, int nStart, int nEnd, int mStart, int mEnd);


    static int convolutionMatrixAsArray(const std::vector<int> & matrix, const std::vector<std::vector<int>> &kernel, int x, int y, int n, int m, int kernelSize);

    static void flattenMatrix(const std::vector<std::vector<int>> &matrix, std::vector<int> & result, int n, int m);

    static bool
    areEqual(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2, int n, int m);
};

#endif // MATRIXOPERATIONS_H
