using System;
using System.IO;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using model;
using networking.dto;
using services.Exceptions;

namespace networking
{
    public class FestivalClientWorker : IFestivalObserver

    {
        private IFestivalServices server;
        private TcpClient connection;
        private NetworkStream stream;
        private IFormatter formatter;
        private volatile bool connected;

        public FestivalClientWorker(IFestivalServices server, TcpClient connection)
        {
            this.server = server;
            this.connection = connection;
            try
            {
                stream = connection.GetStream();
                formatter = new BinaryFormatter();
                connected = true;
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }

        public virtual void run()
        {
            while (connected)

            {
                try
                {
                    object request = formatter.Deserialize(stream);
                    object response = handleRequest((Request)request);
                    if (response != null)
                    {
                        sendResponse((Response)response);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    ErrorResponse errorResponse = new ErrorResponse(e.Message);
                    sendResponse(errorResponse);
                    //throw;
                }
            }

            try
            {
                Thread.Sleep(1000);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                ErrorResponse errorResponse = new ErrorResponse(e.Message);
                sendResponse(errorResponse);
            }

            try
            {
                stream.Close();
                connection.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                ErrorResponse errorResponse = new ErrorResponse(e.Message);
                sendResponse(errorResponse);
            }
        }

        private Response handleRequest(Request request)
        {
            Response response = null;
            if (request is LogInRequest)
            {
                Console.WriteLine("Login request ...");
                LogInRequest logInRequest = (LogInRequest)request;
                AngajatDTO angajatDto = logInRequest.Angajat;
                try
                {
                    server.logIn(angajatDto.Token, angajatDto.Pass, this);
                    return new UserLoggedInResponse(angajatDto.Token, angajatDto.Pass);
                }
                catch (Exception e)
                {
                    connected = false;
                    return new ErrorResponse(e.Message);
                }
            }
            
            if(request is LogOutRequest)
            {
                Console.WriteLine("Logout request ...");
                LogOutRequest logOutRequest = (LogOutRequest)request;
                model.Angajat angajatDto = DTOUtils.getFromDTO(logOutRequest.Angajat);
                try
                {
                    server.logOut(angajatDto);
                    connected = false;
                    return new OkResponse();
                }
                catch (Exception e)
                {
                    return new ErrorResponse(e.Message);
                }
            }

            if (request is GetSpectacoleRequest)
            {
                Console.WriteLine("GetSpec request ...");
                GetSpectacoleRequest getSpecRequest = (GetSpectacoleRequest)request;
                string artist=getSpecRequest.Artist;
                string data=getSpecRequest.DataSpectacol;
                bool filterByDate = getSpecRequest.FilterByDate;
                DateTime dateTime;
                try
                {
                    dateTime= DateTime.Parse(data);
                }
                catch (Exception e)
                {
                    return new ErrorResponse(e.Message);
                }

                try
                {
                    model.SpectacolDTO[] spectacolDtos;
                    
                        spectacolDtos = server.filterSpectacole(dateTime, artist,filterByDate);
                    
                    return new GetSpectacoleResponse(spectacolDtos);
                }
                catch (FestivalException e)
                {
                    return new ErrorResponse(e.Message);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return new ErrorResponse(e.Message);
                }
            }

            if (request is SellTicketRequest)
            {
                Console.WriteLine("Buy ticket request ...");
                SellTicketRequest sellTicketRequest = (SellTicketRequest)request;
                int nrLocuri = int.Parse(sellTicketRequest.Bilet.NumarLocuri);
                string nume = sellTicketRequest.Bilet.NumeClient;
                long idSpectacol = long.Parse(sellTicketRequest.Bilet.IdSpectacol);
                try
                {
                    Console.WriteLine("Buy ticket request ..." + nume + " " + nrLocuri + " " + idSpectacol);
                    
                        server.addBilet(nume,idSpectacol,nrLocuri,this);
                    
                    return new OkResponse();
                }
                catch (FestivalException e)
                {
                    return new ErrorResponse(e.Message);
                }
            }

            if (request is GetArtistiRequest)
            {
                Console.WriteLine("GetArtists Request ...");
                GetArtistiRequest getArtistiRequest = (GetArtistiRequest)request;
                try
                {
                    string [] artisti=null;
                  
                        artisti = server.getArtisti();
                    
                    return new GetArtistiResponse(artisti);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return new ErrorResponse(e.Message);
                }
            }

            return response;
        }

        private void sendResponse(Response response)
        {
            Console.WriteLine("Preparing to send response: " + response);
            if (!stream.CanWrite)
            {
                Console.WriteLine("Stream is closed or not writable.");
                return;
            }

            try
            {
                lock (stream)
                {
                    formatter.Serialize(stream, response);
                    stream.Flush();
                    Console.WriteLine("Response sent successfully.");
                }
            }
            catch (SerializationException e)
            {
                Console.WriteLine("Failed to serialize response: " + e.Message);
            }
            catch (IOException e)
            {
                Console.WriteLine("IO Exception when sending response: " + e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine("General Exception when sending response: " + e.Message);
            }
        }

        public virtual void recievedSellingOfTicket(model.SpectacolDTO spectacol, int nrLocuri, string nume)
        {
            Response response=new RecievedSpecResponse(spectacol,new BiletDTO(spectacol.Id_spectacol,nume,nrLocuri.ToString()));
            Console.WriteLine("Ticket sold"+spectacol+" "+nrLocuri+" "+nume);
            try
            {
                sendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
        }
        

        public virtual void userLoggedIn(string username, string password)
        {
            Response response=new UserLoggedInResponse(username,password);
            Console.WriteLine("User logged in"+username+" "+password);
            try
            {
                sendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
           
        }

        public virtual void userLoggedOut(string username, string password)
        {
            Response response=new UserLoggedOutResponse(username);
            Console.WriteLine("User logged out"+username+" ");
            try
            {
                sendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
        }

        

        public virtual void recievedSpectacole(model.SpectacolDTO[] spectacole)
        {
            Response response = new OkResponse();
            Console.WriteLine("Spectacole recieved");
            try
            {
                sendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
        }

    }
}