package decorator;
import model.*;

public interface TaskRunner {
    void executeOneTask(); //executa un task din colecţia de task-uri de executat
    void executeAll(); //executǎ toate task-urile din colecţia de task-uri.
    void addTask(Task t); //adaugǎ un task în colecţia de task-uri de executat
    boolean hasTask(); //verifica daca mai sunt task-ri de executat
}