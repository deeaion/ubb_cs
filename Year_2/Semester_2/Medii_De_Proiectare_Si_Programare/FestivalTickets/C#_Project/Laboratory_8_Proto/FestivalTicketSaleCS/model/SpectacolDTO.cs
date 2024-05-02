using System;

namespace model
{[Serializable]
    public class SpectacolDTO
    {
        public string Locatie { get; set; }
        public string Id_spectacol { get; set; }
        public string Data { get; set; }
        public string NumarLocuriDisponibile { get; set; } 
        public string NumarLocuriVandute { get; set; }
        public string Artist { get; set; }

        public SpectacolDTO(string locatie, string idSpectacol, string data, string numarLocuriDisponibile, string numarLocuriVandute, string artist)
        {
            Locatie = locatie;
            Id_spectacol = idSpectacol;
            Data = data;
            NumarLocuriDisponibile = numarLocuriDisponibile;
            NumarLocuriVandute = numarLocuriVandute;
            Artist = artist;
        }

        public override string ToString()
        {
            return base.ToString();
        }

        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}