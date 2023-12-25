package org.example.Domain.Validators;

import org.example.Exception.ValidationException;

/*
    Validator for Enitities. It is an univers Validator
 */
public interface Validator <T>{
    void vaildate(T entity) throws ValidationException;
}
