//
// Created by Deea on 10/20/2024.
//

#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include "ConvolutionItems.h"

class MatrixOperations
{
public:
    static int convolution(const ConvolutionItems &items, int x, int y, int lineOffset, int columnOffset);

    static void applyConvolution(ConvolutionItems &items, int nStart, int nEnd, int mStart, int mEnd);

    static void flattenMatrix(const int matrix[MAX_N][MAX_M], int result[], int n, int m);

    static int convolutionMatrixAsArray(const int matrix[], int kernel[MAX_K][MAX_K], int x, int y, int n, int m, int kernelSize);

    static bool areEqual(const int matrix1[MAX_N][MAX_M], const int matrix2[MAX_N][MAX_M], int n, int m);
};

#endif // MATRIXOPERATIONS_H
