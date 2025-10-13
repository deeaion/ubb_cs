package org.convolutionMatrix.Utils;

public class ArrayConvolutionItems {
    public int[] matrix;
    public int[][] kernel;
    public int[][] result;
    public int m;
    public int n;
    public int k;

    public ArrayConvolutionItems(int[] matrix, int[][] kernel, int[][] result, int n, int m, int k) {
        this.matrix = matrix;
        this.kernel = kernel;
        this.result = result;
        this.m = m;
        this.n = n;
        this.k = k;
    }

}
