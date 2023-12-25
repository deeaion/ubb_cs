package org.example.UI;

import org.example.Domain.DTOs.FriendDTO;
import org.example.Domain.User;
import org.example.Service.FriendService;

import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class UI {
    private final FriendService service;
    private final Scanner scanner;
    public void printMenu()
    {
        System.out.println("1.Add User");
        System.out.println("2.Add Friendship between users.");
        System.out.println("3.Remove User");
        System.out.println("4.Print All Users");
        System.out.println("5.Print All Friendships");
        System.out.println("6.Delete Friendship between two users");
        System.out.println("7.Print All Communities.");
        System.out.println("8.Get Number of Communities.");
        System.out.println("9.Print biggest community");
        System.out.println("10.Print friends of user befriended in x month y year");
    }
    private void getFriendsUser()
    {
        System.out.println("Name of user: ");
        String username=scanner.nextLine();
        System.out.println("Month:");
        int month=Integer.parseInt(scanner.nextLine());
        System.out.println("Year: ");
        int year=Integer.parseInt(scanner.nextLine());
        String to_print="For user "+service.findbyUsername(username)
            +"friends from month "+
                month +" year "+year;
        String header="Nume Prieten|Prenume Prieten |Data de la care sunt prieteni";
        Iterable<FriendDTO> found=service.getFriendshipsByMonth(username,year,month);
        System.out.println(to_print);
        System.out.println(header);
        found.forEach(System.out::println);
    }
    public UI(FriendService service)
    {
        scanner=new Scanner(System.in);
        this.service=service;
    }
    private void addUserPrompt()
    {
        System.out.print("\nPlease enter First Name: ");
        String firstName=scanner.nextLine();
        System.out.print("\nPlease enter Second Name: ");
        String lastName=scanner.nextLine();
        System.out.print("\nPlease enter username: ");
        String username=scanner.nextLine();
        service.addUser(firstName,lastName,username);


    }
    private void getAllUsersPrompt()
    {
        service.getAllUsers().forEach(System.out::println);
    }
    private void getAllFriendshipsPrompt()
    {
//        for (Object user: service.getAllFriendships()
//        ) {
//            System.out.println(user);
//        }
        service.getAllFriendships().forEach(System.out::println);
    }
    private void addFriendshipPrompt()
    {
        System.out.print("Please enter the first username: ");
        String username1=scanner.nextLine();
        System.out.print("\nPlease enter the second username: ");
        String username2=scanner.nextLine();
        service.addFriendship(username1,username2);
    }
    private void removeUser()
    {
        String username=scanner.nextLine();
        service.removeUser(username);
    }
    private void removeFriendshipPrompt()
    {
        String username1=scanner.nextLine();
        String username2=scanner.nextLine();

        service.removeFriendship(username1,username2);
    }
    private void getCommunitiesPrompt()
    {
        List<List<User>> com=service.getAllCommunities();
//        int index=0;
//        for(List<User> c:com)
//        {
//            System.out.println("Community :"+index);
//            for(User user:c)
//            {
//                System.out.println(user);
//            }
//            System.out.println("---------------------------------");
//            index++;
//        }
        IntStream.range(1,com.size()+1).
                forEach(index->{
                    System.out.println("Community"+index);
                    com.get(index-1).forEach(System.out::println);
                    System.out.println("-------------------------------------");
                });
    }
    private void getNumberofCommunitiesPrompt()
    {
        System.out.println("Number of Communities is: "+service.showNumberofComunities());
    }
    private void getBiggestCommunity()
    {
        List<List<User>> com=service.biggestCommunity();
        IntStream.range(1,com.size()+1).
                forEach(index->
                {
                    System.out.println("Community " + index);
                    com.get(index-1).forEach(System.out::println);
                    System.out.println("------------------------------");
                });
//        int index=1;
//        for (List<User> com:service.biggestCommunity()) {
//
//            System.out.println("Community "+index);
//            for (User user1:com) {
//                System.out.println(user1);
//            }
//            System.out.println("--------------------------------");
//            index++;

    }
    public void launchUI()
    {
       // service.addPredefinedValues();
        // service.addPredefinedValues();
        while (true)
        {
            printMenu();
        //    service.getFriendships(service.findbyUsername("chrisidk")).forEach(System.out::println);
            System.out.println("Your option is: ");
            String option=scanner.nextLine();
            try
            {
                switch (option)
                {
                    case "1": addUserPrompt(); break;
                    case "2":addFriendshipPrompt(); break;
                    case "3":removeUser(); break;
                    case "4":getAllUsersPrompt(); break;
                    case "5":getAllFriendshipsPrompt(); break;
                    case "6":removeFriendshipPrompt(); break;
                    case "7":getCommunitiesPrompt(); break;
                    case "8":getNumberofCommunitiesPrompt(); break;
                    case "9":getBiggestCommunity(); break;
                    case "10":getFriendsUser();break;
                    default: return;

                }
            }
            catch (RuntimeException mes)
            {
                System.out.println(mes);
            }

        }

    }
}
