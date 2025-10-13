package org.convolutionMatrix;

import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.MatrixOperations;

public class MyThread implements Runnable{
    public ConvolutionItems items;
    public int nStart;
    public int nEnd;
    public int mStart;
    public int mEnd;

    public MyThread(ConvolutionItems items, int nStart, int nEnd, int mStart, int mEnd) {
        this.items = items;
        this.nStart = nStart;
        this.nEnd = nEnd;
        this.mStart = mStart;
        this.mEnd = mEnd;
    }
    @Override
    public void run() {
        MatrixOperations.applyConvolution(items, nStart, nEnd, mStart, mEnd);
    }
}
