package org.example.Domain.DTOs;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import org.example.Domain.User;
public class FriendDTO {
    public User getFriend() {
        return friend;
    }

    public void setFriend(User friend) {
        this.friend = friend;
    }

    public LocalDateTime getStartOfFriendship() {

        return startOfFriendship;
    }

    public void setStartOfFriendship(LocalDateTime startOfFriendship) {
        this.startOfFriendship = startOfFriendship;
    }

    public FriendDTO(User friend, LocalDateTime startOfFriendship) {
        this.friend = friend;
        this.startOfFriendship = startOfFriendship;
    }

    User friend;
    LocalDateTime startOfFriendship;

    @Override
    public String toString() {
        String time_printed;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        time_printed=startOfFriendship.format(formatter);
        return friend.getFirstName()+"| "+
                friend.getLastName()+"| "+
               time_printed;
    }
}
