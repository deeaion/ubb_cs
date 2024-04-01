using FestivalTicketSale.Model.Validators.Enums;

namespace FestivalTicketSale.Model.Validators.Interfaces
{
    public interface IFactory
    {
        IValidator<T> CreateValidator<T>(ValidatorStrategy validatorStrategy);
    }

}