package org.producerConsumer.linkedList;

import java.util.ArrayList;

public class LinkedList implements ILinkedList {
    private final LinkedListE head; // Santinela de inceput
    private final LinkedListE tail; // Santinela de sfarsit

    public LinkedList() {
        head = new LinkedListE("SENTINEL", Integer.MIN_VALUE, "HEAD");
        tail = new LinkedListE("SENTINEL", Integer.MAX_VALUE, "TAIL");
        head.next = tail;
    }

    @Override
    public LinkedListE getHead() {
        return head.next == tail ? null : head.next;
    }

    // Adaugare fara ordine
    @Override
    public void add(LinkedListE element) {
//        System.out.println("Adding " + element.participant + " with score " + element.score);
        head.lock();
        try {
            LinkedListE first = head.next;
            first.lock();
            try {
                element.next = first;
                head.next = element;
            } finally {
                first.unlock();
            }
        } finally {
            head.unlock();
        }
    }


    @Override
    public void remove(String key) {
//        System.out.println("Removing " + key);

        LinkedListE pred = head;
        pred.lock();
        try {
            LinkedListE curr = pred.next;
            while (curr != tail) {
                curr.lock();
                try {
                    if (curr.participant.equals(key)) {
//                        System.out.println("Found and removing " + key);
                        pred.next = curr.next;  // Link pred to the next node
                        curr.unlock();
                        return;  // Exit safely
                    }
                    pred.unlock();  // Unlock pred before moving to curr
                    pred = curr;
                    curr = curr.next;
                } catch (Exception e) {
                    curr.unlock();  // Ensure curr is unlocked if an error occurs
                    throw e;
                }
            }
        } finally {
            pred.unlock();  // Unlock pred at the end
        }
    }


    @Override
    public LinkedListE search(String key) {
        LinkedListE curr = head.next;
        while (curr != tail) {
            curr.lock();
            try {
                if (curr.participant.equals(key)) {
                    return curr;
                }
            } finally {
                curr.unlock();
            }
            curr = curr.next;
        }
        return null;
    }


    @Override
    public void addOrUpdate(LinkedListE element) {

        LinkedListE curr = head.next;

        while (curr != tail) {
            curr.lock();  // Lock current node
            try {
                if (curr.participant.equals(element.participant)
                        && curr.country.equals(element.country)) {
//                        System.out.println("Updating " + element.participant + " with score " + element.score);
                    curr.score += element.score;
                    return;
                }

            } finally {
                curr.unlock();  // Ensure the current node is unlocked
            }
            curr = curr.next;
        }
        add(element);  // Add if the element wasn't found

    }

    @Override
    public void sort() {
        head.next = bottomUpMergeSort(head.next);
    }

    private LinkedListE bottomUpMergeSort(LinkedListE start) {
        if (start == null || start == tail || start.next == tail) {
            return start;  // Base case
        }

        int size = getListSize(start);
        LinkedListE dummy = new LinkedListE("DUMMY", 0, "DUMMY");
        dummy.next = start;

        for (int width = 1; width < size; width *= 2) {
            LinkedListE current = dummy.next;
            LinkedListE tailRef = dummy;

            while (current != tail && current != null) {
                LinkedListE left = current;
                LinkedListE right = split(left, width);
                current = split(right, width);

                tailRef.next = merge(left, right);
                while (tailRef.next != tail && tailRef.next != null) {
                    tailRef = tailRef.next;
                }
            }
        }
        return dummy.next;
    }


    private int getListSize(LinkedListE start) {
        int size = 0;
        while (start != tail) {
            size++;
            start = start.next;
        }
        return size;
    }

    private LinkedListE split(LinkedListE start, int size) {
        while (size > 1 && start != null && start.next != tail) {
            start = start.next;
            size--;
        }
        LinkedListE rest = (start != null && start.next != tail) ? start.next : tail;
        if (start != null) start.next = tail;  // Break the list
        return rest;
    }

    private LinkedListE merge(LinkedListE left, LinkedListE right) {
        LinkedListE dummy = new LinkedListE("DUMMY", 0, "DUMMY");
        LinkedListE current = dummy;

        while (left != tail && right != tail) {
            if (left.score >= right.score) {
                current.next = left;
                left = left.next;
            } else {
                current.next = right;
                right = right.next;
            }
            current = current.next;
        }

        current.next = (left != tail) ? left : right;
        return dummy.next;
    }

    @Override
    public void sortV2()
    {
        // copiez lista intr-un array
        ArrayList<LinkedListE> array = new ArrayList<LinkedListE>();
        LinkedListE current = head.next;
        while(current != tail)
        {
            array.add(current);
            current = current.next;
        }
        // sortez array-ul
        array.sort((a,b) -> b.score - a.score);
    }



}
