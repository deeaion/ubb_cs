//
// Created by Deea on 10/20/2024.
//

#include "MyThread.h"

MyThread::MyThread(ConvolutionItems& items, int nStart, int nEnd, int mStart, int mEnd)
        : items(items), nStart(nStart), nEnd(nEnd), mStart(mStart), mEnd(mEnd) {}

void MyThread::run() {
    MatrixOperations::applyConvolution(items, nStart, nEnd, mStart, mEnd);
}
