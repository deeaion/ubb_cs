using System;
using model.Exceptions;
using model.Validators.Interfaces;

namespace model.Validators.ModelValidators
{
    public class SpectacolValidator : IValidator<Spectacol>
    {
        public void Validate(Spectacol entity)
        {
            string errors = "";

            if (string.IsNullOrEmpty(entity.Locatie))
            {
                errors += "Locatia cannot be empty!\n";
            }
            if (entity.NumarLocuriDisponibile < 0)
            {
                errors += "A negative number of available seats is not valid!\n";
            }
            if (entity.NumarLocuriVandute < 0)
            {
                errors += "A negative number of sold seats is not valid!\n";
            }
            if (string.IsNullOrEmpty(entity.Artist))
            {
                errors += "Artist cannot be empty!\n";
            }
            if (!string.IsNullOrEmpty(errors))
            {
                throw new ValidatorException(errors);
            }
        }
    }
}