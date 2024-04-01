namespace FestivalTicketSale.Model.Validators.Interfaces;

public interface IValidator<TE>
{
    void Validate(TE input);
}