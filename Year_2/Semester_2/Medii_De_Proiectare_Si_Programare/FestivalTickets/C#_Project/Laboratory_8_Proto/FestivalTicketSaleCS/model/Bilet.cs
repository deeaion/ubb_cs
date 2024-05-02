using System;

namespace model{
    [Serializable]
    public class Bilet : Entity<long>
    {
        public string NumeCumparator { get; set; }
        public Spectacol Spectacol { get; set; }
        public string Serie { get; set; }
        public int NrLocuri { get; set; }

        public Bilet(string numeCumparator, string serie, Spectacol spectacol, int nrLocuri)
        {
            NumeCumparator = numeCumparator;
            Spectacol = spectacol;
            NrLocuri = nrLocuri;
            Serie = serie;
        }

        public override bool Equals(object obj)
        {
            if (this == obj)
                return true;
            if (!(obj is Bilet bilet))
                return false;
            if (!base.Equals(obj))
                return false;
            return NrLocuri == bilet.NrLocuri && NumeCumparator == bilet.NumeCumparator && Spectacol.Equals(bilet.Spectacol);
        }

       

        public override string ToString()
        {
            return $"Bilet{{nume_cumparator='{NumeCumparator}', spectacol={Spectacol}, nr_locuri={NrLocuri}}} {base.ToString()}";
        }
    }
}
