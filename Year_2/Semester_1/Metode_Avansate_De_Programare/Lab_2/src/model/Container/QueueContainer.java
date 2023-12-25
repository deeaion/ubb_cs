package model.Container;

import model.Task;

public class QueueContainer extends AbstractContainer {
    public QueueContainer()
    {
        super();
    }
    @Override
    public Task remove() {
        if(tasks.isEmpty())
        {
            return null;
        }
        return tasks.remove(0);
    }
}
