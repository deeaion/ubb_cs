package org.convolutionMatrix.Utils;

public class MatrixOperations {
    // Metoda de convoluție standard
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

    // Convoluție folosind o linie de margine
    public static int convolutionWithRow(ConvolutionItems items, int x, int y, int[] row, boolean isTopRow) {
        int sum = 0;
        int[][] c = items.kernel;
        int kernelSize = items.k;
        int halfK = kernelSize / 2;
        int[][] f = items.matrix;

        for (int i = 0; i < kernelSize; i++) {
            for (int j = 0; j < kernelSize; j++) {
                int nx = Math.max(0, Math.min(x - halfK + i, items.n - 1));
                int ny = Math.max(0, Math.min(y - halfK + j, items.m - 1));

                if (isTopRow && nx == x - 1) {
                    sum += row[ny] * c[i][j];
                } else if (!isTopRow && nx == x + 1) {
                    sum += row[ny] * c[i][j];
                } else {
                    sum += f[nx][ny] * c[i][j];
                }
            }
        }
        return sum;
    }

    public static int convolutionWithBoundaries(ConvolutionItems items, int x, int y, int[] tRow, int[] cRow, int[] bRow, boolean isLastRow) {
        int sum = 0;
        int[][] kernel = items.kernel;

        // Verify top, left, and right values
        int topValue = (tRow != null) ? tRow[y] : cRow[y];
        int topLeft = (tRow==null ? (y>0 ? cRow[y-1] : cRow[y]) : (y>0?tRow[y-1]:tRow[y]));
        int topRight = (tRow==null ? (y<items.m-1 ? cRow[y+1] : cRow[y]) : (y<items.m-1?tRow[y+1]:tRow[y]));

        int leftValue = (y > 0) ? cRow[y - 1] : cRow[y];
        int rightValue = (y < items.m - 1) ? cRow[y + 1] : cRow[y];

        // Set bottom, bottomLeft, and bottomRight values based on isLastRow
        int bottomValue, bottomLeft, bottomRight;
        if (isLastRow) {
            if (bRow != null) {
                bottomValue = bRow[y];
                bottomLeft = (y > 0) ? bRow[y - 1] : bRow[y];
                bottomRight = (y < items.m - 1) ? bRow[y + 1] : bRow[y];
            } else {
                bottomValue = cRow[y];
                bottomLeft = (y > 0) ? cRow[y - 1] : cRow[y];
                bottomRight = (y < items.m - 1) ? cRow[y + 1] : cRow[y];
            }
        } else {
            bottomValue = items.matrix[x + 1][y];
            bottomLeft = (y > 0) ? items.matrix[x + 1][y - 1] : items.matrix[x + 1][y];
            bottomRight = (y < items.m - 1) ? items.matrix[x + 1][y + 1] : items.matrix[x + 1][y];
        }

        // Calculate convolution sum using the kernel values
        sum += topLeft * kernel[0][0];
        sum += topValue * kernel[0][1];
        sum += topRight * kernel[0][2];
        sum += leftValue * kernel[1][0];
        sum += cRow[y] * kernel[1][1];
        sum += rightValue * kernel[1][2];
        sum += bottomLeft * kernel[2][0];
        sum += bottomValue * kernel[2][1];
        sum += bottomRight * kernel[2][2];

        // Debug message to verify values used in calculation
//        System.out.println("For position (" + x + "," + y + "): " +
//                "topLeft=" + topLeft + ", top=" + topValue + ", topRight=" + topRight + ", " +
//                "left=" + leftValue + ", center=" + cRow[y] + ", right=" + rightValue + ", " +
//                "bottomLeft=" + bottomLeft + ", bottom=" + bottomValue + ", bottomRight=" + bottomRight +
//                " => Calculated Sum: " + sum);

        return sum;
    }
}
