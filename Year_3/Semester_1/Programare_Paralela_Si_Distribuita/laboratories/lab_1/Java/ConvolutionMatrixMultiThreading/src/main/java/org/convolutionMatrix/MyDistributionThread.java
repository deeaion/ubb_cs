package org.convolutionMatrix;

import org.convolutionMatrix.Utils.ArrayConvolutionItems;
import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.MatrixOperations;

import java.util.Arrays;

public class MyDistributionThread implements Runnable{
    private int  id;
    public int step;
    public int numThreads;
    public int start;
    public int end;
    public ArrayConvolutionItems convolutionItems;
    public MyDistributionThread(ArrayConvolutionItems items, int step, int numThreads,int start,int end,int id)
    {
        this.convolutionItems=items;
        this.step=step;
        this.numThreads=numThreads;
        this.start=start;
        this.end=end;
        this.id=id;
    }

    @Override
    public void run() {
        for (int i = start; i < convolutionItems.matrix.length; i += step) {
            int x = i / convolutionItems.m;
            int y = i % convolutionItems.m;

            if (i < 0 || i >= convolutionItems.matrix.length) {
                continue;
            }

            convolutionItems.result[x][y] = MatrixOperations.convolutionMatrixAsArray(convolutionItems.matrix, convolutionItems.kernel, x, y, convolutionItems.n, convolutionItems.m);
        }
    }

}
