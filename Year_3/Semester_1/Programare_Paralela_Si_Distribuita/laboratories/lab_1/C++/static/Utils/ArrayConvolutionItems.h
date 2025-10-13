//
// Created by Deea on 10/22/2024.
//

#ifndef SOLUTION_ARRAYCONVOLUTIONITEMS_H
#define SOLUTION_ARRAYCONVOLUTIONITEMS_H

#include "../constants.h"
class ArrayConvolutionItems
{
public:
    int matrix[MAX_N * MAX_M];
    int kernel[MAX_K][MAX_K];
    int result[MAX_N][MAX_M];
    int n, m, k;

    ArrayConvolutionItems(int n, int m, int k);
    ArrayConvolutionItems() = default;
    ArrayConvolutionItems(int n, int m, int k, int matrix[MAX_N * MAX_M], int kernel[MAX_K][MAX_K], int result[MAX_N][MAX_M]);
};

#endif // SOLUTION_ARRAYCONVOLUTIONITEMS_H
