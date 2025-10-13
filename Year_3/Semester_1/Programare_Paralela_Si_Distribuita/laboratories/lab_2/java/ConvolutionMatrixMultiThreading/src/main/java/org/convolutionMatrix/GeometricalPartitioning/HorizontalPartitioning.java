package org.convolutionMatrix.GeometricalPartitioning;

import org.convolutionMatrix.MyThread;
import org.convolutionMatrix.SequentialMethod;
import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.FileManager;
import org.convolutionMatrix.Utils.MatrixOperations;
import org.convolutionMatrix.Utils.VerifyResult;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.CyclicBarrier;

public class HorizontalPartitioning {
    private ConvolutionItems convolutionItems;
    public String inputFile;
    public String outputFile;
    public int numberOfThreads;
    public VariantType variantType;

    public HorizontalPartitioning(String inputFile, String outputFile, int numberOfThreads,VariantType variantType) {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
        this.numberOfThreads = numberOfThreads;
        this.variantType=variantType;
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
        CyclicBarrier cyclicBarrier=null;
        boolean [] flags=null;
        long startTime = System.nanoTime();

        //initializez Bariererle

        if(variantType==VariantType.VARIANTA_1B || variantType==VariantType.VARIANTA_2B)
        {
            cyclicBarrier=new CyclicBarrier(numberOfThreads);
        }
        if(variantType==VariantType.VARIANTA_2F || variantType==VariantType.VARIANTA_1F)
        {
            flags=new boolean[numberOfThreads];
        }
        for(int i=0;i<numberOfThreads;i++)
        {
            if(rest>0){
                end++;
                rest--;
            }
            threads[i]=new Thread(new MyThread(convolutionItems,start,end,0,convolutionItems.m,cyclicBarrier,variantType,flags,i));
            start=end;
            end=start+linesPerThread;
            threads[i].start();

        }
        //astept  barierele

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
        String outputFileToCheck="src/main/resources/valid_output/output_"+inputFile.substring(inputFile.lastIndexOf("/")+1);
        System.out.println(outputFileToCheck);
        try{
            if(VerifyResult.verifyResult(inputFile,outputFile))
            {
                System.out.println("The result is correct");
            }
            else
            {
                System.out.println("The result is incorrect");
            }
        }
        catch (Exception e)
        {
            System.out.println("The result is!!!!!!!! incorrect");
        }

        return (double) (endTime - startTime) / 1000000;
    }}
