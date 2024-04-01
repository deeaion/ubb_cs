/*using System.ComponentModel;
using FestivalTicketSale.Model;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FestivalTicketSale.Tests
{
    [TestClass]
    public class FestivalTests
    {

        [TestMethod]
        [DisplayName("AngajatTests")]
        public void TestAngajat()
        {
            Angajat angajat1 = new Angajat();
            Assert.AreEqual("", angajat1.Email);
            Assert.AreEqual("", angajat1.Nume);
            Angajat angajat2 = new Angajat("Nume", "Prenume", "Email", "Username", "Pass");
            Assert.AreEqual("Nume", angajat2.Nume);
            Assert.AreEqual("Pass", angajat2.Password);
        }

        [TestMethod]
        [DisplayName("SpectacolTests")]
        public void TestSpectacol()
        {
            Spectacol spectacol = new Spectacol();
            Assert.AreEqual(2000, spectacol.Data.Year);
            Assert.AreEqual("", spectacol.Locatie);
            Spectacol spectacol2 = new Spectacol("", new DateTime(2000,11,11), 12, 11, "Chris");
            Assert.AreEqual("", spectacol2.Locatie);
            Assert.AreEqual("Chris", spectacol2.Artist);
        }
    }
    
}*/