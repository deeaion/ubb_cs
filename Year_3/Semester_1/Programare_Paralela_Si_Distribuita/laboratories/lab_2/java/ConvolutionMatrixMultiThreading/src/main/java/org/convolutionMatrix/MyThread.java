package org.convolutionMatrix;

import org.convolutionMatrix.GeometricalPartitioning.VariantType;
import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.MatrixOperations;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class MyThread implements Runnable {
    private ConvolutionItems items;
    private int nStart;
    private int nEnd;
    private int mStart;
    private int mEnd;
    private CyclicBarrier cyclicBarrier; // Used in Varianta_1B and Varianta_2B
    private VariantType variantType;
    private boolean[] flags; // Used in Varianta_1F and Varianta_2F
    private int threadIndex;

    public MyThread(ConvolutionItems items, int nStart, int nEnd, int mStart, int mEnd, CyclicBarrier cyclicBarrier, VariantType variantType, boolean[] flags, int threadIndex) {
        this.items = items;
        this.nStart = nStart;
        this.nEnd = nEnd;
        this.mStart = mStart;
        this.mEnd = mEnd;
        this.cyclicBarrier = cyclicBarrier;
        this.variantType = variantType;
        this.flags = flags;
        this.threadIndex = threadIndex;
    }

    @Override
    public void run() {
        try {
            // Copy boundary values into auxiliary vectors
            int[] topRow = null;
            int[] bottomRow = null;
            //debug

            switch (variantType) {
                case VARIANTA_1B:
                    handleVariant1B(topRow, bottomRow);
                    break;
                case VARIANTA_1F:
                    handleVariant1F(topRow, bottomRow);
                    break;
                case VARIANTA_2B:
                    handleVariant2B(topRow, bottomRow);
                    break;
                case VARIANTA_2F:
                    handleVariant2F(topRow, bottomRow);
                    break;
            }

        } catch (InterruptedException | BrokenBarrierException e) {
            e.printStackTrace();
        }
    }

    private void handleVariant1B(int[] topRow, int[] bottomRow) throws BrokenBarrierException, InterruptedException {
        topRow= (nStart > 0) ? items.matrix[nStart - 1].clone() : null;
        bottomRow= (nEnd < items.n) ? items.matrix[nEnd].clone() : null;
        cyclicBarrier.await();

        int[] currentRow;
        for (int i = nStart; i < nEnd; i++) {
            currentRow = items.matrix[i].clone();

            for (int j = mStart; j < mEnd; j++) {
                items.matrix[i][j] = MatrixOperations.convolutionWithBoundaries(items, i, j, topRow, currentRow, bottomRow, i == nEnd - 1);
            }
            if (i < nEnd - 1) {
                topRow = currentRow;
            }
        }

        cyclicBarrier.await();
    }




    private void handleVariant1F(int[] topRow, int[] bottomRow) {
        topRow= (nStart > 0) ? items.matrix[nStart - 1].clone() : null;
        bottomRow= (nEnd < items.n) ? items.matrix[nEnd].clone() : null;
        flags[threadIndex] = true;

        while (!areNeighborFlagsSet()) {
            Thread.yield();
        }

        int[] currentRow;
        for (int i = nStart; i < nEnd; i++) {
            currentRow = items.matrix[i].clone();

            for (int j = mStart; j < mEnd; j++) {
                items.matrix[i][j] = MatrixOperations.convolutionWithBoundaries(items, i, j, topRow, currentRow, bottomRow, i == nEnd - 1);
            }

            if (i < nEnd - 1) {
                topRow = currentRow;
            }
        }
    }


    private void handleVariant2B(int[] topRow, int[] bottomRow) throws InterruptedException, BrokenBarrierException {
        topRow= (nStart > 0) ? items.matrix[nStart].clone() : null;
        bottomRow= (nEnd < items.n) ? items.matrix[nEnd].clone() : null;
        System.out.println("topRow: " + Arrays.toString(topRow) + threadIndex);
        int startForRest = (nStart>0) ? nStart+1 : nStart;
        int endForRest = (nEnd<items.n) ? nEnd-1 : nEnd;
        if(nStart>0 && topRow!=null)
        {
            for (int j=mStart;j<mEnd;j++)
            {
                topRow[j]=MatrixOperations.convolution(items,nStart,j);
            }
        }
        System.out.println("topRow: " + Arrays.toString(topRow) + threadIndex);
        if (nEnd < items.n&& bottomRow!=null) {
            for (int j = mStart; j < mEnd; j++) {
                bottomRow[j] = MatrixOperations.convolution(items, nEnd, j);
            }
        }

        System.out.println("bottomRow: " + Arrays.toString(bottomRow) + threadIndex);

        int[] previousRow = new int[mEnd - mStart];
        //prev row
        for (int j = mStart; j < mEnd; j++) {
            previousRow[startForRest]=MatrixOperations.convolution(items,startForRest,j);
        }
        startForRest++;
        int[] currentRow;

        for (int i = startForRest; i < nEnd - 1; i++) {
            currentRow = items.matrix[i].clone();
            for (int j = mStart; j < mEnd; j++) {
                currentRow[j] = MatrixOperations.convolution(items, i, j);
            }

            if(i-1>=0)
            {
                for (int j = mStart; j < mEnd; j++) {
                    items.matrix[i-1][j] = previousRow[j - mStart];
                }

            for (int j = mStart; j < mEnd; j++) {
                previousRow[j] = currentRow[j];
            }
            //copiez inapoi in matrice prev

            System.out.println("currentRow: " + Arrays.toString(currentRow) + threadIndex);
        }}

        cyclicBarrier.await();

        if (nStart > 0) {
            for (int j = mStart; j < mEnd; j++) {
                items.matrix[nStart][j] = topRow[j - mStart];
            }
        }
        if (nEnd < items.n) {
            for (int j = mStart; j < mEnd; j++) {
                items.matrix[nEnd - 1][j] = bottomRow[j - mStart];
            }
        }

        cyclicBarrier.await();
    }



        private void handleVariant2F(int[] topRow, int[] bottomRow) throws InterruptedException, BrokenBarrierException {
            topRow = (nStart > 0) ? items.matrix[nStart - 1].clone() : null;
            bottomRow = (nEnd < items.n) ? items.matrix[nEnd].clone() : null;
            flags[threadIndex] = true;

            while (!areNeighborFlagsSet()) {
                Thread.yield();
            }

            int[] currentRow;
            for (int i = nStart; i < nEnd; i++) {
                currentRow = items.matrix[i].clone();

                for (int j = mStart; j < mEnd; j++) {
                    items.matrix[i][j] = MatrixOperations.convolutionWithBoundaries(items, i, j, topRow, currentRow, bottomRow, i == nEnd - 1);
                }

                if (i < nEnd - 1) {
                    topRow = currentRow;
                }
            }
        }

    private boolean areNeighborFlagsSet() {
        if (threadIndex > 0 && !flags[threadIndex - 1]) {
            return false;
        }
        if (threadIndex < flags.length - 1 && !flags[threadIndex + 1]) {
            return false;
        }
        return true;
    }
}
