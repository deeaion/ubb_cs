package org.producerConsumer.method;

import org.producerConsumer.linkedList.LinkedList;
import org.producerConsumer.linkedList.LinkedListE;
import org.producerConsumer.utils.Constants;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Sequential {

    public static void run() throws FileNotFoundException {
        LinkedList list = new LinkedList();
        Set<String> blackList = new HashSet<>();

        for(int i=0; i< Constants.NO_OF_COUNTRIES;i++){
            for(int j=0;j<Constants.NO_OF_PROBLEMS;j++)
            {
                File file= new File(Constants.OUTPUT_DIR+"/C"+i+"_P"+j+".txt");
                Scanner scanner = new Scanner(file);

                while (scanner.hasNext())
                {
                    String participant = scanner.next();
                    Integer score = scanner.nextInt();
                    if(score == -1)
                    {
                        blackList.add(participant);
                        if(list.search(participant) != null)
                        {
                            list.remove(participant);
                        }
                    }
                    if(!blackList.contains(participant))
                    {
                        LinkedListE element = new LinkedListE(participant,score);
                        list.addOrUpdate(element);
                    }
                }
            }
        }

        try(BufferedWriter writer = new BufferedWriter(new FileWriter("resultsSequential.txt")))
        {
            while(list.getHead() != null)
            {
                writer.write(list.getHead().participant + " " + list.getHead().score + "\n");
                list.remove(list.getHead().participant);
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

    }
}
