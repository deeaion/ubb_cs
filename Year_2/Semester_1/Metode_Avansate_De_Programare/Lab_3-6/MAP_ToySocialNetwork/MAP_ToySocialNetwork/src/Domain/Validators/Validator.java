package Domain.Validators;

import Exception.ValidationException.ValidationException;
/*
    Validator for Enitities. It is an univers Validator
 */
public interface Validator <T>{
    void vaildate(T entity) throws ValidationException;
}
