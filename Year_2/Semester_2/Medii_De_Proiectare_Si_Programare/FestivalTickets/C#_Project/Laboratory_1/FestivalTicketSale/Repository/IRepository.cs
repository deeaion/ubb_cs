using FestivalTicketSale.Model;

namespace FestivalTicketSale.Repository;


interface IRepository<TId,TE> where TE : Entity<TId>
{
  
    IEnumerable<TE> FindAll();
    protected TE FindOne();
    protected TE Save(TE entity);
    protected TE Delete(TId id);
    protected TE Update(TE entity);

}