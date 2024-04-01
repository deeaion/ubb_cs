/*using FestivalTicketSale.Model.Validators.Interfaces;

namespace FestivalTicketSale.Model.Validators;

public abstract class Validator<T> : IValidator where T : IValidatable
{
    public abstract bool Validate(T input);

    public bool Validate (object input)
    {
        return Validate ((T) input);
    }
}

public interface IValidatable
{
}*/