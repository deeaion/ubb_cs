using System;
using FestivalTicketSale.Model;
using FestivalTicketSale.Model.Exceptions;
using FestivalTicketSale.Model.Validators.ModelValidators;

namespace FestivalTicketSale.Tests
{
    public class FestivalTestsSimple
    {
        public static void TestAll()
        {
            try
            {
                TestAngajat();
                Console.WriteLine("Test Angajat ran successfully!");
                TestSpectacol();
                Console.WriteLine("Test Spectacol ran successfully!");

                TestAngajatValidator();
                Console.WriteLine("Test AngajatValidator ran successfully!");

                TestSpectacolValidator();
                Console.WriteLine("Test SpectacolValidator ran successfully!");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
           

        }
        static void TestAngajat()
        {
            Angajat angajat1 = new Angajat();
            
            if (angajat1.Email != "")
            {
                throw new Exception("Email should be empty.");
            }
            if (angajat1.Nume != "")
            {
                throw new Exception("Nume should be empty.");
            }

            Angajat angajat2 = new Angajat("Nume", "Prenume", "Email", "Username", "Pass");
            if (angajat2.Nume != "Nume")
            {
                throw new Exception("Nume should be 'Nume'.");
            }
            if (angajat2.Password != "Pass")
            {
                throw new Exception("Password should be 'Pass'.");
            }
        }

        static void TestSpectacol()
        {
            Spectacol spectacol = new Spectacol();
            if (spectacol.Data.Year != 2000)
            {
                throw new Exception("Data year should be 2000.");
            }
            if (spectacol.Locatie != "")
            {
                throw new Exception("Locatie should be empty.");
            }

            Spectacol spectacol2 = new Spectacol("", new DateTime(2000, 11, 11), 12, 11, "Chris");
            if (spectacol2.Locatie != "")
            {
                throw new Exception("Locatie should be empty.");
            }
            if (spectacol2.Artist != "Chris")
            {
                throw new Exception("Artist should be 'Chris'.");
            }
        }

        static void TestAngajatValidator()
        {
            Angajat angajat = new Angajat("Ana", "Clara", "ana@clara.com", "ana", "hey");
            AngajatValidator angajatValidator = new AngajatValidator();
            angajatValidator.Validate(angajat);
            angajat.Nume = "";
            try
            {
                angajatValidator.Validate(angajat);
            }
            catch (ValidatorException exception)
            {
                if (exception.Message != "Name must be at least 2 characters!\n")
                {
                    throw new Exception("Unexpected exception message.");
                }
            }
        }

        static void TestSpectacolValidator()
        {
            Spectacol spectacol2 = new Spectacol("Asda", new DateTime(2023, 11, 11), 12, 11, "Chris");
            SpectacolValidator validator = new SpectacolValidator();
            validator.Validate(spectacol2);
            spectacol2.Locatie = "";
            try
            {
                validator.Validate(spectacol2);
            }
            catch (ValidatorException validatorException)
            {
                if (validatorException.Message != "Locatia cannot be empty!\n")
                {
                    throw new Exception("Unexpected exception message.");
                }
            }
        }
    }
}
