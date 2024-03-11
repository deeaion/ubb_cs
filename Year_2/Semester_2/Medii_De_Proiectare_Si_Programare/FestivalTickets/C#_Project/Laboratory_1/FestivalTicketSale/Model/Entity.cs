namespace FestivalTicketSale.Model;

public class Entity<TId>
{
    public Entity() {}

    public Entity(TId id)
    {
        this.Id = id;
    }

    public TId Id
    {
        get;
        set;
    } = default!;
}