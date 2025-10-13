package org.producerConsumer.old_linkedlist;

public class LinkedListE {
    public String participant;
    public Integer score;
    public LinkedListE next;
    public String country;

    public LinkedListE(String country, Integer score, String participant) {
        this.participant = participant;
        this.country=country;
        this.score = score;
        this.next = null;
    }}
//
//    static class Banda {
//        public Integer n;
//        public Integer currentSize = 0;
//        public List<Nod> list = new ArrayList<>();
//        public boolean finishedProducers = false;
//
//        public Banda(Integer n) {
//            this.n = n;
//        }
//
//        public synchronized void markFinishedProducers() {
//            this.finishedProducers = true;
//            this.notifyAll();
//        }
//
//        public synchronized boolean print() {
//            if (finishedProducers) {
//                return false;
//            }
//
//            list.forEach(System.out::println);
//            System.out.println("=============================================");
//            return true;
//        }
//
//        public synchronized void pune(int idThread) throws InterruptedException {
//            while (currentSize + 4 > n) {
//                this.wait();
//            }
//
//            currentSize += 4;
//            list.add(new Nod(idThread, TipOperatie.DEPUNE, currentSize));
//            this.notifyAll();
//        }
//
//        public synchronized int preia(int idThread) throws InterruptedException {
//            while (currentSize - 3 < 0) {
//                if (!finishedProducers) {
//                    this.wait();
//                } else {
//                    return -1;
//                }
//            }
//
//            currentSize -= 3;
//            list.add(new Nod(idThread, TipOperatie.PREIA, currentSize));
//            this.notifyAll();
//            return currentSize;
//        }
//    }
//
//}
