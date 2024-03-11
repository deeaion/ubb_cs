import org.example.Model.Exceptions.ValidatorException;
import org.example.Model.Angajat;
import org.example.Model.Spectacol;
import org.example.Model.Validators.Enums.ValidatorStrategy;
import org.example.Model.Validators.ModelValidators.AngajatValidator;
import org.example.Model.Validators.ModelValidators.SpectacolValidator;
import org.example.Model.Validators.ValidatorFactory;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.time.LocalDateTime;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ValidatorTests {
    @Test
    @DisplayName("Angajat Validator test")
    public void testAngajatValidator()
    {
        Angajat angajat=new Angajat("Ana","Clara","ana@clara.com","ana","hey");
        ValidatorFactory validatorFactory=new ValidatorFactory();
        AngajatValidator angajatValidator= (AngajatValidator) validatorFactory.createValidator(ValidatorStrategy.Angajat);
        angajatValidator.validate(angajat);
        angajat.setNume("");
        try {
            angajatValidator.validate(angajat);
        }
        catch (ValidatorException exception)
        {
            assertEquals("Name must be at least 2 characters!\n",exception.getMessage());
        }

    }
    @Test
    @DisplayName("Spectacol validator test")
    public void testSpectacolValidator()
    {
        Spectacol spectacol2=new Spectacol("Asda", LocalDateTime.of(2023,11,11,10,10),12,11,"Chris");
        ValidatorFactory validatorFactory=new ValidatorFactory();
        SpectacolValidator validator= (SpectacolValidator) validatorFactory.createValidator(ValidatorStrategy.Spectacol);
        validator.validate(spectacol2);
        spectacol2.setLocatie("");
        try
        {
            validator.validate(spectacol2);
        }
        catch (ValidatorException validatorException)
        {
            assertEquals(validatorException.getMessage(),"Locatia cannot be empty!\n");
        }

    }
}
