using System;
using System.Collections.Generic;
using model;
using services.Exceptions;

namespace client
{
    public class FestivalClientCtrl : IFestivalObserver
    {
        public event EventHandler<FestivalUserEventArgs> updateEvent;
        private readonly IFestivalServices server;
        private model.Angajat currentUser;
        public FestivalClientCtrl(IFestivalServices server)
        {
            this.server = server;
            currentUser = null;
        }
        protected virtual void OnUserEvent(FestivalUserEventArgs e)
        {
            if (updateEvent == null) return;
            updateEvent(this, e);
            Console.WriteLine("Update Event called");
        }
        public void recievedSellingOfTicket(model.SpectacolDTO spectacol, int nrLocuri, string nume)
        {
           String mess="Selling ticket for "+spectacol.Id_spectacol+" "+nrLocuri+" "+nume;
              FestivalUserEventArgs userArgs=new FestivalUserEventArgs(FestivalUserEvent.BiletAdded,mess);
              Console.WriteLine("Message received");
                OnUserEvent(userArgs);
        }

        public bool logIn(string username, string pass)
        {
            server.logIn(username,pass,this);
            Console.WriteLine("Login succeeded ....");
            currentUser = new model.Angajat(username, pass);
            Console.WriteLine("Current user {0}", currentUser);
            return true;
        }
        public String[] getArtists()
        {
            return server.getArtisti();
        }
        public void userLoggedIn(string username, string password)
        {
           model.Angajat angajat=new model.Angajat(username,password);
           Console.WriteLine("Coworker login"+username+" "+password)  ;
           FestivalUserEventArgs userEventArgs=new FestivalUserEventArgs(FestivalUserEvent.LoggedIn,"Coworker logged in");
           OnUserEvent(userEventArgs);

        }

        public void userLoggedOut(string username, string password)
        {
            Console.WriteLine("Coworker logout");
            FestivalUserEventArgs userArgs = new FestivalUserEventArgs(FestivalUserEvent.LoggedOut, "Coworker logged out");
            OnUserEvent(userArgs);
        }

        public void recievedSpectacole(model.SpectacolDTO[] spectacole)
        {
            String mes="Received spectacole";
            FestivalUserEventArgs userArgs=new FestivalUserEventArgs(FestivalUserEvent.SpectacoleReceived,mes);
            OnUserEvent(userArgs);
        }

        public model.SpectacolDTO[] getSpectacole(DateTime date, string artist,bool filterByDate)
        {
            Console.WriteLine("Get spectacole");
            return server.filterSpectacole(date,artist,filterByDate);
             
        }
        public void logOut()
        {
            Console.WriteLine("Ctrl logout");
            server.logOut(currentUser);
            currentUser = null;
        }
        public void sellTicket(string numeCump, long idSpectacol, int nrLocuri)
        {
            server.addBilet(numeCump,idSpectacol,nrLocuri,this);
            
        }
        
    }
}