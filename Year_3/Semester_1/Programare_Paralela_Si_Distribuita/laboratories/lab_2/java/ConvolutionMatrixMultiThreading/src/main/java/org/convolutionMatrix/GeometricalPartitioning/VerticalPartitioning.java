//package org.convolutionMatrix.GeometricalPartitioning;
//
//import org.convolutionMatrix.MyThread;
//import org.convolutionMatrix.Utils.ConvolutionItems;
//import org.convolutionMatrix.Utils.FileManager;
//import org.convolutionMatrix.Utils.VerifyResult;
//
//import java.util.concurrent.CountDownLatch;
//
//public class VerticalPartitioning {
//    private ConvolutionItems convolutionItems;
//    public String inputFile;
//    public String outputFile;
//    public int numberOfThreads;
//
//    public VerticalPartitioning(String inputFile, String outputFile, int numberOfThreads) {
//        this.inputFile = inputFile;
//        this.outputFile = outputFile;
//        this.numberOfThreads = numberOfThreads;
//    }
//
//    public double applyVerticalPartitioningConvolution() {
//        if (inputFile == null) {
//            System.out.println("Please provide an input file");
//            return -1;
//        }
//
//        FileManager fileManager = new FileManager(inputFile, outputFile);
//        convolutionItems = fileManager.readInput();
//
//        // Împărțim matricea pe coloane
//        int columnsPerThread = convolutionItems.m / numberOfThreads;
//        int rest = convolutionItems.m % numberOfThreads;
//        Thread[] threads = new Thread[numberOfThreads];
//        CountDownLatch countDownLatch = new CountDownLatch(numberOfThreads);
//
//        int start = 0;
//        int end = columnsPerThread;
//
//        long startTime = System.nanoTime();
//
//        for (int i = 0; i < numberOfThreads; i++) {
//            if (rest > 0) {
//                end++;
//                rest--;
//            }
//            threads[i] = new Thread(new MyThread(convolutionItems, 0, convolutionItems.n, start, end, countDownLatch));
//            start = end;
//            end = start + columnsPerThread;
//            threads[i].start();
//        }
//
//        // Așteptăm ca toate thread-urile să finalizeze copierea marginilor
//        try {
//            countDownLatch.await();
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }
//
//        // Așteptăm finalizarea fiecărui thread
//        for (Thread thread : threads) {
//            try {
//                thread.join();
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        }
//
//        long endTime = System.nanoTime();
//        fileManager.writeOutput(convolutionItems);
//        assert VerifyResult.verifyResult(inputFile, outputFile);
//        return (double) (endTime - startTime) / 1000000;
//    }
//}
