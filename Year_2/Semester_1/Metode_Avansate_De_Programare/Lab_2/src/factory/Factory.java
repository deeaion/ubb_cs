package factory;

import model.Container.Container;

public interface Factory {
    Container createContainer(Strategy strategy);
}
