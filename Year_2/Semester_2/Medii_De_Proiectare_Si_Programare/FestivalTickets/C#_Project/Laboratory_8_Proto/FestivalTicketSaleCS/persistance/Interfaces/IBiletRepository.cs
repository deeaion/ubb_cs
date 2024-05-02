using System.Collections.Generic;
using model;

namespace persistance.Interfaces
{
    public interface IBiletRepository : IRepository<long,Bilet>
    {
        IEnumerable<Bilet> FindBySpectacol(Spectacol spectacol);
        IEnumerable<Bilet> FindByName(string name);
        Bilet FindBySeries(string series);
    }
}

