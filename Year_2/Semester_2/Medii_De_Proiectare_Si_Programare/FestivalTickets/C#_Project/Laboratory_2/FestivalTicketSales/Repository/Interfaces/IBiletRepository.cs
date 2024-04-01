using FestivalTicketSale.Model;

namespace FestivalTicketSale.Repository.Interfaces;

interface IBiletRepository : IRepository<long,Bilet>
{
    IEnumerable<Bilet> FindBySpectacol(Spectacol spectacol);
    IEnumerable<Bilet> FindByName(string name);
    Bilet FindBySeries(string series);
}