using FestivalTicketSale.Model;

namespace FestivalTicketSale.Repository.Interfaces;

interface ISpectacolRepository : IRepository<long,Spectacol>
{
    IEnumerable<Spectacol> FindByArtist(string artist);
    IEnumerable<Spectacol> FindByDate(DateTime date);
    IEnumerable<string> GetArtisti();
}