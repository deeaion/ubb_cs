using System;

namespace networking.dto
{
    [Serializable]
    public class BiletDTO
    {
        public string IdSpectacol { get; set; }
        public string NumeClient { get; set; }
        public string NumarLocuri { get; set; }
        public BiletDTO(string idSpectacol, string numeClient, string numarLocuri)
        {
            IdSpectacol = idSpectacol;
            NumeClient = numeClient;
            NumarLocuri = numarLocuri;
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