package Exception.RepositoryException;

import Repository.Repository;

public class RepositoryException extends RuntimeException{
    /**
     * class dedicated to repository exceptions.
     */
    public RepositoryException()
    {

    }
    public RepositoryException(String message)
    {
        super(message);
    }
    public RepositoryException(String message,Throwable cause)
    {
        super(message, cause);
    }
    public RepositoryException(Throwable cause) {
        super(cause);
    }

    public RepositoryException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
