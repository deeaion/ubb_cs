package org.example.Model;

import java.util.Objects;

public class Angajat extends Entity<Long>{
    private String nume;
    private String prenume;
    private String email;
    private String username;
    private String password;

    public Angajat() {
        nume="";
        prenume="";
        email="";
        username="";
        password="";
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getPrenume() {
        return prenume;
    }

    public void setPrenume(String prenume) {
        this.prenume = prenume;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Angajat(String nume, String prenume, String email, String username, String password) {
        this.nume = nume;
        this.prenume = prenume;
        this.email = email;
        this.username = username;
        this.password = password;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Angajat angajat)) return false;
        if (!super.equals(o)) return false;
        return Objects.equals(nume, angajat.nume) && Objects.equals(prenume, angajat.prenume) && Objects.equals(email, angajat.email) && Objects.equals(username, angajat.username) && Objects.equals(password, angajat.password);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), nume, prenume, email, username, password);
    }

    @Override
    public String toString() {
        return "Angajat{" +
                "nume='" + nume + '\'' +
                ", prenume='" + prenume + '\'' +
                ", email='" + email + '\'' +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                "} " + super.toString();
    }
}
