package decorator;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class PrinterTaskRunner extends AbstractTaskRunner{
    public PrinterTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    @Override
    public void executeOneTask() {
        super.executeOneTask();
        DateTimeFormatter formatter=DateTimeFormatter.ofPattern("HH:mm:ss");
        LocalDateTime exectuionTime=LocalDateTime.now();
        System.out.println("Task ul a fost executat la ora "+exectuionTime.format(formatter));
    }
    @Override
    public void executeAll()
    {
        while(hasTask())
        {
            executeOneTask();
        }
    }
}
