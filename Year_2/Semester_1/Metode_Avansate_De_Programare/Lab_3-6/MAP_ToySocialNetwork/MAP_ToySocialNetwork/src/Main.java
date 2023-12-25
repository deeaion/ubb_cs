import Domain.Validators.*;
import Repository.InMemoryRepository.InMemoryRepository;
import Repository.Repository;
import Service.Service;
import UI.UI;
import Service.*;
import java.util.UUID;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        ValidatorFactory factory=new ValidatorFactory();
        Validator userValidator=factory.createValidator(ValidatorStrategy.User);
        Validator FriendValidator=factory.createValidator(ValidatorStrategy.Friendship);
        Repository repositoryUser=new InMemoryRepository(userValidator);
        Repository Friendsrepository=new InMemoryRepository(FriendValidator);
        FriendService service=new FriendService(repositoryUser,Friendsrepository) ;
        UI ui=new UI(service);
        ui.launchUI();;
        }
    }
