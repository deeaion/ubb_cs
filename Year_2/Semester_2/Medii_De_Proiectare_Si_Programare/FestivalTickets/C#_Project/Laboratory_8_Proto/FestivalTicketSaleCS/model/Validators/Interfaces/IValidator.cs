namespace model.Validators.Interfaces
{
    public interface IValidator<TE>
    {
        void Validate(TE input);
    }
}
