using model.Validators.Enums;

namespace model.Validators.Interfaces
{
    public interface IFactory
    {
        IValidator<T> CreateValidator<T>(ValidatorStrategy validatorStrategy);
    }

}