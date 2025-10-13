package org.producerConsumer.thread;
import org.producerConsumer.linkedList.ILinkedList;
import org.producerConsumer.queue.CustomQueue;
import org.producerConsumer.utils.Constants;

import java.io.*;
import java.util.List;

public class ReaderThread  extends Thread{
    private List<String> files;
    private CustomQueue<String> queue;
    private final Boolean writeToFile;
    private ILinkedList results = null;
    private int id;

    public ReaderThread(int id,List<String > files, CustomQueue<String> queue,  Boolean writeToFile, ILinkedList results) {
        this.id=id;
        this.files = files;
        this.queue = queue;
        this.writeToFile = writeToFile;
        this.results = results;
    }

    @Override
    public void run(){
        if(!writeToFile)
        {
            readFilesAndEnqueue();
        }
        else {
            writeResultsToFile();
        }
    }

    private void readFilesAndEnqueue() {

        for(String file:files)
        {

        String country=file.split("_")[0];
        try (BufferedReader br = new BufferedReader(new FileReader(Constants.OUTPUT_DIR + '\\' + file))) {
            String line;

            while ((line = br.readLine()) != null) {
                queue.enqueue(line+" "+country);  // Add line to queue
            }
        } catch (FileNotFoundException e) {
            System.err.printf("File %s not found!%n", file);
        } catch (IOException | InterruptedException e) {
            System.err.printf("Error reading file %s: %s%n", file, e.getMessage());
        }}


    }

    private void writeResultsToFile() {
        results.sort();
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("resultsParallel.txt"))) {
            while (results.getHead() != null) {
                bw.write(results.getHead().participant + " " + results.getHead().score + " "+results.getHead().country+"\n");
                results.remove(results.getHead().participant);
            }
        } catch (IOException e) {
            System.err.println("Eroare la scrierea rezultatelor în fișier: " + e.getMessage());
        }
    }

}
