// See https://aka.ms/new-console-template for more information

/*
using FestivalTicketSale.Repository.DBRepositories;
using FestivalTicketSale.Repository.Interfaces;
using FestivalTicketSale.Tests;*/
using log4net.Config;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Text;
using FestivalTicketSale.Model;
using FestivalTicketSale.Repository.DBRepositories;
using FestivalTicketSale.Repository.Interfaces;

/*using FestivalTicketSale.Model;*/
namespace FestivalTicketSale
{
    class Program
    {
        static string GetConnectionStringByName(string name)
        {
            // Assume failure.
            string returnValue = null;

            // Look for the name in the connectionStrings section.
            ConnectionStringSettings settings =ConfigurationManager.ConnectionStrings[name];

            // If found, return the connection string.
            if (settings != null)
                returnValue = settings.ConnectionString;

            return returnValue;
        }
        private static readonly log4net.ILog logger = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        static void Main(string[] args)
        {
            string configFilePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "log4net.config");
            FileInfo fileInfo;
            
            
            try
            {
                fileInfo = new System.IO.FileInfo(configFilePath);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
           
           // XmlConfigurator.Configure(fileInfo);
           XmlConfigurator.Configure(new FileInfo("log4net.config"));
            Console.WriteLine("Configuration Settings for tasksDB {0}",GetConnectionStringByName("ticket_sales"));
            
            IDictionary<String, string> props = new SortedList<String, String>();
            props.Add("ConnectionString", GetConnectionStringByName("ticket_sales"));
            Console.WriteLine("Sorting Tasks Repository DB ...");
            IAngajatRepository angajatRepository = new DBAngajatRepository(props);
            IBiletRepository biletRepository = new DBBiletRepository(props);
            ISpectacolRepository spectacolRepository = new DBSpectacolRepository(props);
            var angajati = angajatRepository.FindAll();
            Console.WriteLine("Angajati:");
            foreach (var angajat in angajati)
            {
                Console.WriteLine(angajat);
            }

           // Console.WriteLine(biletRepository.FindAll());
           var spectacole = spectacolRepository.FindAll();
           Console.WriteLine("Spectacole:");
           foreach (var spectacol in spectacole)
           {
               Console.WriteLine(spectacol);
           }

           var artisti = spectacolRepository.GetArtisti();
           Console.WriteLine("Artisti:");
           foreach (var artist in artisti)
           {
               Console.WriteLine(artist);
           }

           Spectacol spectacols = new Spectacol();
           spectacols.Id = 4;

           //biletRepository.Save(new Bilet("heh", "jgg", spectacols, 2));
           logger.Info("Hello logging world");
           
        }
    }
}