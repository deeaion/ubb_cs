package org.example.Implementations.HashTable;
import java.util.*;

public class MyHashTable<T> {
    private static final int INITIAL_CAPACITY = 30;
    private static final float LOAD_FACTOR = 0.75f;
    private int size;
    private int capacity;
    private List<List<T>> buckets;
    private int globalIndex = 0;

    public MyHashTable(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        buckets = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            buckets.add(new ArrayList<>());
        }
    }

    public MyHashTable() {
        this(INITIAL_CAPACITY);
    }

    private int hash(T elem) {
        return Math.abs(elem.hashCode() % capacity);
    }

    private void rehash() {
        int newCapacity = capacity * 2;
        List<List<T>> newBuckets = new ArrayList<>(newCapacity);
        for (int i = 0; i < newCapacity; i++) {
            newBuckets.add(new ArrayList<>());
        }

        // Reinsert all elements into new buckets
        for (var bucket : buckets) {
            for (var elem : bucket) {
                int newIndex = Math.abs(elem.hashCode() % newCapacity);
                newBuckets.get(newIndex).add(elem);
            }
        }

        capacity = newCapacity;
        buckets = newBuckets;
    }

    public Pair<Integer, Integer> insert(T elem) {
        Pair<Integer, Integer> lookup = get(elem);
        if (lookup != null) {
            return lookup;
        }

        // If not found, trigger rehashing if the load factor is exceeded
        if ((float) size / capacity > LOAD_FACTOR) {
            rehash();
        }
        int bucketIndex = hash(elem);  // Get bucket index
        List<T> bucket = buckets.get(bucketIndex);
        int posInList = globalIndex++;
        size++;
        return new Pair<>(bucketIndex, posInList);
    }

    public Pair<Integer, Integer> get(T elem) {
        int bucketIndex = hash(elem);
        List<T> bucket = buckets.get(bucketIndex);
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket.get(i).equals(elem)) {
                return new Pair<>(bucketIndex, i);
            }
        }
        return null;
    }

    public T findByPair(int bucketIndex, int index) throws Exception {
        if (bucketIndex < 0 || bucketIndex >= capacity) {
            throw new Exception("Invalid bucket index");
        }
        List<T> bucket = buckets.get(bucketIndex);
        if (index < 0 || index >= bucket.size()) {
            throw new Exception("Invalid element index");
        }
        return bucket.get(index);
    }

    public String iterate() {
        StringBuilder res = new StringBuilder();
        for (int bucketIndex = 0; bucketIndex < buckets.size(); bucketIndex++) {
            List<T> bucket = buckets.get(bucketIndex);
            for (int posInList = 0; posInList < bucket.size(); posInList++) {
                T element = bucket.get(posInList);
                res.append(bucketIndex).append(",").append(posInList).append(",").append(element).append('\n');
            }
        }
        return res.toString();
    }

    public List<T> getArray() {
        List<T> list = new ArrayList<>();
        for (int bucketIndex = 0; bucketIndex < buckets.size(); bucketIndex++) {
            List<T> bucket = buckets.get(bucketIndex);
            for (int posInList = 0; posInList < bucket.size(); posInList++) {
                T element = bucket.get(posInList);
                list.add(element);
            }
        }
        return list.size() == 0 ? null : list;
    }

    @Override
    public String toString() {
        return iterate();
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }
}
