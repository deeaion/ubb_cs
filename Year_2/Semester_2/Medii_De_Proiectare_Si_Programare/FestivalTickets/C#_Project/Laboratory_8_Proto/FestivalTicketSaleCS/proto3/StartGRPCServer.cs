/*using System;
using System.Collections.Generic;
using System.Configuration;
using persistance.DBRepositories;
using persistance.Interfaces;
using System.Configuration;
using Grpc.Core;
using Microsoft.Extensions.DependencyInjection.Extensions;
using proto3;
using proto3.Services;


namespace protobufGRPC
{

    public class StartGRPCServer
    {
        private static int DEFAULT_PORT = 55556;
        private static String DEFAULT_IP = "127.0.0.1";
        public static IHostBuilder CreateHostBuilder(string[] args) =>
            Host.CreateDefaultBuilder(args)
                .ConfigureWebHostDefaults(webBuilder =>
                {
                    webBuilder.ConfigureServices((context, services) =>
                    {
                        // Add gRPC services here
                        services.AddGrpc(options => options.EnableDetailedErrors = true);

                        // Example: Adding a singleton service for configuration settings
                        var databaseSettings = context.Configuration.GetSection("DatabaseSettings").Get<DatabaseSettings>();
                        services.AddSingleton(databaseSettings);

                        // Register repositories
                        services.AddSingleton<IAngajatRepository, DBAngajatRepository>();
                        services.AddSingleton<ISpectacolRepository, DBSpectacolRepository>();
                        services.AddSingleton<IBiletRepository, DBBiletRepository>();

                        // Register the gRPC service implementation
                        services.AddGrpcService<FestivalSvService>();
                    });

                    webBuilder.Configure(app =>
                    {
                        // Configure the HTTP request pipeline.
                        app.UseRouting();

                        app.UseEndpoints(endpoints =>
                        {
                            // Map gRPC services within the application's request pipeline.
                            endpoints.MapGrpcService<FestivalSvService>();
                        });
                    });
                });
    }
}

        static void Main(string[] args)
        {

            CreateHostBuilder(args).Build().Run();
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
            //ConnectionStringSettings settings = ConfigurationManager.ConnectionStrings[chatdb];

            // If found, return the connection string.
           //

            return "Data Source=C:\\Users\\Deea\\Desktop\\Uni\\By Year\\mpp-C#\\FestivalTicketSaleCS\\ticket_sales.db;Version=3;";
        }


    }
}*/