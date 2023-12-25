package org.example.Repository;

import org.example.Domain.Entity;
import org.example.Domain.User;
import org.example.Domain.Validators.Validator;

import java.sql.*;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class DatabaseRepository implements Repository<Long, User> {
    private String url;
    private String usernameDB;
    private String password;
    private Validator validator;
    public DatabaseRepository(Validator validator, String url, String usernameDB, String password)
    {
        this.url=url;
        this.usernameDB=usernameDB;
        this.password=password;
        this.validator=validator;
    }
    @Override
    public Optional<User> findOne(Long id) {
        User user =null;
        try
                (Connection connection= DriverManager.getConnection(url,usernameDB,password))
        {
            PreparedStatement statement=connection.prepareStatement("select * from users where id=?");
            statement.setLong(1,id);
            ResultSet resultSet=statement.executeQuery();
            if(resultSet.next())
            {
                String firstName=resultSet.getString("first_name");
                String lastName=resultSet.getString("last_name");
                String username=resultSet.getString("username");
                user=new User(firstName,lastName,username);
                user.setId(id);

            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.ofNullable(user);

    }

    @Override
    public Iterable<User> findAll() {
        Set<User> users=new HashSet<>();
        try{
            Connection connection= DriverManager.getConnection(url,usernameDB,password);
            PreparedStatement statement=connection.prepareStatement("select * from users");
            ResultSet resultSet=statement.executeQuery();
            while(resultSet.next())
            {
                Long id=resultSet.getLong("id");
                String firstName=resultSet.getString("first_name");
                String lastName=resultSet.getString("last_name");
                String username=resultSet.getString("username");
                User user=new User(firstName,lastName,username);
                user.setId(id);
                users.add(user);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return users;
    }

    @Override
    public Optional<User> save(User entity) {
        String insertSQL="insert into users(first_name,last_name) values";
        return Optional.empty();
    }

    @Override
    public Optional<User> delete(Long aLong) {
        return Optional.empty();
    }



    @Override
    public Optional<User> update(User entity) {
        return Optional.empty();
    }

}
