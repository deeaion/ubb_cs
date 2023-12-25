package factory;

import model.Container.Container;
import model.Container.QueueContainer;
import model.Container.StackContainer;

import java.security.InvalidParameterException;

public class TaskContainerFactory implements Factory {
    private static TaskContainerFactory instance;
    private TaskContainerFactory() {

    }
    public static TaskContainerFactory getInstance()
    {
        if(instance==null)
        {
            instance=new TaskContainerFactory();
        }
        return instance;
    }
    @Override
    public Container createContainer(Strategy strategy) {
        if(strategy.equals(Strategy.LIFO))
        {
            return new StackContainer();
        }
        if(strategy.equals(Strategy.FIFO))
        {
            return new QueueContainer();
        }
        else
        {
            throw new InvalidParameterException();
        }
    }
}
