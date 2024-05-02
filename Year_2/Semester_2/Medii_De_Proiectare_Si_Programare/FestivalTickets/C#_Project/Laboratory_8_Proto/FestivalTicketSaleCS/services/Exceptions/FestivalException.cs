using System;

namespace services.Exceptions
{
    public class FestivalException : Exception
    {
        public FestivalException() : base() { }

        public FestivalException(String msg) : base(msg) { }

        public FestivalException(String msg, Exception ex) : base(msg, ex) { }

    }   
  
}