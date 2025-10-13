#include "ArrayConvolutionItems.h"
#include <iostream>

ArrayConvolutionItems::ArrayConvolutionItems(int n, int m, int k) : n(n), m(m), k(k)
{
    // Initialize matrix and result if valid dimensions
    if (n > 0 && m > 0)
    {
        matrix = std::vector<int>(n * m, 0);
        result = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    }
    else
    {
        std::cerr << "Error: invalid matrix dimensions (n or m <= 0)" << std::endl;
    }

    // Initialize kernel if valid dimension
    if (k > 0)
    {
        kernel = std::vector<std::vector<int>>(k, std::vector<int>(k, 0));
    }
    else
    {
        std::cerr << "Error: invalid kernel size (k <= 0)" << std::endl;
    }
}
