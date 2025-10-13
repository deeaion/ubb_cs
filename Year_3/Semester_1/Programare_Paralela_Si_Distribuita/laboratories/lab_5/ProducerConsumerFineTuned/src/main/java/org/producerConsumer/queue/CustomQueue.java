package org.producerConsumer.queue;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CustomQueue<T> {

    private static class Node<T> {
        T value;
        Node<T> next;

        Node(T value) {
            this.value = value;
            this.next = null;
        }
    }

    private Node<T> head;
    private Node<T> tail;
    private final AtomicInteger size = new AtomicInteger(0);
    private final int capacity;
    private int consumersFinished = 0;
    private int consumers=0;

    private final Lock lock = new ReentrantLock();
    private final Condition isNotFull = lock.newCondition();
    private final Condition isNotEmpty = lock.newCondition();
    private boolean hasFinished = false;
    public CustomQueue(int capacity) {
        this.capacity = capacity;
        this.head = null;
        this.tail = null;
    }

    public CustomQueue(int capacity, int consumers) {
        this.capacity = capacity;
        this.head = null;
        this.tail = null;
        this.consumers = consumers;
    }
    /**
     * Add to the queue
     */
    public void enqueue(T item) throws InterruptedException {
        lock.lock();
        try {
            while (size.get() == capacity) {
//                System.out.println("Queue full, waiting for space...");
                isNotFull.await();  // Wait for available space
            }
            //i need to access the property id of the item

            if (item.toString().split(",")[0].equals("-1")) {
                hasFinished = true;
            }

            Node<T> newNode = new Node<>(item);
            if (tail == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }

            size.incrementAndGet();
//            System.out.println("Enqueue: " + item);
            isNotEmpty.signalAll();  // Notify waiting consumers
        } finally {
            lock.unlock();
        }
    }

    public void consumerFinished() {
        lock.lock();
        try {
            if (!hasFinished) {
                hasFinished = true;
                isNotEmpty.signalAll(); // Wake up any waiting consumers
            }
        } finally {
            lock.unlock();
        }
    }

    public boolean hasFinishedQueing() {
        lock.lock();
        try {
            if(hasFinished)
            {
                System.out.println("Has finished: " + hasFinished);
            }
            return hasFinished ;
        } finally {
            lock.unlock();
        }

    }
    /**
     * Remove from the queue
     */
    public T dequeue() throws InterruptedException {
        lock.lock();
        try {
            while (size.get() == 0) {
//                System.out.println("Queue empty, waiting for items...");
                if(hasFinished)
                {
                    return null;
                }
                isNotEmpty.await();  // Wait for available items
            }

            T value = head.value;
            head = head.next;
            if (head == null) {
                tail = null;
            }

            size.decrementAndGet();
//            System.out.println("Dequeue: " + value);
            isNotFull.signalAll();  // Notify waiting producers
            return value;
        } finally {
            lock.unlock();
        }
    }

    public List<T> getCurrentItems() {
        lock.lock();
        try {
            ArrayList<T> items = new ArrayList<>();
            Node<T> current = head;
            while (current != null) {
                items.add(current.value);
                current = current.next;
            }
            return items;
        } finally {
            lock.unlock();
        }
    }

    /**
     * Check if the queue is empty
     */
    public boolean isEmpty() {
        lock.lock();
        try {
            return size.get() == 0;
        } finally {
            lock.unlock();
        }
    }

    /**
     * Return the current size of the queue
     */
    public int size() {
        return size.get();
    }
}
