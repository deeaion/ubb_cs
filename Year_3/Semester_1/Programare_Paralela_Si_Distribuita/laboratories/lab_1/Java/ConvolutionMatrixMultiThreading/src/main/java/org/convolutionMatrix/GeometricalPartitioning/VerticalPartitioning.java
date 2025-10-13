package org.convolutionMatrix.GeometricalPartitioning;

import org.convolutionMatrix.MyThread;
import org.convolutionMatrix.SequentialMethod;
import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.FileManager;
import org.convolutionMatrix.Utils.MatrixOperations;
import org.convolutionMatrix.Utils.VerifyResult;

public class VerticalPartitioning {
    private ConvolutionItems convolutionItems;
    public String inputFile;
    public String outputFile;
    public int numberOfThreads;

    public VerticalPartitioning(String inputFile, String outputFile, int numberOfThreads) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
        this.numberOfThreads = numberOfThreads;
    }

    public double applyVerticalPartitioningConvolution() {
        if (inputFile == null) {
            System.out.println("Please provide an input file");
            return -1;
        }
        //citesc
        FileManager fileManager = new FileManager(inputFile, outputFile);
        convolutionItems = fileManager.readInput();
        // impart matricea
        int columnsPerThread= convolutionItems.m / numberOfThreads;
        int rest=convolutionItems.m % numberOfThreads;
        Thread[] threads = new Thread[numberOfThreads];
        int start=0;
        int end=convolutionItems.m/numberOfThreads;
        //timp
        long startTime = System.nanoTime();

        for(int i=0;i<numberOfThreads;i++)
        {
            if(rest>0){
                end++;
                rest--;
            }
            threads[i]=new Thread(new MyThread(convolutionItems,0,convolutionItems.n,start,end));
            start=end;
            end=start+columnsPerThread;
            threads[i].start();

        }
        for(int i=0;i<numberOfThreads;i++)
        {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        long endTime = System.nanoTime();
        // write the result
        fileManager.writeOutput(convolutionItems);
        assert VerifyResult.verifyResult(inputFile, outputFile);
        return (double) (endTime - startTime) / 1000000;
    }
    public int [][] getResult()
    {
        return convolutionItems.result;
    }
}
