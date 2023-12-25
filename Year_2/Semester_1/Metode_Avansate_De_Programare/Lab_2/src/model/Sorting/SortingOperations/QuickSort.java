package model.Sorting.SortingOperations;

import model.Sorting.SortingOperations.AbstractSorter;

public class QuickSort extends AbstractSorter {

    private void quickSort(int toSort[],int begin,int end)
    {
        if(begin<end)
        {
            int partInd=partition(toSort,begin,end);
            quickSort(toSort,begin,partInd-1);
            quickSort(toSort,partInd+1,end);
        }
    }
    private int partition(int toSort[],int begin,int end)
    {
        int pivot=toSort[end];
        int i=(begin-1);
        int j;
        for(j=begin;j<=end-1;j++)
        {
            if(toSort[j]<pivot)
            {
                i++;
               swap(toSort,i,j);
            }
        }
       swap(toSort,i+1,end);
        return (i+1);
    }
    @Override
    public void sort(int[] toSort) {
        quickSort(toSort,0,toSort.length-1);
    }
}
