using System;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Threading;
using Google.Protobuf;
using services.Exceptions;

namespace networking
{
    public class FestivalClientProtoWorker : IFestivalObserver
    {
        private IFestivalServices server;
        private TcpClient connection;
        private NetworkStream stream;
        private IFormatter formatter;
        private volatile bool connected;
        public FestivalClientProtoWorker(IFestivalServices server,TcpClient connection)
        {
            this.server = server;
            this.connection = connection;
            try
            {
                stream = connection.GetStream();
                connected=true;
            }
            catch (System.Exception e)
            {
                System.Console.WriteLine(e);
            }
        }
        public virtual void run()
        {
            while (connected)
            {
                try
                {
                    FestivalRequest request = FestivalRequest.Parser.ParseDelimitedFrom(stream);
                    FestivalResponse response = HandleRequest(request);
                    if (response != null)
                    {
                        SendResponse(response);
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }

                try
                {
                    Thread.Sleep(1000);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }
            }
            try
            {
                stream.Close();
                connection.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Error " + e);
            }
        }

        private void SendResponse(FestivalResponse response)
        {
            Console.WriteLine("Sending response " + response);
            lock (stream)
            {
                response.WriteDelimitedTo(stream);
                stream.Flush();
            }
            Console.WriteLine("Sent");
        }

        private FestivalResponse HandleRequest(FestivalRequest request)
        {
            FestivalResponse response = null;
            if (request.RequestType==FestivalRequest.Types.RequestType.Login)
            {
                Console.WriteLine("Login request ...");

                Angajat angajatDto = request.Angajat;
                try
                {
                    server.logIn(angajatDto.Token, angajatDto.Password, this);
                    return ProtoUtils.createUserLoggedInResponse(angajatDto);
                }
                catch (Exception e)
                {
                    connected = false;
                    return ProtoUtils.createErrorResponse(e.Message);
                }
            }
            
            if(request.RequestType==FestivalRequest.Types.RequestType.Logout)
            {
                Console.WriteLine("Logout request ...");
                Angajat angajatDto = request.Angajat;
                try
                {
                    server.logOut(ProtoUtils.createAngajatFromProto(angajatDto));
                    connected = false;
                    return ProtoUtils.createUserLoggedOutResponse(angajatDto.Token);
                }
                catch (Exception e)
                {
                    return ProtoUtils.createErrorResponse(e.Message);
                }
            }


            if (request.RequestType == FestivalRequest.Types.RequestType.GetSpectacole)
            {
                Console.WriteLine("GetSpec request ...");
                string artist = null;
                string data = null;
                bool filterByDate = false;
                DateTime dateTime = DateTime.Now;

                if (request.Spectacol != null)
                {
                    Console.WriteLine("GetSpec request ..." + request.Spectacol.Artist + " " + request.Spectacol.Data);
                    artist = request.Spectacol.Artist;
                     data = request.Spectacol.Data;
                     filterByDate = request.FilteredByDate;
                     if (filterByDate == true)
                     {
                         try
                         {
                             dateTime = DateTime.Parse(data);
                         }
                         catch (Exception e)
                         {
                             return ProtoUtils.createErrorResponse(e.Message);
                         }
                     }
                     
                }
            
            else
            {
                Console.WriteLine("GetSpec request ...null");
            }

            try
            {
                model.SpectacolDTO[] spectacole;
                    
                    if(request.Spectacol!=null)
                        spectacole = server.filterSpectacole(dateTime, artist, filterByDate);
                    else
                    {
                        spectacole = server.filterSpectacole(dateTime, null, false);
                    }
                    return ProtoUtils.createGetSpectacoleResponse(spectacole);
                }
                catch (Exception e)
                {
                    return ProtoUtils.createErrorResponse(e.Message);
                }
            }

            if (request.RequestType == FestivalRequest.Types.RequestType.SellTicket)
            {
                Console.WriteLine("Buy ticket request ...");
                int nrLocuri = int.Parse(request.Bilet.NrLocuri);
                string nume = request.Bilet.NumeCump;
                long idSpectacol = long.Parse(request.Bilet.Spectacol.IdSpec);
                try
                {
                    Console.WriteLine("Buy ticket request ..." + nume + " " + nrLocuri + " " + idSpectacol);
                    
                        server.addBilet(nume,idSpectacol,nrLocuri,this);
                    
                    return ProtoUtils.createOkResponse();
                }
                catch (FestivalException e)
                {
                    return ProtoUtils.createErrorResponse(e.Message);
                }
            }

            if (request.RequestType == FestivalRequest.Types.RequestType.GetArtisti)
            {
                Console.WriteLine("GetArtists Request ...");
                try
                {
                    string [] artisti=null;
                  
                        artisti = server.getArtisti();
                    
                    return ProtoUtils.crateGetArtistiResponse(artisti);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e);
                    return ProtoUtils.createErrorResponse(e.Message);
                }
            }

            return response;
        }

        public void recievedSellingOfTicket(model.SpectacolDTO spectacol, int nrLocuri, string nume)
        {
            FestivalResponse response=ProtoUtils.createRecievedSpecResponse(spectacol,nrLocuri,nume);
            Console.WriteLine("Ticket sold"+spectacol+" "+nrLocuri+" "+nume);
            try
            {
                SendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
        }

        public void userLoggedIn(string username, string password)
        {
            Angajat angajat = new Angajat();
            angajat.Token = username;
            angajat.Password = password;
            FestivalResponse response=ProtoUtils.createUserLoggedInResponse(angajat);
            Console.WriteLine("User logged in"+username+" "+password);
            try
            {
                SendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
        }

        public void userLoggedOut(string username, string password)
        {
            FestivalResponse response=ProtoUtils.createUserLoggedOutResponse(username);
            
            Console.WriteLine("User logged out"+username+" ");
            try
            {
                SendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
        }

        public void recievedSpectacole(model.SpectacolDTO[] spectacole)
        {
            FestivalResponse response = ProtoUtils.createOkResponse();
            Console.WriteLine("Spectacole recieved");
            try
            {
                SendResponse(response);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                return;
            }
        }
    }
}