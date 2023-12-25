package org.example.Repository.DataBaseRepository.Factory;

import org.example.Domain.Validators.*;
import org.example.Exception.RepositoryException;
import org.example.Repository.DataBaseRepository.UserDatabaseRepository;
import org.example.Repository.DataBaseRepository.Util.AbstractDataBaseRepository;
import org.example.Repository.DataBaseRepository.Util.DataBaseAccess;
import org.example.Repository.DataBaseRepository.FriendshipDatabase;

public class DatabaseRepoFactory implements DataBaseFactory {
   private final DataBaseAccess data;

    public DatabaseRepoFactory(DataBaseAccess data) {
        this.data=data;
    }
    @Override
    public AbstractDataBaseRepository createRepositor(DataBaseRepositoryStrategy strategy,Validator validator) {
        switch (strategy)
        {
            case users -> {return new UserDatabaseRepository(validator,data,strategy.toString());}
            case friendship -> {return new FriendshipDatabase(validator,data,strategy.toString());}
            default -> throw new RepositoryException("Invalid Strategy");
        }
    }


}
