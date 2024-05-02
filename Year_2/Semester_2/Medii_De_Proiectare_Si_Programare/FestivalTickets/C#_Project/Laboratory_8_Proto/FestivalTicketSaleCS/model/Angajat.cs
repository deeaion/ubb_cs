using System;

namespace model
{[Serializable]
    public class Angajat : Entity<long>
    {
        public Angajat(string nume, string prenume, string email, string username, string password)
        {
            Nume = nume;
            Prenume = prenume;
            Email = email;
            Username = username;
            this.Password = password;
        }

        public Angajat(string username, string password)
        {
            this.Username=username;
            this.Email = username;
            this.Password=password;
        }

        public Angajat()
        {
            Nume = "";
            Prenume = "";
            Email = "";
            Username = "";
            Password = "";
        }

        public string Nume { get; set; }
        public string Prenume { get; set; }
        public string Email { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }

        public override string ToString()
        {
            return Id + "," + Nume + "," + Prenume + "," + Username;
        }
    }
}