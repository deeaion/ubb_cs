package org.example.Domain;


import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Friendship extends Entity<Tuple<Integer,Integer>>{
    private LocalDateTime date;
    private User user2;
    private User user1;

    /**
     * Creates Friendship
     * @param user1 first one
     * @param user2 second one
     * @param date the friendship was made
     */
    public Friendship(User user1,User user2,LocalDateTime date)
    {
        this.user1=user1;
        this.user2=user2;
        this.date=date;
        Integer uuid1=user1.getId();
        Integer uuid2=user2.getId();
        Tuple<Integer,Integer> UUIDComb=new Tuple<>(uuid1,uuid2);
        this.setId(UUIDComb);
    }

    /**
     * Formmater for time
     * @return string formatter
     */
    private String formatter(LocalDateTime time)
    {
        String time_printed;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        time_printed=time.format(formatter);
        return time_printed;
    }

    /**
     * to string function between users
     */
    @Override
    public String toString() {
        return "{Friendship between: "+user1.getUsername()+" "+user2.getUsername()+" , date: "+formatter(getDate())+"}";
    }

    /**
     *
     * @return date of friendship
     */
    public LocalDateTime getDate() {
        return date;
    }

    /**
     * sets date of friendship
     */
    public void setDate(LocalDateTime date) {
        this.date = date;
    }


}
