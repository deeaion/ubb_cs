package model.Sorting;

import model.Sorting.SortingOperations.AbstractSorter;
import model.Sorting.SortingOperations.BubbleSort;
import model.Sorting.SortingOperations.MergeSort;
import model.Sorting.SortingOperations.QuickSort;

import java.security.InvalidParameterException;

public class SorterFactory implements Factory{

    private static SorterFactory instance;
    public static SorterFactory getInstance()
    {
        if (instance==null)
        {
            instance=new SorterFactory();
        }
        return instance;
    }
    public AbstractSorter makeSorter(SortingStrategy strategy) {
        switch (strategy)
        {
            case MergeSort -> {
                    return new MergeSort();
        }
            case QuickSort ->
            {
                return new QuickSort();}
            case BubbleSort -> {return new BubbleSort();}
            default ->
            throw new InvalidParameterException("Incorect Sorter.Failed to create!");
        }
     }
}
