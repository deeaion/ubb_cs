import org.example.Model.Angajat;
import org.example.Model.Spectacol;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.time.LocalDateTime;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ModelTests {
    @Test
    @DisplayName("AngajatTests")
    public void testAngajat()
    {
        Angajat angajat1=new Angajat();
        assertEquals("",angajat1.getEmail());
        assertEquals("",angajat1.getNume());
        Angajat angajat2=new Angajat("Nume","Prenume","Email","Username","Pass");
        assertEquals("Nume",angajat2.getNume());
        assertEquals("Pass",angajat2.getPassword());
    }
    @Test
    @DisplayName("SpectacolTests")
    public void testSpectacol()
    {
        Spectacol spectacol=new Spectacol();
        assertEquals(2000,spectacol.getData().getYear());
        assertEquals("",spectacol.getLocatie());
        Spectacol spectacol2=new Spectacol("", LocalDateTime.of(2023,11,11,10,10),12,11,"Chris");
        assertEquals("",spectacol2.getLocatie());
        assertEquals("Chris",spectacol2.getArtist());
    }
}
