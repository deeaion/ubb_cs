package org.example.domain;

import javax.swing.*;
import java.util.Objects;

public class Movie extends Entity<Long> {
    private String title;

    public Movie(String title, String director, int year) {
        this.title = title;
        this.director = director;
        this.year = year;
    }

    private String director;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDirector() {
        return director;
    }

    public void setDirector(String director) {
        this.director = director;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    private int year;

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Movie movie = (Movie) o;
        return year == movie.year && Objects.equals(title, movie.title) && Objects.equals(director, movie.director);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), title, director, year);
    }

    @Override
    public String toString() {
        return "Movie{" +
                "title='" + title + '\'' +
                ", director='" + director + '\'' +
                ", year=" + year +
                '}';
    }
}
