package org.producerConsumer.method;

import org.producerConsumer.linkedList.LinkedList;
import org.producerConsumer.queue.CustomQueue;
import org.producerConsumer.thread.ReaderThread;
import org.producerConsumer.thread.ReaderThreadV2;
import org.producerConsumer.thread.WorkerThread;
import org.producerConsumer.utils.Constants;

import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ParallelV2 {
    public static void run(int nrOfReaderThreads, int nrOfWriterThreads) {
        // Create result list and blacklist
        LinkedList result = new LinkedList();
        Set<String> blackList = Collections.synchronizedSet(new HashSet<>());

        // Executor service for readers
        ExecutorService readerExecutor = Executors.newFixedThreadPool(nrOfReaderThreads);

        // Shared queue with max capacity
        CustomQueue<String> queue = new CustomQueue<>(50);

        // Prepare file list
        for (int i = 0; i < Constants.NO_OF_COUNTRIES; i++) {
            for (int j = 0; j < Constants.NO_OF_PROBLEMS; j++) {
                String fileName="C" + i + "_P" + j + ".txt";
                readerExecutor.submit(new ReaderThreadV2(i,fileName,queue,false,null));

            }
        }
        // Shutdown reader executor
        readerExecutor.shutdown();

        // Start worker threads
        Thread[] writerThreads = new Thread[nrOfWriterThreads];
        for (int i = 0; i < nrOfWriterThreads; i++) {
            writerThreads[i] = new WorkerThread(i, queue, result, blackList);
            writerThreads[i].start();
        }

        // Wait for all readers to finish
        try {
            if (!readerExecutor.awaitTermination(Long.MAX_VALUE, TimeUnit.MILLISECONDS)) {
                System.err.println("Reader threads timed out!");
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        // Send termination signals to workers
        for (int i = 0; i < nrOfWriterThreads; i++) {
            try {
                queue.enqueue("-1 -1 -1");
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }

        // Wait for all workers to finish
        for (Thread worker : writerThreads) {
            try {
                worker.join();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }

        // Save final results
        Thread writerThread = new ReaderThreadV2(0, "", queue, true, result);
        writerThread.start();

        try {
            writerThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
