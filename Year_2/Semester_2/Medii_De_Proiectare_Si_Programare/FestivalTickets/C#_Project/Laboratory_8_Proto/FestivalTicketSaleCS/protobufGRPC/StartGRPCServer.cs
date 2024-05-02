using System;
using System.Collections.Generic;
using System.Configuration;
using persistance.DBRepositories;
using persistance.Interfaces;
using protobufGRPC.Services;
using System.Configuration;
using Grpc.Core;


namespace protobufGRPC
{

    public class StartGRPCServer
    {
        private static int DEFAULT_PORT = 55556;
        private static String DEFAULT_IP = "127.0.0.1";

        static void Main(string[] args)
        {

            // IUserRepository userRepo = new UserRepositoryMock();
            Console.WriteLine("Reading properties from app.config ...");
            int port = DEFAULT_PORT;
            String ip = DEFAULT_IP;
            String portS = ConfigurationManager.AppSettings["port"];
            if (portS == null)
            {
                Console.WriteLine("Port property not set. Using default value " + DEFAULT_PORT);
            }
            else
            {
                bool result = Int32.TryParse(portS, out port);
                if (!result)
                {
                    Console.WriteLine("Port property not a number. Using default value " + DEFAULT_PORT);
                    port = DEFAULT_PORT;
                    Console.WriteLine("Portul " + port);
                }
            }

            String ipS = ConfigurationManager.AppSettings["ip"];

            if (ipS == null)
            {
                Console.WriteLine("Port property not set. Using default value " + DEFAULT_IP);
            }

            Console.WriteLine("Configuration Settings for database {0}", GetConnectionStringByName("chatDB"));
            IDictionary<String, string> props = new SortedList<String, String>();
            props.Add("ConnectionString", GetConnectionStringByName("ticket_sales"));
            IAngajatRepository angajatRepository = new DBAngajatRepository(props);
            ISpectacolRepository spectacolRepository = new DBSpectacolRepository(props);
            IBiletRepository biletRepository = new DBBiletRepository(props);
            FestivalSvService services =
                new FestivalSvService(angajatRepository, spectacolRepository, biletRepository);
            Console.WriteLine("Starting server on IP {0} and port {1}", ip, port);
            Console.WriteLine("Server started ...");
            //Console.WriteLine("Press <enter> to exit...");
            // Set up the server and start it
            var server = new Server
            {
                Services = { FestivalSv.BindService(services) },
                Ports = { new ServerPort("localhost", 55556, ServerCredentials.Insecure) }
            };
            server.Services.Add(FestivalSv.BindService(services));
            server.Start();

            Console.WriteLine($"Server started on IP {ip} and port {port}.");
            Console.WriteLine("Press any key to stop the server...");

            Console.ReadKey(); // This should be after server.Start()

            server.ShutdownAsync().Wait();

        }

        private static string GetConnectionStringByName(string chatdb)
        {
            string returnValue = null;

            // Look for the name in the connectionStrings section.
            ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings[chatdb];

            // If found, return the connection string.
            if (settings != null)
                returnValue = settings.ConnectionString;

            return returnValue;
        }


    }
}