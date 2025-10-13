package org.convolutionMatrix;

import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.FileManager;
import org.convolutionMatrix.Utils.MatrixOperations;

public class SequentialMethod {
    private ConvolutionItems items;
    private String inputFile;
    private String outputFile;

    public SequentialMethod(String inputFile, String outputFile) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
    }

    public double applySequentialConvolution() {
        if (inputFile == null) {
            System.out.println("Please provide an input file");
            return -1;
        }

        FileManager fileManager = new FileManager(inputFile, outputFile);
        items = fileManager.readInput();
        long startTime = System.nanoTime();

        applyInPlaceConvolution();

        long endTime = System.nanoTime();

        fileManager.writeOutput(items);

        String validOutputFile = "src/main/resources/valid_output/output_" + inputFile.substring(inputFile.lastIndexOf("/") + 1);
        FileManager validationFileManager = new FileManager(inputFile, validOutputFile);
        validationFileManager.writeOutput(items);

        return (double) (endTime - startTime) / 1000000;
    }

    private void applyInPlaceConvolution() {
        int n = items.n;
        int m = items.m;
        int[][] matrix = items.matrix;

        int[] tempRow = new int[m];  // Current row's convolution results
        int[] prevRow = new int[m];  // Previous row's original values

        for (int j = 0; j < m; j++) {
            prevRow[j] = MatrixOperations.convolution(items, 0, j);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tempRow[j] = MatrixOperations.convolution(items, i, j);
            }

            System.arraycopy(prevRow ,0, matrix[i-1], 0, m);

            int[] swap = prevRow;
            prevRow = tempRow;
            tempRow = swap;
        }
        System.arraycopy(prevRow, 0, matrix[n-1], 0, m);
    }





}
