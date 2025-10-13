package org.producerConsumer.linkedList;

public interface ILinkedList {
    public LinkedListE getHead();
    public void add(LinkedListE element);
    public void remove(String key);
    public LinkedListE search(String key);
    public void addOrUpdate(LinkedListE element);
}
