//
// Created by Deea on 10/20/2024.
//

#ifndef CONVOLUTIONITEMS_H
#define CONVOLUTIONITEMS_H
#include <vector>
class ConvolutionItems {
public:
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> kernel;
    int n, m, k;

    ConvolutionItems(int n, int m, int k);
    ConvolutionItems() = default;
    ConvolutionItems(int n,int m,int k,
                     const std::vector<std::vector<int>>& matrix,
                     const std::vector<std::vector<int>>& kernel);
};

#endif // CONVOLUTIONITEMS_H
