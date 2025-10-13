package org.producerConsumer.method;

import org.producerConsumer.linkedList.LinkedList;
import org.producerConsumer.queue.CustomQueue;
import org.producerConsumer.thread.ReaderThread;
import org.producerConsumer.thread.WorkerThread;
import org.producerConsumer.utils.Constants;

import java.util.*;

public class Parallel {
    public static void run(int nrOfReaderThreads, int nrOfWriterThreads) {
    //creez lista
        LinkedList result = new LinkedList();
        // black list
        Set<String> blackList = new HashSet<>();
        //coada in care pun shit
        CustomQueue<String > queue=new CustomQueue<>();
        Object lock= new Object();

        int p_r=nrOfReaderThreads;
        int p_w=nrOfWriterThreads;

        List<String> filesArray= new ArrayList<>();

        //adaug fisierele ca sa stiu ce parcurg
        for(int i=0;i< Constants.NO_OF_COUNTRIES;i++)
        {
            for(int j=0;j<Constants.NO_OF_PROBLEMS;j++)
            {
                filesArray.add("C"+i+"_P"+j+".txt");
            }
        }

        // Threads arrays
        Thread[] readerThreads=new Thread[p_r];
        Thread[] writerThreads=new Thread[p_w];

        //calculez cate fisiere i a fiecare thread
        int filesPerThread= filesArray.size()/p_r;
        int rest=filesArray.size() %p_r;
        for(int i=0;i<p_r;i++)
        {
            int start= (rest!=0) ? i*filesPerThread+1 : i*filesPerThread;
            if(rest!=0) rest--;
            int end= start+filesPerThread;
            List<String> threadFiles= Arrays.stream(Arrays.copyOfRange(filesArray.toArray(new String[0]),start,end)).toList();
            readerThreads[i]= new ReaderThread(i,threadFiles,queue,lock,false,null);
            readerThreads[i].start();

        }

        //astept sa se termine toti readerii
        for(Thread reader:readerThreads)
        {
            try {
                reader.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        //pornesc workerii
        for(int i=0;i<p_w;i++)
        {
            writerThreads[i]= new WorkerThread(i,queue,result,blackList,lock);
            writerThreads[i].start();
        }

        //pun in coada -1 -1 pentru a sti ca s-a terminat
        for(int i=0;i<p_w;i++)
        {
            queue.enqueue("-1 -1");
            synchronized (writerThreads[i])
            {
                writerThreads[i].notify();
            }
        }

        //astept sa se termine toti workerii
        for(Thread worker:writerThreads)
        {
            try {
                worker.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        // trimit la primul reader ca sa salveze rezultatele
        readerThreads[0]= new ReaderThread(0,filesArray,queue,lock,true,result);
        readerThreads[0].start();

        try {
            readerThreads[0].join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }


    }
}
