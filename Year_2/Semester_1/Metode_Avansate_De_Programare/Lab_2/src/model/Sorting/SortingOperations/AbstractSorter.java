package model.Sorting.SortingOperations;

public abstract class AbstractSorter {
    public abstract void sort(int toSort[]);
    static void swap(int[] toSort, int i, int j)
    {
        int temp =toSort[i];
        toSort[i] = toSort[j];
        toSort[j] = temp;
    }
}
