//
// Created by Deea on 10/20/2024.
//

#ifndef CONVOLUTIONITEMS_H
#define CONVOLUTIONITEMS_H

#include "../constants.h"
class ConvolutionItems
{
public:
    int matrix[MAX_N][MAX_M];
    int kernel[MAX_K][MAX_K];
    int result[MAX_N][MAX_M];
    int n, m, k;

    ConvolutionItems(int n, int m, int k);
    ConvolutionItems() = default;
    ConvolutionItems(int n, int m, int k, int matrix[MAX_N][MAX_M], int kernel[MAX_K][MAX_K], int result[MAX_N][MAX_M]);
};

#endif // CONVOLUTIONITEMS_H
