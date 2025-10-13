package org.producerConsumer.linkedList;

public class LinkedListE {
    public String participant;
    public Integer score;
    public LinkedListE next;

    public LinkedListE(String country, Integer score) {
        this.participant = country;
        this.score = score;
        this.next = null;
    }
}
