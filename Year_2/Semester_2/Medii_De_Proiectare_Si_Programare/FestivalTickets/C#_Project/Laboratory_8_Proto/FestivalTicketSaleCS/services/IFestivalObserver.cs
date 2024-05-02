using model;

namespace services.Exceptions
{
    public interface IFestivalObserver
    {
        void recievedSellingOfTicket(SpectacolDTO spectacol, int nrLocuri, string nume) ;
        void userLoggedIn(string username,string password) ;
        void userLoggedOut(string username,string password) ;
        void recievedSpectacole(SpectacolDTO[] spectacole) ;

    }
}