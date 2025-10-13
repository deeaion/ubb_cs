package org.producerConsumer.utils;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class FileManagment {
    public boolean areFilesEqual(String file1, String file2) throws FileNotFoundException {
        File fileA=new File(file1);
        File fileB=new File(file2);
        Scanner scannerA = new Scanner(fileA);
        Scanner scannerB = new Scanner(fileB);
        Map<String,String> mapA = new HashMap<>();
        Map<String,String> mapB = new HashMap<>();
        // nu o sa fie neaparat in aceeasi ordine
        while(scannerA.hasNext() && scannerB.hasNext()){
            String participantA = scannerA.next();
            String scoreA = scannerA.next();
            String participantB = scannerB.next();
            String scoreB = scannerB.next();
            mapA.put(participantA,scoreA);
            mapB.put(participantB,scoreB);
        }
        // compar maps
        if(scannerA.hasNext() || scannerB.hasNext()){
            throw new RuntimeException("Files have different number of lines");
        }
        for(String key: mapA.keySet()){
            if(!mapA.get(key).equals(mapB.get(key))){
                throw new RuntimeException("Files have different content");
            }
        }

        return true;
    }
}
