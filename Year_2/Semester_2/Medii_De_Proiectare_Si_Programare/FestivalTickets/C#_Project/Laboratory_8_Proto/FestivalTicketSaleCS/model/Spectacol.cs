using System;

namespace model
{[Serializable]
    public class Spectacol : Entity<long>
    {
        public string Locatie { get; set; }
        public DateTime Data { get; set; }
        public int NumarLocuriDisponibile { get; set; } 
        public int NumarLocuriVandute { get; set; }
        public string Artist { get; set; }

        public Spectacol()
        {
            Locatie = "";
            Data = new DateTime(2000, 10, 10, 10, 10, 10,10);
            NumarLocuriVandute = 0;
            NumarLocuriVandute = 0;
            Artist = "";
        }

        public Spectacol(string locatie, DateTime data, int numarLocuriDisponibile, int numarLocuriVandute, string artist)
        {
            Locatie = locatie;
            this.Data = data;
            NumarLocuriDisponibile = numarLocuriDisponibile;
            NumarLocuriVandute = numarLocuriVandute;
            Artist = artist;
        }

        public override string ToString()
        {
            return Id + "," + Locatie + "," + Data + "," + Artist;
        }
    }
}

