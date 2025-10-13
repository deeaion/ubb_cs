#ifndef SOLUTION_ARRAYCONVOLUTIONITEMS_H
#define SOLUTION_ARRAYCONVOLUTIONITEMS_H

#include <vector>

class ArrayConvolutionItems
{
public:
    std::vector<int> matrix;
    std::vector<std::vector<int>> kernel;
    std::vector<std::vector<int>> result;
    int n, m, k;

    ArrayConvolutionItems(int n, int m, int k);

    ArrayConvolutionItems() = default;

    ArrayConvolutionItems(int n, int m, int k, const std::vector<int> &matrix, const std::vector<std::vector<int>> &kernel, const std::vector<std::vector<int>> &result)
        : n(n), m(m), k(k), matrix(matrix), kernel(kernel), result(result) {}
};

#endif // SOLUTION_ARRAYCONVOLUTIONITEMS_H
