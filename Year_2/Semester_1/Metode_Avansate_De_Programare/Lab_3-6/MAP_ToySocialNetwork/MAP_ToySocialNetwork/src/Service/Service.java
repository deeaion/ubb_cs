package Service;

import Domain.Entity;
import Domain.Friendship;
import Domain.User;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public interface Service <ID>{
    //SO in service first of all lets have CRUD

    /**
     * Adds an user to our network.
     * @param firstName - first name
     * @param lastName - to ADD
     * @param userName -username user
     * @return true if user was added
     *          throws: RepoException and ValidationException if anything happens(because of repo)
     */
    boolean addUser(String firstName, String lastName, String userName);

    /**
     * Removes an user and if they are friends with someone they get that friendship removed.
     * And also all the friendship entities that contain him
     * @param username
     * @return the removed user if it is removed
     */
    Entity<String> removeUser(String username);


    /**
     *
     * @param username1
     * @param username2
     * @return
     */
    boolean addFriendship(String username1,String username2);
    boolean removeFriendship(String username1,String username2);
    int showNumberofComunities();
//PRIVATE FUNCTIONS THAT ARE USED FOR THE MAIN ONES
    List<List<User>> biggestCommunity();
    Iterable getAllUsers();
     Iterable getAllFriendships();


}
