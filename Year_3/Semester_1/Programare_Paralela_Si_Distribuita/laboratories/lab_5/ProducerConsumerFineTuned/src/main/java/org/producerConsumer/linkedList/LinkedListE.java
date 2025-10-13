package org.producerConsumer.linkedList;

import java.util.Objects;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LinkedListE {
    public String participant;
    public Integer score;
    public String country;
    public LinkedListE next;
    // pentru lock doar pe un element
    private final Lock lock = new ReentrantLock(); // un ReentrantLock este un lock
    // care poate fi
    // blocat si deblocat de acelasi thread

    public LinkedListE(String country, Integer score, String participant) {
        this.participant = participant;
        this.country=country;
        this.score = score;
        this.next = null;
    }
    public void lock() {
        lock.lock();
    }
    public void unlock() {
        lock.unlock();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof LinkedListE that)) return false;
        return Objects.equals(participant, that.participant)  && Objects.equals(country, that.country) ;
    }

    @Override
    public int hashCode() {
        return Objects.hash(participant, country);
    }
}
