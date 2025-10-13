package org.producerConsumer.utils;
import java.util.*;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class SyncMap<K,V> {
    private Map<K, List<V>> map;
    Lock lock;

    //sort function
    Comparator<V> comparator;

    public SyncMap(Comparator<V> comparator)
    {
        this.comparator = comparator;
        map = new TreeMap<>();
        lock = new ReentrantLock();
    }
    public SyncMap()
    {
        map = new TreeMap<>();
        lock = new ReentrantLock();
    }

    public void add(K key,V value)
    {
        lock.lock();
        if(map.containsKey(key))
        {
            if(comparator != null)
            {
                List<V> list = map.get(key);
                list.add(value);
                list.sort(comparator);
            }
            else
            {
                List<V> list = map.get(key);
                list.add(value);
            }
        }
        else
        {
            List<V> list = new ArrayList<>();
            list.add(value);
            map.put(key,list);
        }
        lock.unlock();
    }
    public List<K> getKeys(){
        lock.lock();
        try{
            return new ArrayList<>(map.keySet());
        }
        finally {
            lock.unlock();
        }
    }

    public List<V> get(K key)
    {
        lock.lock();
        try{
            return map.get(key);
        }
        finally {
            lock.unlock();
        }
    }

    public int size()
    {
        lock.lock();
        try{
            return map.size();
        }
        finally {
            lock.unlock();
        }
    }

    public int size(K key)
    {
        lock.lock();
        try{
            return map.get(key).size();
        }
        finally {
            lock.unlock();
        }
    }

    public int sizeAll()
    {
        lock.lock();
        try{
            int size = 0;
            for(K key : map.keySet())
            {
                size += map.get(key).size();
            }
            return size;
        }
        finally {
            lock.unlock();
        }
    }


}
