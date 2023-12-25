package model.Sorting;

import model.Sorting.SortingOperations.AbstractSorter;
import model.Sorting.SortingOperations.BubbleSort;
import model.Sorting.SortingOperations.MergeSort;
import model.Sorting.SortingOperations.QuickSort;
import model.Task;

public class SortingTask extends Task {
    int[] toSort;
    SortingStrategy strategy;
    AbstractSorter taskSorter;
    public SortingTask(int [] toSort,SortingStrategy strategy,String taskId,String descriere)
    {
        super(taskId,descriere);
        this.toSort=toSort;
        this.strategy=strategy;
        SorterFactory factory=new SorterFactory();
        taskSorter=factory.makeSorter(strategy);
    }
    @Override
    public void execute() {
        taskSorter.sort(toSort);
    }
}
