package decorator;

import model.Task;

public class AbstractTaskRunner implements TaskRunner{
    private TaskRunner wrapper;
    public AbstractTaskRunner(TaskRunner taskRunner)
    {
        this.wrapper=taskRunner;
    }
    @Override
    public void executeOneTask() {
        wrapper.executeOneTask();
    }

    @Override
    public void executeAll() {
        wrapper.executeAll();;
    }

    @Override
    public void addTask(Task t) {
        wrapper.addTask(t);
    }

    @Override
    public boolean hasTask() {
        return wrapper.hasTask();
    }
}
