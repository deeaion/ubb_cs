using System;
using System.Collections.Generic;
using System.Configuration;
using System.Net.Sockets;
using System.Threading;
using networking;
using persistance.DBRepositories;
using persistance.Interfaces;
using services.Exceptions;

namespace Server
{
     public class StartProtoServer
    {
        private static int DEFAULT_PORT = 55555;
        private static String DEFAULT_IP = "127.0.0.1";
        
        public static void Main(string[] args)
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
            IFestivalServices services =
                new FestivalServerImplementation(angajatRepository, spectacolRepository, biletRepository);
            Console.WriteLine("Starting server on IP {0} and port {1}", ip, port);
            ProtoServer server = new ProtoServer(ip, port, services);

            server.Start();
            Console.WriteLine("Server started ...");
            //Console.WriteLine("Press <enter> to exit...");
            Console.ReadLine();

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

        public class SerialChatServer : ConcurrentServer
        {
            private IFestivalServices server;
            private FestivalClientWorker worker;

            public SerialChatServer(string host, int port, IFestivalServices server) : base(host, port)
            {
                this.server = server;
                Console.WriteLine("SerialChatServer...");
            }

            protected override Thread createWorker(TcpClient client)
            {
                worker = new FestivalClientWorker(server, client);
                return new Thread(new ThreadStart(worker.run));
            }
        }
        public class ProtoServer : ConcurrentServer
        {
            private IFestivalServices server;
            private FestivalClientProtoWorker worker;
            public ProtoServer(string host, int port, IFestivalServices server) : base(host, port)
            {
                this.server = server;
                Console.WriteLine("ProtoChatServer...");
            }
            protected override Thread createWorker(TcpClient client)
            {
                worker = new FestivalClientProtoWorker(server, client);
                return new Thread(new ThreadStart(worker.run));
            }
        }
        static void ConnectToServer()
        {
            var client = new TcpClient("127.0.0.1", 55599);

        }
        
    }
}
