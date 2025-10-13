package org.producerConsumer;


import org.producerConsumer.method.Parallel;
import org.producerConsumer.method.ParallelV2;
import org.producerConsumer.method.Sequential;
import org.producerConsumer.utils.FileManagment;
import org.producerConsumer.utils.Generator;

import java.io.FileNotFoundException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Objects;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        // primesc argumentele astfel
        //type -> sequential/parallel
        // nrOfReaderThreads -> numarul de threaduri
        // nrOfWriterThreads -> numarul de threaduri
        String type = args[0];
        int nrOfReaderThreads = Integer.parseInt(args[1]);
        int nrOfWriterThreads = Integer.parseInt(args[2]);
        // caut sa vad daca am in src/main/resources datele daca nu le generez
        if(!Files.exists(Paths.get("src/main/resources/input_data")))
        {
            Generator.generate();
        }
        double start = System.nanoTime();
        if(Objects.equals(type, "sequential"))
        {
            Sequential.run();
        }
        else if (Objects.equals(type, "parallel"))
        {
            Parallel.run(nrOfReaderThreads,nrOfWriterThreads);
            FileManagment fileManagment = new FileManagment();
            assert fileManagment.areFilesEqual("resultsSequential.txt","resultsParallel.txt");

        }
        else if(Objects.equals(type, "parallelV2"))
        {
            ParallelV2.run(nrOfReaderThreads,nrOfWriterThreads);
            FileManagment fileManagment = new FileManagment();
            assert fileManagment.areFilesEqual("resultsSequential.txt","resultsParallel.txt");

        }

        double end=System.nanoTime();
        System.out.println((end-start)/1e6); // masurare in Milisecunde

    }
}