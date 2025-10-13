//
// Created by Deea on 10/22/2024.
//

#include "ArrayConvolutionItems.h"

ArrayConvolutionItems::ArrayConvolutionItems(int n, int m, int k)
{
    this->n = n;
    this->m = m;
    this->k = k;

    for (int i = 0; i < n * m; i++)
    {

        matrix[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
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
ArrayConvolutionItems::ArrayConvolutionItems(int n, int m, int k,
                                             int matrix[MAX_N * MAX_M], int kernel[MAX_K][MAX_K],
                                             int result[MAX_N][MAX_M])
{
    this->n = n;
    this->m = m;
    this->k = k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            this->matrix[i * m + j] = matrix[i * m + j];
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
