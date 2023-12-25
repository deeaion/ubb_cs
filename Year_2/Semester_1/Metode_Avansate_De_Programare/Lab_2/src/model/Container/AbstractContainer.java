package model.Container;

import model.Task;

import java.util.ArrayList;

public abstract class AbstractContainer implements Container {
    protected ArrayList<Task> tasks;

    public AbstractContainer()
    {
        this.tasks = new ArrayList<>();
    }

    @Override
    public abstract Task remove();

    @Override
    public void add(Task task)
    {
        tasks.add(task);
    }

    @Override
    public int size()
    {
        return tasks.size();
    }

    @Override
    public boolean isEmpty()
    {
        return tasks.isEmpty();
    }
}
