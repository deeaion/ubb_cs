package model.Sorting.SortingOperations;

import model.Sorting.SortingOperations.AbstractSorter;

public class MergeSort extends AbstractSorter {


    private static void merge(int [] a,int [] l, int [] r,int left,int right)
    {
        int i=0,j=0,k=0;
        while(i<left&&j<right)
        {
            if(l[i]<=r[j])
            {
                a[k++]=l[i++];
            }
            else{
                a[k++]=r[j++];
            }
        }
        while(i<left){
            a[k++]=l[i++];
        }
        while(j<right)
        {
            a[k++]=r[j++];
        }

    }
    private static void mergeSort(int[] toSort,int n)
    {
        if(n<2)
        {
            return;
        }
        int mid=n/2;
        int [] l =new int[mid];
        int [] r=new int[n-mid];
        System.arraycopy(toSort, 0, l, 0, mid);
        if (n - mid >= 0) System.arraycopy(toSort, mid, r, 0, n - mid);
        mergeSort(l,mid);
        mergeSort(r,n-mid);
        merge(toSort,l,r,mid,n-mid);
    }
    @Override
    public void sort(int[] toSort) {
        mergeSort(toSort,toSort.length);
    }
}
