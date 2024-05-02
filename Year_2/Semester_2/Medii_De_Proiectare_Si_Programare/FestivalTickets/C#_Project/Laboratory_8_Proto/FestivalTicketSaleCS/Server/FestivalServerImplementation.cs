using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using model;
using persistance.Interfaces;
using services.Exceptions;

namespace Server
{
    public class FestivalServerImplementation : IFestivalServices
    {
        private IAngajatRepository angajatRepository;
        private ISpectacolRepository spectacolRepository;
        private model.Angajat angajatLogat;
        private IBiletRepository biletRepository;
        private IDictionary<String,IFestivalObserver> loggedClients;
        
        public FestivalServerImplementation(IAngajatRepository angajatRepository, ISpectacolRepository spectacolRepository, IBiletRepository biletRepository)
        {
            this.angajatRepository = angajatRepository;
            this.spectacolRepository = spectacolRepository;
            this.biletRepository = biletRepository;
            loggedClients = new ConcurrentDictionary<string, IFestivalObserver>();
        }
        private  model.SpectacolDTO convertSpectacolToDTO(Spectacol spectacol)
        {
            return new model.SpectacolDTO(spectacol.Locatie,spectacol.Id.ToString(),spectacol.Data.ToString(),spectacol.NumarLocuriDisponibile.ToString(),spectacol.NumarLocuriVandute.ToString(),spectacol.Artist);
        }
        private Spectacol convertDTOToSpectacol( model.SpectacolDTO spectacolDTO)
        {
            return new Spectacol(spectacolDTO.Locatie,DateTime.Parse(spectacolDTO.Data),Int32.Parse(spectacolDTO.NumarLocuriDisponibile),Int32.Parse(spectacolDTO.NumarLocuriVandute),spectacolDTO.Artist);
        }
        public  model.SpectacolDTO[] getSpectacole()
        {
            List<Spectacol> spectacole = (List<Spectacol>)spectacolRepository.FindAll(); // Assuming FindAll returns an IEnumerable<Spectacol>
            return spectacole.Select(convertSpectacolToDTO).ToArray();
        }
        private string GetInitials(string buyer)
        {
            if (string.IsNullOrWhiteSpace(buyer))
            {
                throw new ArgumentException("Buyer cannot be null or whitespace", nameof(buyer));
            }

            string[] names = buyer.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            StringBuilder initials = new StringBuilder();
            foreach (string name in names)
            {
                initials.Append(name[0]);
            }
            return initials.ToString();
        }
        private int GetNumberOfDigits(long number)
        {
            int count = 0;
            while (number > 0)
            {
                number /= 10;
                count++;
            }
            return count;
        }
        private string GetNumberAsString(long number)
        {
            int nrDigits = GetNumberOfDigits(number);
            StringBuilder nr = new StringBuilder();
            for (int i = 0; i < 4 - nrDigits; i++)
            {
                nr.Append("0");
            }
            nr.Append(number.ToString());
            return nr.ToString();
        }

        private string GenerateSeries(long id, string buyer, DateTime date, long id_spectacol)
        {
            StringBuilder series = new StringBuilder("XY");
            series.Append(id_spectacol.ToString());
            series.Append(GetInitials(buyer));
            series.Append(GetNumberAsString(id));
            series.Append(date.Day.ToString());
            series.Append(date.Month.ToString());
            return series.ToString();
        }
        
        public string[] getArtisti()
        {
            List<string> artisti = (List<string>)spectacolRepository.GetArtisti();
            artisti.Add("None");
            return artisti.ToArray();
        }

        public  model.SpectacolDTO addBilet(string nume_cump, long id_spectacol, int nrLocuri, IFestivalObserver observer)
        {
            Spectacol spectacol= spectacolRepository.FindOne(id_spectacol);
            if (spectacol == null)
                throw new FestivalException("Spectacol inexistent!");
            spectacol.NumarLocuriVandute=spectacol.NumarLocuriVandute+nrLocuri;
            spectacol.NumarLocuriDisponibile=spectacol.NumarLocuriDisponibile-nrLocuri;
            spectacolRepository.Update(spectacol.Id,spectacol);
            model.Bilet bilet = new  model.Bilet(nume_cump, "dummy", spectacol, nrLocuri);
            model.Bilet biletWithId = biletRepository.Save(bilet);
            string series = GenerateSeries(biletWithId.Id, nume_cump, spectacol.Data, spectacol.Id);
            biletWithId.Serie = series;
            biletRepository.Update(biletWithId.Id, biletWithId);
            model.SpectacolDTO spectacolDto= convertSpectacolToDTO(spectacol);
            notifyOfSoldTicket(spectacolDto, nrLocuri, nume_cump, observer);
            return convertSpectacolToDTO(spectacol);
        }

        private void notifyOfSoldTicket( model.SpectacolDTO spectacolDto, int nrLocuri, string numeCump, IFestivalObserver observer)
        {
            IEnumerable<IFestivalObserver> observers = loggedClients.Values;
            foreach (var obs in observers)
            {
                Task.Run(() => obs.recievedSellingOfTicket(spectacolDto, nrLocuri, numeCump));
            }
        }

        public  model.Angajat logIn(string username, string password, IFestivalObserver employee)
        {
            model.Angajat angajat = angajatRepository.FindByEmail(username);

            if (angajat == null)
            {
                angajat = angajatRepository.FindByUsername(username);
                if(angajat == null)
                    throw new FestivalException("Utilizator inexistent!");
            }
            if (angajat.Password != password)
                throw new FestivalException("Parola incorecta!");
            if (loggedClients.ContainsKey(angajat.Username))
            {
                throw new FestivalException("Angajat deja logat!");
            }
            else
            {
                this.angajatLogat = angajat;
                loggedClients[angajat.Username] = employee;
                return angajat;
            }
            
        }

        public  model.SpectacolDTO[] filterSpectacole(DateTime date, string artist,bool filterByDate = false)
        {
            List<Spectacol> spectacols;
            if (!filterByDate && (string.IsNullOrEmpty(artist) || string.Equals(artist, "None", StringComparison.OrdinalIgnoreCase)))
            {
                spectacols= (List<Spectacol>)spectacolRepository.FindAll();
            }
            else if (string.Equals(artist, "None", StringComparison.OrdinalIgnoreCase) || string.IsNullOrEmpty(artist))
            {
                spectacols= (List<Spectacol>)(filterByDate ? spectacolRepository.FindByDate(date) : spectacolRepository.FindByDateandArtist(artist, date));
            }
            else if (!filterByDate)
            {
                spectacols =(List<Spectacol>)spectacolRepository.FindByArtist(artist);
            }
            else{
                spectacols=(List<Spectacol>)spectacolRepository.FindByDateandArtist(artist, date);
        }
            model.SpectacolDTO [] spectacolDtos= spectacols.Select(convertSpectacolToDTO).ToArray();
            return spectacolDtos;
        }

        public bool logOut( model.Angajat angajat)
        {
            IFestivalObserver festivalObserver=loggedClients[angajat.Username];
            if (festivalObserver == null)
                throw new FestivalException("Angajatul nu este logat!");
            loggedClients.Remove(angajat.Username);
            return true;
        }
    }
}