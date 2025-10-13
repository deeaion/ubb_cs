#include "MyDistributionThread.h"
#include "Utils/MatrixOperations.h"
#include <iostream>

// Constructor
MyDistributionThread::MyDistributionThread(ArrayConvolutionItems &items, int step, int numThreads, int start, int end, int id)
    : matrix(matrix), items(items), step(step), numThreads(numThreads), start(start), end(end), id(id) {}

void MyDistributionThread::run()
{
    for (int i = start; i < end; i += step)
    {
        int x = i / items.m;
        int y = i % items.m;
        if (i < 0 || i >= items.n * items.m)
        {
            continue;
        }

        items.result[x][y] = MatrixOperations::convolutionMatrixAsArray(items.matrix, items.kernel, x, y, items.n, items.m, items.k);
    }
}
