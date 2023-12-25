package org.example.repository;

import org.example.domain.Movie;
import org.example.domain.User;


import java.sql.*;
import java.util.HashSet;
import java.util.Optional;

public class MovieDbRepository implements Repository<Long, Movie>{
    private String url,username,password;

    public MovieDbRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    @Override
    public Optional<Movie> findOne(Long aLong) {
        Movie user =null;
        try
                (Connection connection=DriverManager.getConnection(url,username,password))
        {
            PreparedStatement statement=connection.prepareStatement("select * from movies where id=?");
            statement.setLong(1,aLong);
            ResultSet resultSet=statement.executeQuery();
            if(resultSet.next())
            {
                String firstName=resultSet.getString("title");
                String lastName=resultSet.getString("director");
                int year=resultSet.getInt("year");
                user=new Movie(firstName,lastName,year);
                user.setId(aLong);

            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.ofNullable(user);
    }

    @Override
    public Iterable<Movie> findAll() {
        HashSet<Movie> movies=new HashSet<>();
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("select * from movies");
             ResultSet resultSet = statement.executeQuery()
        ) {

            while (resultSet.next())
            {
                Long id= resultSet.getLong("id");
                String title=resultSet.getString("title");
                String director=resultSet.getString("director");
                int year=resultSet.getInt("year");
                Movie movie=new Movie(title,director,year);
                movie.setId(id);
                movies.add(movie);


            }
            return movies;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<Movie> save(Movie entity) {
        String insertSQL = "insert into movies(title,director,year) values (?,?,?)";
        try(Connection connection2 = DriverManager.getConnection(url, username, password)){

            PreparedStatement statement = connection2.prepareStatement(insertSQL);
            statement.setString(1,entity.getTitle());
            statement.setString(2,entity.getDirector());
            statement.setInt(3,entity.getYear());
            int answer = statement.executeUpdate();

            if(answer>0)
            {
                ResultSet resultSet=statement.getGeneratedKeys();
                while (resultSet.next())
                {
                    Long id=resultSet.getLong("id");
                    entity.setId(id);
                }



            }
            return answer==0 ? Optional.of(entity): Optional.empty();


        }
        catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<Movie> delete(Long aLong) {
        if (aLong == null) {
            throw new IllegalArgumentException("id must not be null");
        }
        String deleteSQL = "delete from movies where id=?";

        try(Connection connection2 = DriverManager.getConnection(url, username, password)){

            PreparedStatement statement = connection2.prepareStatement(deleteSQL);
            statement.setLong(1,aLong);
            Optional<Movie> foundUser = findOne(aLong);
            int answer=0;
            if(foundUser.isPresent()){
                answer = statement.executeUpdate();
            }
            return answer == 0 ? Optional.empty() : foundUser;

        }
        catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public Optional<Movie> update(Movie entity) {
        if(entity == null){
            throw new IllegalArgumentException("Entity cannot be null!");
        }
        String updateSQL = "update movies set title=?,director=?,year=? where id=?";
        try(Connection connection2 = DriverManager.getConnection(url, username, password)){
            PreparedStatement statement = connection2.prepareStatement(updateSQL);
            statement.setString(1,entity.getTitle());
            statement.setString(2,entity.getDirector());
            statement.setInt(3,entity.getYear());

            statement.setLong(4,entity.getId());
            int answer = statement.executeUpdate();
            return answer == 0 ? Optional.of(entity) : Optional.empty();

        }
        catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
