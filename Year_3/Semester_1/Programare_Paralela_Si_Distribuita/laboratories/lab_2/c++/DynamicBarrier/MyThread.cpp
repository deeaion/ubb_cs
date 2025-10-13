//
// Created by Deea on 10/20/2024.
//

#include <chrono>
#include <thread>
#include <iostream>
#include "MyThread.h"
#include "Utils/MatrixOperations.h"

MyThread::MyThread(ConvolutionItems &items, int nStart, int nEnd, int mStart, int mEnd,
                   std::barrier<> *barrier, std::vector<std::unique_ptr<std::atomic<bool>>> &flags,
                   VariantType variantType, int threadIndex)
        : items(items), nStart(nStart), nEnd(nEnd), mStart(mStart), mEnd(mEnd),
          barrier(barrier), flags(flags), variantType(variantType), threadIndex(threadIndex) {}

void MyThread::run() {
    // Copy boundary rows for each thread
    std::vector<int> topRow = (nStart > 0) ? std::vector<int>(items.matrix[nStart - 1]) : std::vector<int>();
    std::vector<int> bottomRow = (nEnd < items.n) ? std::vector<int>(items.matrix[nEnd]) : std::vector<int>();

    switch (variantType) {
        case VariantType::VARIANTA_1B:
            handleVariant1B(topRow, bottomRow);
            break;
        case VariantType::VARIANTA_1F:
            handleVariant1F(topRow, bottomRow);
            break;
            // Additional variants would go here...
    }
}

void MyThread::handleVariant1B( std::vector<int> &topRow, const std::vector<int> &bottomRow) {
    barrier->arrive_and_wait(); // Initial synchronization for all threads

    for (int i = nStart; i < nEnd; i++) {
        std::vector<int> currentRow = items.matrix[i]; // Clone the current row

        for (int j = mStart; j < mEnd; j++) {
            bool isLastRow = (i == nEnd - 1);
            items.matrix[i][j] = MatrixOperations::convolutionWithBoundaries(items, i, j, topRow, currentRow, bottomRow, isLastRow);
        }

        // Update topRow to be the currentRow for the next iteration
        if (i < nEnd - 1) {
            topRow = currentRow;
        }
    }

    barrier->arrive_and_wait(); // Final synchronization for all threads
}

void MyThread::handleVariant1F(std::vector<int> &topRow, const std::vector<int> &bottomRow) {
    flags[threadIndex]->store(true); // Set flag to true after copying boundary values

    // Wait until neighboring flags are set
    while (!areNeighborFlagsSet()) {
        std::this_thread::yield();
    }

    for (int i = nStart; i < nEnd; i++) {
        std::vector<int> currentRow = items.matrix[i]; // Clone current row

        for (int j = mStart; j < mEnd; j++) {
            bool isLastRow = (i == nEnd - 1);
            items.matrix[i][j] = MatrixOperations::convolutionWithBoundaries(items, i, j, topRow, currentRow, bottomRow, isLastRow);
        }

        // Update topRow to be the currentRow for the next iteration
        if (i < nEnd - 1) {
            topRow = currentRow;
        }
    }
}

void MyThread::handleVariant2B(std::vector<int> &topRow, const std::vector<int> &bottomRow) {
    std::vector<int> boundaryValuesTop(mEnd - mStart);
    std::vector<int> boundaryValuesBottom(mEnd - mStart);

    if (nStart > 0) {
        for (int j = mStart; j < mEnd; j++) {
            boundaryValuesTop[j - mStart] = MatrixOperations::convolution(items, nStart, j);
        }
    }
    if (nEnd < items.n) {
        for (int j = mStart; j < mEnd; j++) {
            boundaryValuesBottom[j - mStart] = MatrixOperations::convolution(items, nEnd - 1, j);
        }
    }

    for (int i = nStart + 1; i < nEnd - 1; i++) {
        for (int j = mStart; j < mEnd; j++) {
            items.matrix[i][j] = MatrixOperations::convolution(items, i, j);
        }
    }

    barrier->arrive_and_wait(); // Synchronize all threads

    if (nStart > 0) {
        for (int j = mStart; j < mEnd; j++) {
            items.matrix[nStart][j] = boundaryValuesTop[j - mStart];
        }
    }
    if (nEnd < items.n) {
        for (int j = mStart; j < mEnd; j++) {
            items.matrix[nEnd - 1][j] = boundaryValuesBottom[j - mStart];
        }
    }

    barrier->arrive_and_wait(); // Final synchronization
}

void MyThread::handleVariant2F(const std::vector<int> &topRow, const std::vector<int> &bottomRow) {
    std::vector<int> boundaryValuesTop(mEnd - mStart);
    std::vector<int> boundaryValuesBottom(mEnd - mStart);

    if (nStart > 0) {
        for (int j = mStart; j < mEnd; j++) {
            boundaryValuesTop[j - mStart] = MatrixOperations::convolution(items, nStart, j);
        }
    }
    if (nEnd < items.n) {
        for (int j = mStart; j < mEnd; j++) {
            boundaryValuesBottom[j - mStart] = MatrixOperations::convolution(items, nEnd - 1, j);
        }
    }
    flags[threadIndex]->store(true);

    for (int i = nStart + 1; i < nEnd - 1; i++) {
        for (int j = mStart; j < mEnd; j++) {
            items.matrix[i][j] = MatrixOperations::convolution(items, i, j);
        }
    }

    while (!areNeighborFlagsSet()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    if (nStart > 0) {
        for (int j = mStart; j < mEnd; j++) {
            items.matrix[nStart][j] = boundaryValuesTop[j - mStart];
        }
    }
    if (nEnd < items.n) {
        for (int j = mStart; j < mEnd; j++) {
            items.matrix[nEnd - 1][j] = boundaryValuesBottom[j - mStart];
        }
    }
}

bool MyThread::areNeighborFlagsSet() {
    if (threadIndex > 0 && !flags[threadIndex - 1]->load()) {
        return false;
    }
    if (threadIndex < flags.size() - 1 && !flags[threadIndex + 1]->load()) {
        return false;
    }
    return true;
}


