//
// Created by Deea on 10/20/2024.
//

#ifndef SOLUTION_MYTHREAD_H
#define SOLUTION_MYTHREAD_H



#include "Utils/ConvolutionItems.h"
#include "Utils/MatrixOperations.h"
#include <thread>

class MyThread {
public:
    MyThread(ConvolutionItems& items, int nStart, int nEnd, int mStart, int mEnd);
    void run();

private:
    ConvolutionItems& items;
    int nStart;
    int nEnd;
    int mStart;
    int mEnd;
};

#endif // MYTHREAD_H
