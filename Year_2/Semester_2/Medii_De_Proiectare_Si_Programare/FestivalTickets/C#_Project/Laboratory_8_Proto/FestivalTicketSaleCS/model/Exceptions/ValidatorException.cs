using System;
namespace model.Exceptions
{
    public class ValidatorException : Exception
    {
        public ValidatorException() : base()
        {

        }

        /// <summary>
        /// Constructor with a message parameter
        /// </summary>
        /// <param name="message">Message to throw</param>
        public ValidatorException(string message) : base(message)
        {

        }
    }
}