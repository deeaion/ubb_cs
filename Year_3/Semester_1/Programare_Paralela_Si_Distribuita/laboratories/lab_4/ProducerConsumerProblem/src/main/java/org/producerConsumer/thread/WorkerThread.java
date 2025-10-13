package org.producerConsumer.thread;

import org.producerConsumer.linkedList.LinkedList;
import org.producerConsumer.linkedList.LinkedListE;
import org.producerConsumer.queue.CustomQueue;

import java.util.Queue;
import java.util.Set;

public class WorkerThread extends Thread{
    private LinkedList list;
    private CustomQueue<String> queue;
    private Set<String> blackList;
    private final Object lock;
    private final int id;
    public WorkerThread(int id,CustomQueue<String> queue, LinkedList list, Set<String> blackList, Object lock) {
        this.id=id;
        this.queue = queue;
        this.list = list;
        this.blackList = blackList;
        this.lock = lock;
    }

    @Override
    public void run()
    {
        // tehnic eu fac un while true si ies cand imi zice ca am un -1 -1 indicand sfarsitul
        while(true)
        {
            String line;
            synchronized (lock)
            {
                // cat timp coada e goala astept
                while(queue.isEmpty())
                {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        return;
                    }
                }
                // scot din coada
                line=queue.dequeue();
                // daca am primit -1 -1 ies
                if(line.equals("-1 -1"))
                {
                    lock.notifyAll();
                    break;
                }
            }
            // procesez linia
            process(line);
        }
    }
    private void process(String line)
    {
        String [] parts=line.split(" ");
        String id=parts[0].trim();
        int score=Integer.parseInt(parts[1].trim());

        // blochez lista
        synchronized (list)
        {
            if(score==-1)
            {
                blackList.add(id);
                if(list.search(id)!=null)
                {
                    list.remove(id);
                }
            }
            else
            {
                if(!blackList.contains(id)) {
                    LinkedListE element = new LinkedListE(id, score);
                    list.addOrUpdate(element);
                }
            }
        }
    }
}
