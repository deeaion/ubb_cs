/*using System;
using FestivalTicketSale.Model.Exceptions;
using FestivalTicketSale.Model.Validators.Enums;
using FestivalTicketSale.Model.Validators.Interfaces;
using FestivalTicketSale.Model.Validators.ModelValidators;

namespace FestivalTicketSale.Model.Validators
{
    public class ValidatorFactory : IFactory<TE>
    {
        private static ValidatorFactory instance;

        public static ValidatorFactory GetInstance()
        {/*#1#
            if (instance == null)
            {
                instance = new ValidatorFactory();
            }
            return instance;
        }

        public IValidator CreateValidator(ValidatorStrategy validatorStrategy)
        {
            switch (validatorStrategy)
            {
                case ValidatorStrategy.Angajat:
                    return new AngajatValidator();
                case ValidatorStrategy.Spectacol:
                    return new SpectacolValidator();
                default:
                    throw new ValidatorException("Invalid strategy for creating the validator!");
            }
        }
    }
}*/