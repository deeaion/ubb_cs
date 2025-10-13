package org.convolutionMatrix.GeometricalPartitioning;

import org.convolutionMatrix.MyThread;
import org.convolutionMatrix.SequentialMethod;
import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.FileManager;
import org.convolutionMatrix.Utils.MatrixOperations;
import org.convolutionMatrix.Utils.VerifyResult;

public class HorizontalPartitioning {
    private ConvolutionItems convolutionItems;
    public String inputFile;
    public String outputFile;
    public int numberOfThreads;

    public HorizontalPartitioning(String inputFile, String outputFile, int numberOfThreads) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
        this.numberOfThreads = numberOfThreads;
    }

    public double applyHorizontalPartitioningConvolution() {
        if (inputFile == null) {
            System.out.println("Please provide an input file");
            return -1;
        }
        //citesc
        FileManager fileManager = new FileManager(inputFile, outputFile);
        convolutionItems = fileManager.readInput();
        // impart matricea
        int linesPerThread= convolutionItems.n / numberOfThreads;
        int rest=convolutionItems.n % numberOfThreads;
        Thread[] threads = new Thread[numberOfThreads];
        int start=0;
        int end=convolutionItems.n/numberOfThreads;
        //timp
        long startTime = System.nanoTime();

        for(int i=0;i<numberOfThreads;i++)
        {
            if(rest>0){
                end++;
                rest--;
            }
            threads[i]=new Thread(new MyThread(convolutionItems,start,end,0,convolutionItems.m));
            start=end;
            end=start+linesPerThread;
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
