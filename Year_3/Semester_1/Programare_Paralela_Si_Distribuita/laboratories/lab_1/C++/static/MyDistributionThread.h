#ifndef MYDISTRIBUTIONTHREAD_H
#define MYDISTRIBUTIONTHREAD_H

#include "Utils/ArrayConvolutionItems.h"
#include <thread>

class MyDistributionThread
{
public:
    MyDistributionThread(ArrayConvolutionItems &items, int step, int numThreads, int start, int end, int id);
    void run();

private:
    int *matrix;
    ArrayConvolutionItems &items;
    int step;
    int numThreads;
    int start;
    int end;
    int id;
};

#endif // MYDISTRIBUTIONTHREAD_H
