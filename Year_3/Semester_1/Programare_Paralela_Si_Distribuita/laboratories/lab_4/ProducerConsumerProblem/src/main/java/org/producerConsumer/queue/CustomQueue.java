package org.producerConsumer.queue;

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
    private int size;

    public CustomQueue() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void enqueue(T item) {
        Node<T> newNode = new Node<>(item);
        if (tail == null) { // Empty queue
            head = tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    public T dequeue() {
        if (head == null) {
            throw new IllegalStateException("Queue is empty");
        }
        T value = head.value;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        size--;
        return value;
    }


    public T peek() {
        if (head == null) {
            throw new IllegalStateException("Queue is empty");
        }
        return head.value;
    }


    public boolean isEmpty() {
        return head == null;
    }


    public int size() {
        return size;
    }
}
