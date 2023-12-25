package org.example;

import org.example.domain.Movie;
import org.example.domain.User;
import org.example.repository.MovieDbRepository;
import org.example.repository.Repository;
import org.example.repository.UserDBRepository;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        String url="jdbc:postgresql://localhost:5432/movies";
        String username = "postgres";
        String password = "hello";

        MovieDbRepository movieRepository = new MovieDbRepository(url, username, password);
        //userRepository.findAll().forEach(System.out::println);
//        movieRepository.findAll().forEach(System.out::println);
//        Movie newM=new Movie("HaA","HEaLLO",2023);
//        movieRepository.save(newM);
//        movieRepository.findAll().forEach(System.out::println);
        Movie newM=new Movie("HaAaaaaaaaaaaaaaaaaaa","HEaLLO",2023);
        newM.setId(4l);
        movieRepository.update(newM);
//        System.out.println(movieRepository.delete(3l));



    }
}