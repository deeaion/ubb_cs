package org.producerConsumer.thread;

import org.producerConsumer.linkedList.LinkedList;
import org.producerConsumer.linkedList.LinkedListE;
import org.producerConsumer.queue.CustomQueue;

import java.util.Set;

public class WorkerThread extends Thread {
    private LinkedList list;
    private CustomQueue<String> queue;
    private Set<String> blackList;
    private final int id;


    public WorkerThread(int id, CustomQueue<String> queue, LinkedList list, Set<String> blackList) {
        this.id = id;
        this.queue = queue;
        this.list = list;
        this.blackList = blackList;
    }

    @Override
    public void run() {
        // tehnic eu fac un while true si ies cand imi zice ca am un -1 -1 indicand sfarsitul

        while (true) {
            String line;
            try {
                line = queue.dequeue();  // Blocking dequeue
                if (line.equals("-1 -1 -1")) {
                    break;  // Proper termination
                }
                process(line);  // Process the line
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;  // Exit on interrupt
            }
        }

    }

    private void process(String line) {
        String[] parts = line.trim().split(" ");

        // Validate the correct number of parts
        if (parts.length != 3) {
            System.err.println("Invalid input format: " + line);
            return;
        }

        String id = parts[0].trim();
        int score;
        String country = parts[2].trim();
//        System.out.println("Country: " + country);

        try {
            score = Integer.parseInt(parts[1].trim());
        } catch (NumberFormatException e) {
            System.err.println("Invalid score format in line: " + line);
            return;
        }

        if (score == -1) {
            blackList.add(id);
            list.remove(id);
        } else {
            if (!blackList.contains(id)) {
                LinkedListE element = new LinkedListE(country, score, id);
                list.addOrUpdate(element);
            }
        }
    }
}

