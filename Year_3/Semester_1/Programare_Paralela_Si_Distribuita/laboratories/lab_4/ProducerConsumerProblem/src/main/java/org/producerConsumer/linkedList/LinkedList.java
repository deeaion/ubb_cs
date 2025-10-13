package org.producerConsumer.linkedList;

public class LinkedList implements ILinkedList{
    public LinkedListE head;
    public LinkedList() {
        this.head = null;
    }
    //daca primesc head-ul
    public LinkedList(LinkedListE head) {
        this.head = head;
    }
    @Override
    public LinkedListE getHead() {
        return this.head;
    }

    @Override
    public void add(LinkedListE element) {
        //daca lista e goala sau elementul are scorul mai mare decat head-ul
        if (this.head == null || this.head.score < element.score) {
            element.next = this.head;
            this.head = element;
        } else {
            // altfel parcurg lista pana gasesc un element cu scorul mai mic decat elementul
            LinkedListE current = this.head;
            while (current.next != null && current.next.score >= element.score) {
                current = current.next;
            }
            element.next = current.next;
            current.next = element;
        }
    }

    @Override
    public void remove(String key) {
        if (this.head == null) {
            return;
        }

        if (this.head.participant.equals(key)) {
            this.head = this.head.next;
            return;
        }

        LinkedListE current = this.head;
        while (current.next != null && !current.next.participant.equals(key)) {
            current = current.next;
        }

        if (current.next != null) {
            current.next = current.next.next;
        }

    }

    @Override
    public LinkedListE search(String key) {
        LinkedListE current = this.head;
        while (current != null) {
            if (current.participant.equals(key)) {
                return current;
            }
            current = current.next;
        }
        return null;
    }

    @Override
    public void addOrUpdate(LinkedListE element) {
        var current = search(element.participant);
        if (current == null) {
            add(element);
        } else {
            current.score += element.score;
            remove(element.participant); // il sterg pentru a ii modifica pozitia
            // pot si sa fac un swap cu elementul curent dar ar fi aceleasi operatii
            add(current);
        }
    }
}
