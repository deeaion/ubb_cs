namespace FestivalTicketSale.Repository.Exceptions;

public class RepositoryException : Exception
    {
        public RepositoryException() : base()
        {

        }

        /// <summary>
        /// Constructor with a message parameter
        /// </summary>
        /// <param name="message">Message to throw</param>
        public RepositoryException(string message) : base(message)
        {

        }
    }