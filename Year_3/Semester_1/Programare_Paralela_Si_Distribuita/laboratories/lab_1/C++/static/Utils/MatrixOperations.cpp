//
// Created by Deea on 10/20/2024.
//

#include "MatrixOperations.h"
#include <iostream>

int MatrixOperations::convolution(const ConvolutionItems &items, int x, int y, int lineOffset, int columnOffset)
{
    int sum = 0;

    for (int i = 0; i < items.k; ++i)
    {
        for (int j = 0; j < items.k; ++j)
        {
            int nx = x - lineOffset + i;
            int ny = y - columnOffset + j;

            if (nx < 0)
                nx = 0;
            else if (nx >= items.n)
                nx = items.n - 1;

            if (ny < 0)
                ny = 0;
            else if (ny >= items.m)
                ny = items.m - 1;

            sum += items.matrix[nx][ny] * items.kernel[i][j];
        }
    }

    return sum;
}

void MatrixOperations::applyConvolution(ConvolutionItems &items, int nStart, int nEnd, int mStart, int mEnd)
{
    int lineOffset = (items.k - 1) / 2;
    int columnOffset = (items.k - 1) / 2;

    for (int i = nStart; i < nEnd; ++i)
    {
        for (int j = mStart; j < mEnd; ++j)
        {
            items.result[i][j] = convolution(items, i, j, lineOffset, columnOffset);
        }
    }
}

void MatrixOperations::flattenMatrix(const int matrix[MAX_N][MAX_M], int result[MAX_N * MAX_M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i * m + j] = matrix[i][j];
        }
    }
}

int MatrixOperations::convolutionMatrixAsArray(const int matrix[],
                                               int kernel[MAX_K][MAX_K],
                                               int x, int y,
                                               int n, int m,
                                               int kernelSize)
{
    int sum = 0;
    int lineOffset = (kernelSize - 1) / 2;
    int columnOffset = (kernelSize - 1) / 2;

    for (int i = 0; i < kernelSize; ++i)
    {
        for (int j = 0; j < kernelSize; ++j)
        {
            int nx = x - lineOffset + i;
            int ny = y - columnOffset + j;

            // Gestionarea padding-ului
            if (nx < 0)
                nx = 0;
            else if (nx >= n)
                nx = n - 1;

            if (ny < 0)
                ny = 0;
            else if (ny >= m)
                ny = m - 1;

            int index = nx * m + ny;

            // Verificare index
            if (index < 0 || index >= n * m)
            {
                std::cerr << "Eroare la calculul indexului. nx: "
                          << nx << ", ny: " << ny << ", index: " << index << std::endl;
                throw std::out_of_range("Index " + std::to_string(index) +
                                        " out of bounds for flattened matrix of length " + std::to_string(n * m));
            }

            sum += matrix[index] * kernel[i][j];
        }
    }

    return sum;
}

bool MatrixOperations::areEqual(const int matrix1[MAX_N][MAX_M], const int matrix2[MAX_N][MAX_M], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}