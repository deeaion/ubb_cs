using System;
using System.Text.RegularExpressions;
using model.Exceptions;
using model.Validators.Interfaces;


namespace model.Validators.ModelValidators
{
    public class AngajatValidator : IValidator<Angajat>
    {
        private static readonly string EMAIL_REGEX =
            @"^[a-zA-Z0-9_+&*-]+(?:\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\.)+[a-zA-Z]{2,7}$";

        private static readonly Regex pattern = new Regex(EMAIL_REGEX);

        public static bool IsValidEmail(string email)
        {
            return pattern.IsMatch(email);
        }

        public void Validate(Angajat entity)
        {
            string errors = "";

            if (string.IsNullOrEmpty(entity.Nume) || entity.Nume.Length <= 2)
            {
                errors += "Name must be at least 2 characters!\n";
            }
            if (string.IsNullOrEmpty(entity.Prenume) || entity.Prenume.Length <= 2)
            {
                errors += "Prenumele must be at least 2 characters!";
            }
            if (!IsValidEmail(entity.Email))
            {
                errors += "Email is not valid!";
            }
            if (entity.Username.Length < 3)
            {
                errors += "Username is not valid! It must be at least 3 characters!";
            }
            if (entity.Password.Length < 3)
            {
                errors += "Password must be at least 2 characters long!";
            }
            if (!string.IsNullOrEmpty(errors))
            {
                throw new ValidatorException(errors);
            }
        }

        public void validate(Angajat entity)
        {
            throw new NotImplementedException();
        }
    }
}