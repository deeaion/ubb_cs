package org.example.Domain.Validators;

import org.example.Domain.User;
import org.example.Exception.ValidationException;

public class UserValidator implements Validator<User>{
    /**
     * Validates the User and uses the functions provided bellow
     * @param entity entity to be validated
     * @throws ValidationException if entity does not respect certain criterias (Names not uppercase or all are  empty)
     */
    @Override
    public void vaildate(User entity) throws ValidationException {
        String toThrow;
        toThrow=validateFirstName(entity.getFirstName())+validateLastName(entity.getLastName())+validateUsername(entity.getUsername());
        if(toThrow.isEmpty()) return;
        throw new ValidationException(toThrow);


    }

    /**
     * Validates the first name
     * @param firstName the first name of the User
     * @return toThrow : empty if the string was perfectly fine
     *          else
     *              :+=Invalid FirstName(Name must not be empty)! if string is empty
     *              +="Invalid FirstName(Name must not be null)!\n"; if string is null
     *              +="Invalid FirstName(Name must be UpperCase)!\n"; if is not uppercase
     */
    private String validateFirstName(String firstName)
    {
        String toThrow="";
        if(firstName.isEmpty())
        {
            toThrow+="Invalid FirstName(Name must not be empty)!\n";
        }
        if(!Character.isUpperCase(firstName.charAt(0)))
        {
            toThrow+="Invalid FirstName(Name must be upperCase)!\n";

        }

        return toThrow;
    }

    /**
     * Validates the second Name
     * @param lastName-the second name of the user
     * @return string t
     */
    private String validateLastName(String lastName)
    {
        String toThrow="";
        if(lastName.isEmpty())
        {
            toThrow+="Invalid FirstName(Name must not be empty)!\n";
        }
        if(!Character.isUpperCase(lastName.charAt(0)))
        {
            toThrow+="Invalid LastName ( It must be an uppercase name)!\n";

        }

        return toThrow;
    }

    /**
     * Validates the username
     * @param username <- to val
     * @return empty string if everything is okay else it adds one of the errors or more
     *          +="Invalid username( username must not be empty)!\n";
     *          +="Invalid username( username must not be empty)!\n";
     *          Invalid username (lenght of username must be between 3 and 50)\n";
     */
    private String validateUsername(String username)
    {
        String toThrow="";
        if(username==null)
        {
            toThrow+="Invalid username( username must not be empty)!\n";

        }
        if(username!=null&&username.isEmpty())
        {
            toThrow+="Invalid username( username must not be empty)!\n";
        }
        if(username !=null && (username.length()<3||username.length()>50))
        {
            toThrow+="Invalid username (lenght of username must be between 3 and 50)\n";
        }

        return toThrow;
    }
}
