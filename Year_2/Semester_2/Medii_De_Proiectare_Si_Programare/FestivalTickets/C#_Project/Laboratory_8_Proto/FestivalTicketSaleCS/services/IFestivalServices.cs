using System;
using model;

namespace services.Exceptions
{
    public interface IFestivalServices
    {
        SpectacolDTO[] getSpectacole();
        String[] getArtisti();
        SpectacolDTO addBilet(String nume_cump,long id_spectacol,int nrLocuri,IFestivalObserver observer) ;
        Angajat logIn(String username,String password,IFestivalObserver employee) ;
        Boolean logOut(Angajat angajat);
        SpectacolDTO[] filterSpectacole(DateTime date, String Artist,bool filterByDate=false) ;

    }
}