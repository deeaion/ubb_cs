//
// Created by Deea on 10/20/2024.
//

#include "ConvolutionItems.h"

ConvolutionItems::ConvolutionItems(int n, int m, int k) : n(n), m(m), k(k) {
    // Inițializarea fiecărui rând din matrix, kernel și result
    if (n > 0 && m > 0) {
        matrix = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
        result = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    } else {
        std::cerr << "Eroare: dimensiunile matricii sunt invalide (n sau m <= 0)" << std::endl;
    }

    if (k > 0) {
        kernel = std::vector<std::vector<int>>(k, std::vector<int>(k, 0));
    } else {
        std::cerr << "Eroare: dimensiunea kernel-ului este invalidă (k <= 0)" << std::endl;
    }
}