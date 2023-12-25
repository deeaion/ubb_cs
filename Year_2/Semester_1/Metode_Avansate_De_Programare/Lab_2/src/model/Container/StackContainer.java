package model.Container;

import model.Task;

public class StackContainer extends AbstractContainer {

    public StackContainer()
    {
        super();
    }

    @Override
    public Task remove() {
        if(isEmpty())
        {
            return null;
        }
        else {
            return tasks.remove(size() - 1);
        }
    }


}
