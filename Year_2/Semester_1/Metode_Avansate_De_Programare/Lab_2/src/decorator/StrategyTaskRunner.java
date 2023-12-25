package decorator;

import factory.ContainerFactory;
import factory.Strategy;
import model.Container.Container;
import model.Task;

public class StrategyTaskRunner implements TaskRunner{
    private Container container;
    //private Strategy strategy;
    public StrategyTaskRunner(Strategy strategy)
    {
        ContainerFactory containerFactory=new ContainerFactory();
        this.container= containerFactory.createContainer(strategy);
    }
    //executes task from list
    @Override
    public void executeOneTask() {
        if(hasTask())
        {
            Task removedTask=container.remove();
        removedTask.execute();
        }

    }
    //executes all
    @Override
    public void executeAll() {
        while (hasTask())
        {
            executeOneTask();
        }
    }
    //ads task to containter
    @Override
    public void addTask(Task t) {
        container.add(t);
    }
    //verifies if it has any task

    @Override
    public boolean hasTask() {
        return !container.isEmpty();
    }
}
