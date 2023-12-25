package model;


/*

Definiți clasa abstractă Task avand atributele:
taskID(String),
 descriere(String) si metodele: un constructor cu parametri,
 set/get, execute() (metoda abstracta), toString() si metodele equals - hashCode;  De ce trebuie sa fie clasa Task abstracta?
Contractul equals - hashcode: dacă obj1.equals(obj2) atunci obj1. hashCode() == obj2.hashCode().
Ce se intampla cand avem o relatie de mostenire intre doua clase si suprascriem equals? (a=b => b=a ?)

 */
public abstract class Task {
    private String taskId;
    private String descriere;

    public Task(String taskId, String descriere){
        this.taskId = taskId;
        this.descriere = descriere;
    }

    public void setTaskId(String taskId) {
        this.taskId = taskId;
    }

    public void setDescriere(String descriere) {
        this.descriere = descriere;
    }

    public String getTaskId() {
        return taskId;
    }

    public String getDescriere() {
        return descriere;
    }

    public abstract void execute();

    @Override
    public String toString() {
        return "id="+taskId+"| descriere="+descriere;
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }
}
