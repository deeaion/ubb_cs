package org.convolutionMatrix.Utils;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Scanner;

public class FileManager {
    private String inputFile;
    private String outputFile;

    public FileManager(String inputFile, String outputFile) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
    }

    public ArrayConvolutionItems readInputAsArrayConvolution() {
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(inputFile))) {
            // Read dimensions of the matrix
            String[] dimensions = bufferedReader.readLine().split(" ");
            int n = Integer.parseInt(dimensions[0]);
            int m = Integer.parseInt(dimensions[1]);
            // Get the matrix
            int[] matrix = readMatrixAsArray(bufferedReader, n, m);
            // Kernel size
            String[] kernelDimension = bufferedReader.readLine().split(" ");
            int k = Integer.parseInt(kernelDimension[0]);
            // Get the kernel
            int[][] kernel = readMatrix(bufferedReader, k, k);

            return new ArrayConvolutionItems(matrix, kernel, new int[n][m], n, m, k);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private int[] readMatrixAsArray(BufferedReader bufferedReader, int n, int m) {
        int[] matrix = new int[n * m];
        try {
            for (int i = 0; i < n; i++) {
                String[] line = bufferedReader.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    try {
                        matrix[i * m + j] = Integer.parseInt(line[j]);
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input + " + line[j]);
                        throw new RuntimeException("Invalid input");
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return matrix;
    }

    public void writeOutput(ArrayConvolutionItems convolutionItems) {
        // write the result matrix in the output file
        try {
            java.io.PrintWriter printWriter = new java.io.PrintWriter(outputFile);
            for (int i = 0; i < convolutionItems.n; i++) {
                for (int j = 0; j < convolutionItems.m; j++) {
                    printWriter.print(convolutionItems.result[i][j] + " ");
                }
                printWriter.println();
            }
            printWriter.close();
        } catch (java.io.FileNotFoundException e) {
            System.out.println("File not found");
        }
    }

    public ConvolutionItems readInput() {
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(inputFile))) {
            // Read dimensions of the matrix
            String[] dimensions = bufferedReader.readLine().split(" ");
            int n = Integer.parseInt(dimensions[0]);
            int m = Integer.parseInt(dimensions[1]);
            // Get the matrix
            int[][] matrix = readMatrix(bufferedReader, n, m);
            // Kernel size
            String[] kernelDimension = bufferedReader.readLine().split(" ");
            int k = Integer.parseInt(kernelDimension[0]);
            // Get the kernel
            int[][] kernel = readMatrix(bufferedReader, k, k);

            return new ConvolutionItems(matrix, kernel, new int[n][m], n, m, k);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private int[][] readMatrix(BufferedReader bufferedReader, int n, int m) {
        int[][] matrix = new int[n][m];
        try {
            for (int i = 0; i < n; i++) {
                String[] line = bufferedReader.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    try {
                        matrix[i][j] = Integer.parseInt(line[j]);
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input + " + line[j]);
                        throw new RuntimeException("Invalid input");
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return matrix;
    }

    public void writeOutput(ConvolutionItems convolutionItems) {
        // write the result matrix in the output file
        try {
            java.io.PrintWriter printWriter = new java.io.PrintWriter(outputFile);
            for (int i = 0; i < convolutionItems.n; i++) {
                for (int j = 0; j < convolutionItems.m; j++) {
                    printWriter.print(convolutionItems.result[i][j] + " ");
                }
                printWriter.println();
            }
            printWriter.close();
        } catch (java.io.FileNotFoundException e) {
            System.out.println("File not found");
        }
    }

    public static boolean checkIfTwoFilesAreEqual(String file1, String file2) {
        try {
            Scanner scanner1 = new Scanner(new FileReader(file1));
            Scanner scanner2 = new Scanner(new FileReader(file2));
            while (scanner1.hasNextLine() && scanner2.hasNextLine()) {
                String line1 = scanner1.nextLine();
                String line2 = scanner2.nextLine();
                if (!line1.equals(line2)) {
                    return false;
                }
            }
            return !scanner1.hasNextLine() && !scanner2.hasNextLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }
}
