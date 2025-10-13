package org.convolutionMatrix.OtherWaysOfPartitioning;

import org.convolutionMatrix.MyThread;
import org.convolutionMatrix.SequentialMethod;
import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.FileManager;
import org.convolutionMatrix.Utils.MatrixOperations;
import org.convolutionMatrix.Utils.VerifyResult;

public class BlockPartitioning {
    private ConvolutionItems convolutionItems;
    public String inputFile;
    public String outputFile;
    public int numberOfThreads;

    public BlockPartitioning(String inputFile, String outputFile, int numberOfThreads) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
        this.numberOfThreads = numberOfThreads;
    }

    public double applyBlockPartitioningConvolution() {
        if (inputFile == null) {
            System.out.println("Please provide an input file");
            return -1;
        }

        FileManager fileManager = new FileManager(inputFile, outputFile);
        convolutionItems = fileManager.readInput();

        int numBlocksPerRow = (int) Math.ceil(Math.sqrt(numberOfThreads));
        int numBlocksPerColumn = numBlocksPerRow;

        int blockRows = convolutionItems.n / numBlocksPerRow;
        int blockColumns = convolutionItems.m / numBlocksPerColumn;

        int remainingRows = convolutionItems.n % numBlocksPerRow;
        int remainingColumns = convolutionItems.m % numBlocksPerColumn;

        Thread[] threads = new Thread[numBlocksPerRow * numBlocksPerColumn];
        int index = 0;


        long startTime = System.nanoTime();


        for (int i = 0; i < numBlocksPerRow; i++) {
            int rowStart = i * blockRows;
            int rowEnd = rowStart + blockRows;
            if (i < remainingRows) {
                rowEnd++;
            }

            for (int j = 0; j < numBlocksPerColumn; j++) {
                int columnStart = j * blockColumns;
                int columnEnd = columnStart + blockColumns;
                if (j < remainingColumns) {
                    columnEnd++;
                }

                threads[index] = new Thread(new MyThread(convolutionItems, rowStart, rowEnd, columnStart, columnEnd));
                threads[index].start();
                index++;
            }
        }

        for (int i = 0; i < index; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        long endTime = System.nanoTime();
        fileManager.writeOutput(convolutionItems);
        assert VerifyResult.verifyResult(inputFile, outputFile);
        return (double) (endTime - startTime) / 1000000;
    }

    public int[][] getResult() {
        return convolutionItems.result;
    }
}
