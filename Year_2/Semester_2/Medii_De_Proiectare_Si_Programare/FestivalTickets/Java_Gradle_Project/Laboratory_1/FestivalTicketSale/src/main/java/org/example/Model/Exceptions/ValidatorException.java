package org.example.Model.Exceptions;

public class ValidatorException extends RuntimeException{
    public ValidatorException()
    {

    }

    /**
     *
     * @param message -> message to throw
     */
    public ValidatorException(String message){super(message);}
}