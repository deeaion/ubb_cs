#include "MatrixOperations.h"
#include <algorithm>
#include <iostream>
#include <vector>

// Standard convolution for a given (x, y) position using the full kernel
int MatrixOperations::convolution(const ConvolutionItems &items, int x, int y) {
    int sum = 0;
    int kernelSize = items.k;
    int halfK = kernelSize / 2;

    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            int nx = x - halfK + i;
            int ny = y - halfK + j;
            nx = std::max(0, std::min(nx, items.n - 1));
            ny = std::max(0, std::min(ny, items.m - 1));
            sum += items.matrix[nx][ny] * items.kernel[i][j];
        }
    }
    return sum;
}

// Convolution for boundary rows (top or bottom row), using a specific row vector for edge handling
int MatrixOperations::convolutionWithRow(const ConvolutionItems &items, int x, int y, const std::vector<int> &row, bool isTopRow) {
    int sum = 0;
    int kernelSize = items.k;
    int halfK = kernelSize / 2;

    for (int i = 0; i < kernelSize; i++) {
        for (int j = 0; j < kernelSize; j++) {
            int nx = x - halfK + i;
            int ny = y - halfK + j;

            // Handle edge cases based on the row boundaries
            if (nx < 0 || nx >= items.n) {
                // Use the boundary row vector if outside the matrix on the vertical axis
                sum += row[std::max(0,std::min(ny,items.m-1))] * items.kernel[i][j];
            } else {
                // Otherwise, use the matrix values
                nx = std::max(0, std::min(nx, items.n - 1));
                ny = std::max(0, std::min(ny, items.m - 1));
                sum += items.matrix[nx][ny] * items.kernel[i][j];
            }
        }
    }

    return sum;
}
int MatrixOperations::convolutionWithBoundaries(const ConvolutionItems &items, int x, int y,
                                                const std::vector<int> &tRow, const std::vector<int> &cRow,
                                                const std::vector<int> &bRow, bool isLastRow) {
    int sum = 0;
    auto &kernel = items.kernel;

    // Top, Left, Right, and Center values
    int topValue = tRow.empty() ? cRow[y] : tRow[y];
    int topLeft = tRow.empty() ? (y > 0 ? cRow[y - 1] : cRow[y]) : (y > 0 ? tRow[y - 1] : tRow[y]);
    int topRight = tRow.empty() ? (y < items.m - 1 ? cRow[y + 1] : cRow[y]) : (y < items.m - 1 ? tRow[y + 1] : tRow[y]);
    int leftValue = (y > 0) ? cRow[y - 1] : cRow[y];
    int rightValue = (y < items.m - 1) ? cRow[y + 1] : cRow[y];

    // Bottom values
    int bottomValue, bottomLeft, bottomRight;
    if (isLastRow) {
        if (!bRow.empty()) {
            bottomValue = bRow[y];
            bottomLeft = (y > 0) ? bRow[y - 1] : bRow[y];
            bottomRight = (y < items.m - 1) ? bRow[y + 1] : bRow[y];
        } else {
            bottomValue = cRow[y];
            bottomLeft = (y > 0) ? cRow[y - 1] : cRow[y];
            bottomRight = (y < items.m - 1) ? cRow[y + 1] : cRow[y];
        }
    } else {
        bottomValue = items.matrix[x + 1][y];
        bottomLeft = (y > 0) ? items.matrix[x + 1][y - 1] : items.matrix[x + 1][y];
        bottomRight = (y < items.m - 1) ? items.matrix[x + 1][y + 1] : items.matrix[x + 1][y];
    }

    // Convolution calculation
    sum += topLeft * kernel[0][0];
    sum += topValue * kernel[0][1];
    sum += topRight * kernel[0][2];
    sum += leftValue * kernel[1][0];
    sum += cRow[y] * kernel[1][1];
    sum += rightValue * kernel[1][2];
    sum += bottomLeft * kernel[2][0];
    sum += bottomValue * kernel[2][1];
    sum += bottomRight * kernel[2][2];

    // Debugging output to verify calculation
    std::cout << "For position (" << x << "," << y << "): "
              << "topLeft=" << topLeft << ", top=" << topValue << ", topRight=" << topRight << ", "
              << "left=" << leftValue << ", center=" << cRow[y] << ", right=" << rightValue << ", "
              << "bottomLeft=" << bottomLeft << ", bottom=" << bottomValue << ", bottomRight=" << bottomRight
              << " => Calculated Sum: " << sum << std::endl;

    return sum;
}
