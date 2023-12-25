package model.Sorting;

import model.Sorting.SortingOperations.AbstractSorter;

public interface Factory {
    AbstractSorter makeSorter(SortingStrategy strategy);
}

