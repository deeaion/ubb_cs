package org.example;

import org.example.Domain.Validators.Validator;
import org.example.Domain.Validators.ValidatorFactory;
import org.example.Domain.Validators.ValidatorStrategy;
import org.example.Repository.InMemoryRepository;
import org.example.Repository.Repository;
import org.example.Service.FriendService;
import org.example.UI.UI;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        String url="jdbc:postgresql://localhost:5432/socialnetwork";
        String username="postgres";
        ValidatorFactory factory=new ValidatorFactory();
        Validator userValidator=factory.createValidator(ValidatorStrategy.User);
        Validator FriendValidator=factory.createValidator(ValidatorStrategy.Friendship);
        Repository userRepository=new UserDBRepository(userValidator,url,username,"hello");
        userRepository.findAll().forEach(System.out::println);
        Repository repositoryUser=new InMemoryRepository(userValidator);
        Repository Friendsrepository=new InMemoryRepository(FriendValidator);
        FriendService service=new FriendService(repositoryUser,Friendsrepository) ;
        UI ui=new UI(service);
        ui.launchUI();;
    }
}