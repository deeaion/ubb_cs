package model;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/*
Derivați clasa MessageTask din clasa Task, avand atributele mesaj (String),
 from(String), to(String) si date (LocalDateTime) și afișează pe ecran,
 via metoda execute, textul mesajului (valoarea atributului mesaj) si data
  la care a fost creat; (Vezi si DateTimeFormatter)
Clasa MessageTask ar putea fi refactorizata, astfel inca sa incapsuleze un
obiect de tipul Message avand atributele: id, subject, body, from, to, date
 */
public class MessageTask extends Task {
    private String mesaj;
    private String from;
    private String to;
    private LocalDateTime date;

    private static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");

    public MessageTask(String taskId, String descriere,String mesaj, String from, String to, LocalDateTime date){
        super(taskId, descriere);
        this.mesaj = mesaj;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    @Override
    public void execute() {
        System.out.println("mesaj="+mesaj+"| date="+date.format(formatter));

    }
    //id=1 | description=Feedback lab1| message=Ai obtinut 9.60 | from=Gigi | to=Ana | date=2018-09-27 09:29

    public String toString(){
        return "id="+getTaskId()+" | description=" + getDescriere() + " | message= " + mesaj + " | from= " + from + " | to =" +
                to + " | date = " + date.format(formatter);
    }
}
