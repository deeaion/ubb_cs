using System;
using System.Collections.Generic;
using model;

namespace persistance.Interfaces
{
    public interface ISpectacolRepository : IRepository<long,Spectacol>
    {
        IEnumerable<Spectacol> FindByArtist(string artist);
        IEnumerable<Spectacol> FindByDate(DateTime date);
        IEnumerable<string> GetArtisti();
        IEnumerable<Spectacol> FindByDateandArtist(string artist, DateTime dateTime);
    }
}

