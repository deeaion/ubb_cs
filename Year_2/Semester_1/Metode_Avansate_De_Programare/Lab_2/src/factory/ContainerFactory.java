package factory;

import model.Container.Container;
import model.Container.QueueContainer;
import model.Container.StackContainer;

public class ContainerFactory implements Factory{
    @Override
    public Container createContainer(Strategy strategy) {
        if(strategy.equals(Strategy.LIFO)){
            return new StackContainer();
        }
        else {
            return new QueueContainer(); // return new Qu..Container();
        }
    }
}
