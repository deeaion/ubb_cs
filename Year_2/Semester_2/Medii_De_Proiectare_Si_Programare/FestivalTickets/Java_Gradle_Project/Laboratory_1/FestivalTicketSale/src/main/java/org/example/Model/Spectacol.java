package org.example.Model;

import java.time.LocalDateTime;
import java.util.Objects;

public class Spectacol extends Entity<Long>{
    private String locatie;
    private LocalDateTime data;
    private int numar_locuri_disponibile;
    private int numar_locuri_vandute;
    private String artist;

    public Spectacol() {
        locatie="" ;
        data=LocalDateTime.of(2000,10,10,10,10,10,10);
        numar_locuri_disponibile=0;
        numar_locuri_vandute=0;
        artist="";
    }

    public Spectacol(String locatie, LocalDateTime data, int numar_locuri_disponibile, int numar_locuri_vandute, String artist) {
        this.locatie = locatie;
        this.data = data;
        this.numar_locuri_disponibile = numar_locuri_disponibile;
        this.numar_locuri_vandute = numar_locuri_vandute;
        this.artist = artist;
    }

    public String getLocatie() {
        return locatie;
    }

    public void setLocatie(String locatie) {
        this.locatie = locatie;
    }

    public LocalDateTime getData() {
        return data;
    }

    public void setData(LocalDateTime data) {
        this.data = data;
    }

    public int getNumar_locuri_disponibile() {
        return numar_locuri_disponibile;
    }

    public void setNumar_locuri_disponibile(int numar_locuri_disponibile) {
        this.numar_locuri_disponibile = numar_locuri_disponibile;
    }


    public String getArtist() {
        return artist;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }

    public int getNumar_locuri_vandute() {
        return numar_locuri_vandute;
    }

    public void setNumar_locuri_vandute(int numar_locuri_vandute) {
        this.numar_locuri_vandute = numar_locuri_vandute;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Spectacol spectacol)) return false;
        if (!super.equals(o)) return false;
        return getNumar_locuri_disponibile() == spectacol.getNumar_locuri_disponibile() && getNumar_locuri_vandute() == spectacol.getNumar_locuri_vandute() && Objects.equals(getLocatie(), spectacol.getLocatie()) && Objects.equals(getData(), spectacol.getData()) && Objects.equals(getArtist(), spectacol.getArtist());
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), getLocatie(), getData(), getNumar_locuri_disponibile(), getNumar_locuri_vandute(), getArtist());
    }

    @Override
    public String toString() {
        return "Spectacol{" +
                "locatie='" + locatie + '\'' +
                ", data=" + data +
                ", numar_locuri_disponibile=" + numar_locuri_disponibile +
                ", getNumar_locuri_vandute=" + numar_locuri_vandute +
                ", Artist='" + artist + '\'' +
                "} " + super.toString();
    }
}
