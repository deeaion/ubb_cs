#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include "ConvolutionItems.h"
#include <vector>

class MatrixOperations {
public:
    // Standard convolution operation for a given (x, y) position using the full kernel
    static int convolution(const ConvolutionItems &items, int x, int y);

    // Convolution for boundary rows using a specific row vector for edge handling
    static int convolutionWithRow(const ConvolutionItems &items, int x, int y, const std::vector<int> &row, bool isTopRow);

    // Applies convolution over a specified range in the matrix
    static void applyConvolution(ConvolutionItems &items, int nStart, int nEnd, int mStart, int mEnd);

    static int convolutionWithBoundaries(const ConvolutionItems &items, int x, int y, const std::vector<int> &tRow,
                                         const std::vector<int> &cRow, const std::vector<int> &bRow, bool isLastRow);
};

#endif // MATRIXOPERATIONS_H
