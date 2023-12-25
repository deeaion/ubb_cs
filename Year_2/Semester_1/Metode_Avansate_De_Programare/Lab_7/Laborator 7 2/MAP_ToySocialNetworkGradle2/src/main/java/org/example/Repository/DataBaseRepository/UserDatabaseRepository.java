package org.example.Repository.DataBaseRepository;

import org.example.Domain.User;
import org.example.Domain.Validators.Validator;
import org.example.Exception.RepositoryException;
import org.example.Repository.DataBaseRepository.Util.AbstractDataBaseRepository;
import org.example.Repository.DataBaseRepository.Util.DataBaseAccess;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class UserDatabaseRepository extends AbstractDataBaseRepository<Long, User> {
    public UserDatabaseRepository(Validator<User> validator, DataBaseAccess data, String table) {
        super(validator, data, table);
    }
    private Optional<User> getUser(ResultSet resultSet,Long id) throws SQLException
    {
        String firstName=resultSet.getString("first_name");
        String lastName=resultSet.getString("last_name");
        String username=resultSet.getString("username");
        User user=new User(firstName,lastName,username);
        user.setId(id);
        return Optional.of(user);
    }
    @Override
    public Optional<User> findOne(Long id) {
        if (id==null)
        {
            throw new IllegalArgumentException("Id of entity is  null!");
        }
        String findOneStatement="SELECT * from users where id = ?";
        try
        {
            PreparedStatement statement=data.createStatement(findOneStatement);
            statement.setLong(1,id);
            ResultSet resultSet=statement.executeQuery();
            if(resultSet.next())
            {
//                String firstName=resultSet.getString("first_name");
//                String lastName=resultSet.getString("last_name");
//                String username=resultSet.getString("username");
//                User user=new User(firstName,lastName,username);
//                user.setId(id);
//                return Optional.of(user);
                return getUser(resultSet,id);
            }
            return Optional.empty();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    @Override
    public  Optional<User> delete(Long id){
        Optional<User> entity=findOne(id);
        if(id!=null)
        {
            String deleteStatement="DELETE FROM "+table+" where id="+id;
            int response=0;
            try
            {
                PreparedStatement statement=data.createStatement(deleteStatement);

                if (entity.isPresent())
                {
                    response=statement.executeUpdate();
                }
                return response==0? Optional.empty() : entity;

            }
            catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        else
        {
            throw  new IllegalArgumentException("ID cannot be null!");
        }

    }
    @Override
    public Iterable<User> findAll() {
        String findAllStatement="SELECT * FROM users";
        Set<User> users=new HashSet<>();
        try
        {
            PreparedStatement statement= data.createStatement(findAllStatement);
            ResultSet resultSet=statement.executeQuery();
            while (resultSet.next())
            {
                Long id=resultSet.getLong("id");
//                String firstName=resultSet.getString("first_name");
//                String lastName=resultSet.getString("last_name");
//                String username=resultSet.getString("username");
//                User newUser=new User(firstName,lastName,username);
//                newUser.setId(id);
                users.add(getUser(resultSet,id).get());

            }
        }
        catch (SQLException e)
        {
            throw new RuntimeException(e);
        }
        return users;
    }

    @Override
    public Optional<User> save(User entity) {
        String insertSQL="INSERT INTO users(first_name,last_name,username) values(?,?,?)";
        try
        {
            PreparedStatement statement= data.createStatement(insertSQL);
            statement.setString(1,entity.getFirstName());
            statement.setString(2,entity.getLastName());
            statement.setString(3,entity.getUsername());
            int response=statement.executeUpdate();
            return response==0?Optional.of(entity):Optional.empty();
        }
        catch (SQLException e)
        {
            throw new RepositoryException(e);
        }

    }


    @Override
    public Optional<User> update(User entity) {
        if (entity == null) {
            throw new RepositoryException("Enitity must not be null");
        }
        String updateStatement = "UPDATE users set first_name=?,last_name=?where id=?";
        try {
            PreparedStatement statement = data.createStatement(updateStatement);
            statement.setString(1,entity.getFirstName());
            statement.setString(2,entity.getLastName());
            statement.setString(3,entity.getUsername());
            statement.setLong(4,entity.getId());
            int response=statement.executeUpdate();
            return response==0? Optional.of(entity):Optional.empty();
        } catch (SQLException e) {
            throw new RepositoryException(e);
        }

    }
}
