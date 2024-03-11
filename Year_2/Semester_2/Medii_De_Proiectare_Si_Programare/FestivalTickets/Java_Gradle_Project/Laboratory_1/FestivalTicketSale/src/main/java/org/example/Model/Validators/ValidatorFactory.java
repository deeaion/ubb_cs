package org.example.Model.Validators;

import org.example.Model.Exceptions.ValidatorException;
import org.example.Model.Validators.Enums.ValidatorStrategy;
import org.example.Model.Validators.Interfaces.Factory;
import org.example.Model.Validators.Interfaces.Validator;
import org.example.Model.Validators.ModelValidators.AngajatValidator;
import org.example.Model.Validators.ModelValidators.SpectacolValidator;

public class ValidatorFactory implements Factory {
    private static ValidatorFactory instance;
    @Override
    public Validator createValidator(ValidatorStrategy validatorStrategy) {
        switch (validatorStrategy)
        {
            case Angajat -> {return new AngajatValidator();}
            case Spectacol -> {return new SpectacolValidator();}
            default -> throw new ValidatorException("Invalid strategy for creating the validator!");
            }

    }
    public static ValidatorFactory getInstance()
    {
        if(instance==null)
        {
            instance=new ValidatorFactory();
        }
        return instance;
    }
}
