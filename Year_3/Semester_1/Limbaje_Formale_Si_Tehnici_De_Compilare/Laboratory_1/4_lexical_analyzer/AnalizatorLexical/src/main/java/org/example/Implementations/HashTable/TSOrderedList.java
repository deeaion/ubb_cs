package org.example.Implementations.HashTable;

import org.example.TSValue;

import java.util.ArrayList;
import java.util.List;

public class TSOrderedList {

    private List<TSValue> symbols;

    public TSOrderedList() {
        this.symbols = new ArrayList<>();
    }

    public int insert(TSValue value) {
        TSValue existingValue = find(value.getValue());
        if (existingValue != null) {
            return existingValue.getPosition();
        }
        int index = binarySearchInsertPosition(value.getValue());
        symbols.add(index, value);
        // Update positions
        for (int i = index; i < symbols.size(); i++) {
            symbols.get(i).setPosition(i);
        }
        return index;
    }

    private int binarySearchInsertPosition(String value) {
        int low = 0;
        int high = symbols.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            TSValue midValue = symbols.get(mid);

            if (midValue.getValue().compareTo(value) < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    public TSValue find(String value) {
        int index = binarySearchFindPosition(value);
        if (index >= 0 && index < symbols.size() && symbols.get(index).getValue().equals(value)) {
            return symbols.get(index);
        } else {
            return null;
        }
    }

    private int binarySearchFindPosition(String value) {
        int low = 0;
        int high = symbols.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            TSValue midValue = symbols.get(mid);

            if (midValue.getValue().compareTo(value) < 0) {
                low = mid + 1;
            } else if (midValue.getValue().compareTo(value) > 0) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low;
    }


    public List<TSValue> getValues() {
        return symbols;
    }
}
