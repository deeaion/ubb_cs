package org.producerConsumer.linkedList;

public interface ILinkedList {
    LinkedListE getHead();
    void add(LinkedListE element);
    void remove(String key);
    LinkedListE search(String key);
    void addOrUpdate(LinkedListE element);
    void sort();
    void sortV2();
}
