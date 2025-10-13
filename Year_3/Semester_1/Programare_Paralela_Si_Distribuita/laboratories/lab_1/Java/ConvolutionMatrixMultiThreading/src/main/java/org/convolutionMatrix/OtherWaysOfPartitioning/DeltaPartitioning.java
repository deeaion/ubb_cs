package org.convolutionMatrix.OtherWaysOfPartitioning;

import org.convolutionMatrix.MyDistributionThread;
import org.convolutionMatrix.MyThread;
import org.convolutionMatrix.SequentialMethod;
import org.convolutionMatrix.Utils.*;

public class DeltaPartitioning
{

public DeltaPartitioning(String inputFile, String outputFile, int numberOfThreads, DistributionType distributionType) {
    this.inputFile = inputFile;
    this.outputFile = outputFile;
    this.numberOfThreads = numberOfThreads;
    this.distributionType = distributionType;
}
public double applyDeltaPartitioningConvolution(){
    if(inputFile == null){
        System.out.println("Please provide an input file");
        return -1;
    }
    //citesc
    FileManager fileManager = new FileManager(inputFile, outputFile);
    convolutionItems = fileManager.readInputAsArrayConvolution();
    // threaduri
    Thread[] threads = new Thread[numberOfThreads];
    //timp
    long startTime = System.nanoTime();
    // check the distribution type
    switch (distributionType)
    {
        case CYCLIC -> {
            distributeCyclic(threads);
            break;
        }
        case LINEAR -> {
            distributeLinear(threads);
            break;
        }
        default ->
        {
            System.out.println("Invalid distribution type");
            return -1;
        }
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
private void distributeCyclic(Thread[] threads)
{

   // cu pas/ step egal cu numarul de threaduri -> il vedem ca pe un ciclu
    int step=numberOfThreads;
    int start=0;
    for(int i=0;i<numberOfThreads;i++)
    {
        threads[i]=new Thread(new MyDistributionThread(convolutionItems,numberOfThreads,numberOfThreads,start,convolutionItems.n*convolutionItems.m,i));
        threads[i].start();
        start++;
    }

}

private void distributeLinear(Thread[] threads)
{
    // cu pas/ step egal cu 1
    int step=1;
    //pt fiecare thread calculam start si end pt col si linii
    int start = 0;
    int end=convolutionItems.n*convolutionItems.m/numberOfThreads;
    int rest=convolutionItems.n*convolutionItems.m % numberOfThreads;
    for(int i=0;i<numberOfThreads;i++)
    {
        if(rest>0){
            end++;
            rest--;
        }
        threads[i]=new Thread(new MyDistributionThread(convolutionItems,numberOfThreads,numberOfThreads,start,end,i));
        threads[i].start();
        start=end;
        end=start+step;
    }
}
public int [][] getResult()
{
    return convolutionItems.result;
}
    private ArrayConvolutionItems convolutionItems;
    public String inputFile;
    public String outputFile;
    public int numberOfThreads;
    public int [] matrix;
    public DistributionType distributionType;
}
