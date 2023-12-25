package Exception.ValidationException;

public class ValidationException extends RuntimeException {
    /**
     * class dedicated to validation exceptions
     */
    public ValidationException()
    {

    }

    /**
     *
     * @param message -> message to throw
     */
    public ValidationException(String message){super(message);}

}
