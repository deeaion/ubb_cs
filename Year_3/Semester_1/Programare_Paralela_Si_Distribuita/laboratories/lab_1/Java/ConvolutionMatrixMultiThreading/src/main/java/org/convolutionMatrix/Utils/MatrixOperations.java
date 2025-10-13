package org.convolutionMatrix.Utils;

import java.lang.reflect.Array;
import java.util.Arrays;

public class MatrixOperations {
    // the atomic operation of convolution
    public static int convolution(ConvolutionItems convolutionItems, int x, int y) {
        int sum = 0;

        int n = convolutionItems.n;
        int m = convolutionItems.m;

        int[][] c = convolutionItems.kernel;
        int kernelSize = convolutionItems.k;

        int halfK = kernelSize / 2;

        //matricea
        int[][] f = convolutionItems.matrix;

        //  go through the kernel
        for (int i = 0; i < kernelSize; i++) {
            for (int j = 0; j < kernelSize; j++) {
                // poz vecin
                int nx = x - halfK + i;
                int ny = y - halfK + j;

                // verificam marginile
                if (nx < 0) {
                    nx = 0; // altfel e egal cu marginea de langa de sus colt stanga
                } else if (nx >= n) {
                    nx = n - 1; // daca nu cu cea de jos
                }

                if (ny < 0) {
                    ny = 0; // luam marginea din stanga
                } else if (ny >= m) {
                    ny = m - 1; // luam marginea din dreapta
                }

                // facem produsul
                sum += f[nx][ny] * c[i][j];
            }
        }

        return sum;
    }


    public static int[] flattenMatrix(int [][] matrix,int n,int m)
    {
        int [] result=new int[n*m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                result[i*m+j]=matrix[i][j];
            }
        }
        return result;
    }
    public static int convolutionMatrixAsArray(int[] matrix, int[][] kernel, int x, int y, int n, int m) {
        int sum = 0;
        int kernelSize = kernel.length;
        int halfK = kernelSize / 2;

        // iterare
        for (int i = 0; i < kernelSize; i++) {
            for (int j = 0; j < kernelSize; j++) {
                // Coordonate kernel
                int nx = x - halfK + i;
                int ny = y - halfK + j;

                // Verificare margini
                if (nx < 0) nx = 0;
                else if (nx >= n) nx = n - 1;

                if (ny < 0) ny = 0;
                else if (ny >= m) ny = m - 1;

                // Calcul index
                int index = nx * m + ny;

                // Verificare index
                if (index < 0 || index >= n * m) {
                    System.out.println("Eroare la calculul indexului. nx: " + nx + ", ny: " + ny + ", index: " + index);
                    throw new ArrayIndexOutOfBoundsException("Index " + index + " out of bounds for flattened matrix of length " + (n * m));
                }

                sum += matrix[index] * kernel[i][j];
            }
        }
        return sum;
    }



    public static boolean areEqual(int [][] matrix1,int [][] matrix2,int n,int m,int N,int M)
    {
        if(m!=M || n!=N)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix1[i][j]!=matrix2[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    public static void applyConvolution(ConvolutionItems convolutionItems,
                                        int nStart, int nEnd, int mStart, int mEnd) {

        for (int i = nStart; i < nEnd; i++) {
            for (int j = mStart; j < mEnd; j++) {
                convolutionItems.result[i][j] = convolution(convolutionItems, i, j);
            }
        }
    }


}
