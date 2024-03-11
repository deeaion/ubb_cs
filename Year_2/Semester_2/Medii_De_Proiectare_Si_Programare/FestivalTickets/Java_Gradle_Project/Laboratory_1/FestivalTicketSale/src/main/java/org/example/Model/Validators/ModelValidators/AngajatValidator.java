package org.example.Model.Validators.ModelValidators;

import org.example.Model.Exceptions.ValidatorException;
import org.example.Model.Angajat;
import org.example.Model.Validators.Interfaces.Validator;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class AngajatValidator implements Validator<Angajat> {
    private static final String EMAIL_REGEX =
            "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";

    private static final Pattern pattern = Pattern.compile(EMAIL_REGEX);

    public static boolean isValidEmail(String email) {
        Matcher matcher = pattern.matcher(email);
        return matcher.matches();
    }
    @Override
    public void validate(Angajat entity) throws ValidatorException {

        String errors="";
        if(entity.getNume().isEmpty() || entity.getNume().length()<=2)
        {
            errors+="Name must be at least 2 characters!\n";
        }
        if(entity.getPrenume().isEmpty() || entity.getPrenume().length()<=2)
        {
            errors+="Prenumele must be at least 2 characters!";
        }
        if(!isValidEmail(entity.getEmail()))
        {
            errors+="Email is not valid!";
        }
        if(entity.getUsername().length()<3)
        {
            errors+="Username is not valid! It must be at least 3 characters!";
        }
        if(entity.getPassword().length()<3)
        {
            errors+="Password must be at least 2 characters long!";
        }
        if(!errors.isEmpty())
        {
            throw new ValidatorException(errors);
        }

    }
}
