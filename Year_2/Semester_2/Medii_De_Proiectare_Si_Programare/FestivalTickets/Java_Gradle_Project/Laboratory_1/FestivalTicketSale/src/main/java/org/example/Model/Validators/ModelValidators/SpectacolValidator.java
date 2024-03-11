package org.example.Model.Validators.ModelValidators;

import org.example.Model.Exceptions.ValidatorException;
import org.example.Model.Spectacol;
import org.example.Model.Validators.Interfaces.Validator;

public class SpectacolValidator implements Validator<Spectacol> {

    @Override
    public void validate(Spectacol entity) throws ValidatorException {
        String errors="";
        if(entity.getLocatie().isEmpty())
        {
            errors+="Locatia cannot be empty!\n";
        }
        if(entity.getNumar_locuri_disponibile()<0)
        {
            errors+="A negative number of available seats is not valid!\n";
        }
        if(entity.getNumar_locuri_vandute()<0)
        {
            errors+="A negative number of sold seats is not valid!\n";
        }
        if(entity.getArtist().isEmpty())
        {
            errors+="Artist cannot be empty!\n";
        }
        if(!errors.isEmpty())
        {
            throw new ValidatorException(errors);
        }
        }
}
