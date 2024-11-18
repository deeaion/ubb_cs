package org.example.Implementations.HashTable;

import org.example.TSValue;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class TSHashTable {
    private MyHashTable<String> hashTable;
    private Set<TSValue> values;
    private int capacity;

    public TSHashTable(int capacity) {
        this.capacity = capacity;
        this.hashTable = new MyHashTable<>(capacity);
        this.values = new HashSet<>();
    }

    public int insert(TSValue value) {
        int post=hashTable.insert(value.getValue()).getValue();
        value.setPosition(post);
        values.add(value);
        return post;
    }
    public List<TSValue> getValues() {
        return new ArrayList<>(values);
    }
}
