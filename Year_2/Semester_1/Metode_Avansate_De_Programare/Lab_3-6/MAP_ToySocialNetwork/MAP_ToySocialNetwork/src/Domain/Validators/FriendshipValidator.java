package Domain.Validators;

import Domain.Friendship;
import Exception.ValidationException.ValidationException;

import java.util.Objects;

public class FriendshipValidator implements Validator<Friendship> {
    /**
     * Validates a friendship between two users!
     * @param entity- the friendship we are validating
     * @throws ValidationException
     *                  "Date must not be invalid"- if the date is null
     *                  Incorrect usernames led to no id found!\n"
     *                  "You cannot add yourself as a friend. You are already your friend :) (at least I hope so).\n"
     *                  ^if u try to make a friendhsip with yourself haha
     */
    @Override
    public void vaildate(Friendship entity) throws ValidationException {
        String toThrow="";
        if(entity.getDate()==null)
        {
            toThrow+="Date must not be invalid";
        }
        if(entity.getId().getRight()==null||entity.getId().getLeft()==null)
        {
            toThrow+="Incorrect usernames led to no id found!\n";
        }
        if(Objects.equals(entity.getId().getLeft(), entity.getId().getRight()))
        {
            toThrow+="You cannot add yourself as a friend. You are already your friend :) (at least I hope so).\n";
        }
        if(!toThrow.isEmpty())
         throw new ValidationException(toThrow);
    }
}
