package model.Sorting.SortingOperations;

import model.Sorting.SortingOperations.AbstractSorter;

public class BubbleSort extends AbstractSorter {
    @Override
    public void sort(int[] toSort) {
        int i,j;
        boolean swaped;

        for(i=0;i< toSort.length;i++)
        {
            swaped=false;
            for(j=0;j<toSort.length-i-1;j++)
            {
                if(toSort[j]>toSort[j+1])
                {
                    swap(toSort,j,j+1);
                    swaped=true;
                }
            }
            if(!swaped)
            {
                break;
            }
        }
    }
}
