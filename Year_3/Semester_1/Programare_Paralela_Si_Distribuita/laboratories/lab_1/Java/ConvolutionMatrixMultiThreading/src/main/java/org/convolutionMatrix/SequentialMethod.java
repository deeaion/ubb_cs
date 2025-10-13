package org.convolutionMatrix;

import org.convolutionMatrix.Utils.ConvolutionItems;
import org.convolutionMatrix.Utils.FileManager;
import org.convolutionMatrix.Utils.MatrixOperations;

public class SequentialMethod {
    private ConvolutionItems items;
    private String inputFile;
    private String outputFile;

    public SequentialMethod(String inputFile, String outputFile)
    {
        this.inputFile=inputFile;
        this.outputFile=outputFile;
    }
    // return the number of milliseconds needed to apply the convolution
    public double applySequentialConvolution()
    {
        if(inputFile==null)
        {
            System.out.println("Please provide an input file");
            return -1;
        }
        FileManager fileManager=new FileManager(inputFile,outputFile);
        items=fileManager.readInput();
        long startTime=System.nanoTime();
        MatrixOperations.applyConvolution(items, 0, items.n, 0, items.m);
        long endTime=System.nanoTime();
        fileManager.writeOutput(items);
        String outputFile="src/main/resources/valid_output/output_"+inputFile.substring(inputFile.lastIndexOf("/")+1);
        System.out.println(outputFile);
        FileManager fileManager1=new FileManager(inputFile,outputFile);
        fileManager1.writeOutput(items);
        return (double) (endTime - startTime) / 1000000;

    }
    public int[][] getResult()
    {
        return items.result;
    }
}
