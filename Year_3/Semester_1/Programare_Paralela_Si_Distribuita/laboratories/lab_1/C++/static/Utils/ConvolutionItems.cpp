//
// Created by Deea on 10/20/2024.
//

#include "ConvolutionItems.h"

ConvolutionItems::ConvolutionItems(int n, int m, int k)
{
    this->n = n;
    this->m = m;
    this->k = k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = 0;
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            kernel[i][j] = 0;
        }
    }
}
ConvolutionItems::ConvolutionItems(int n, int m, int k,
                                   int matrix[MAX_N][MAX_M], int kernel[MAX_K][MAX_K],
                                   int result[MAX_N][MAX_M])
{
    this->n = n;
    this->m = m;
    this->k = k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            this->matrix[i][j] = matrix[i][j];
            this->result[i][j] = result[i][j];
        }
    }

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            this->kernel[i][j] = kernel[i][j];
        }
    }
}
