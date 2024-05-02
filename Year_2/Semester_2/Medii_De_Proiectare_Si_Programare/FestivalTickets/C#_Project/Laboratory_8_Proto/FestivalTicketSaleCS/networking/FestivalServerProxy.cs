using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using model;
using networking.dto;
using services.Exceptions;

namespace networking
{
    public class FestivalServerProxy : IFestivalServices
    
    {
        private string host;
        private int port;

        private IFestivalObserver client;

        private NetworkStream stream;
		
        private IFormatter formatter;
        private TcpClient connection;

        private Queue<Response> responses;
        private volatile bool finished;
        private EventWaitHandle _waitHandle;

        public FestivalServerProxy(string host, int port)
        {
            this.host = host;
            this.port = port;
            responses = new Queue<Response>();
        }
        public virtual model.SpectacolDTO[] getSpectacole()
        {
            Console.WriteLine("Proxy : get Spectacole");
            Request request = new GetSpectacoleRequest(DateTime.Now, null, false);
            sendRequest(request);
            Response response = readResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new FestivalException(err.Message);
            }
            GetSpectacoleResponse resp = (GetSpectacoleResponse)response;
            return resp.Spectacole;
        }

        public virtual string[] getArtisti()
        {
            Request request=new GetArtistiRequest();
            sendRequest(request);
            Response response = readResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new FestivalException(err.Message);
            }
            GetArtistiResponse resp = (GetArtistiResponse)response;
            return resp.Artisti;
        }
        private void closeConnection()
        {
            finished=true;
            try
            {
                stream.Close();
			
                connection.Close();
                _waitHandle.Close();
                client=null;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }

        }
        
        private void sendRequest(Request request)
        {
            try
            {
                formatter.Serialize(stream, request);
                Console.WriteLine("Proxy : send req");
                stream.Flush();
            }
            catch (Exception e)
            {
                throw new FestivalException("Error sending object "+e);
            }

        }
        
        
        private Response readResponse()
        {
            Response response =null;
            try
            {
                _waitHandle.WaitOne();
                lock (responses)
                {
                    //Monitor.Wait(responses); 
                    response = responses.Dequeue();
                
                }
				

            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
            return response;
        }
        public virtual model.SpectacolDTO addBilet(string nume_cump, long id_spectacol, int nrLocuri, IFestivalObserver observer)
        {
            Console.WriteLine("Add bilet"+nume_cump+" "+id_spectacol+" "+nrLocuri);
            Request request=new SellTicketRequest(nume_cump,id_spectacol,nrLocuri);
            sendRequest(request);
            Response response = readResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new FestivalException(err.Message);
            }
            OkResponse resp = (OkResponse)response;
            return null;
        }

        public virtual model.Angajat logIn(string username, string password, IFestivalObserver employee)
        {
            initializeConnection();
            Request request=new LogInRequest(new AngajatDTO(username,password));
            sendRequest(request);
            Response response = readResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                closeConnection();
                throw new FestivalException(err.Message);
            }
            UserLoggedInResponse resp = (UserLoggedInResponse)response;
            this.client = employee;
            return resp.Angajat;
        }

        public virtual bool logOut(model.Angajat angajat)
        {
            Request request=new LogOutRequest(DTOUtils.getDTO(angajat));
            sendRequest(request);
            Response response = readResponse();
            closeConnection();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new FestivalException(err.Message);
            }

            return true;
        }

        public virtual model.SpectacolDTO[] filterSpectacole(DateTime date, string Artist, bool filterByDate = false)
        {
            Console.WriteLine("Proxy : get Spectacole filtered");
           Request request= new GetSpectacoleRequest(date,Artist,filterByDate);
            sendRequest(request);
            Response response = readResponse();
            if (response is ErrorResponse)
            {
                ErrorResponse err = (ErrorResponse)response;
                throw new FestivalException(err.Message);
            }
            GetSpectacoleResponse resp = (GetSpectacoleResponse)response;
            return resp.Spectacole;
        }
        private void initializeConnection()
        {
            try
            {
                connection=new TcpClient(host,port);
                stream=connection.GetStream();
                formatter = new BinaryFormatter();
                finished=false;
                _waitHandle = new AutoResetEvent(false);
                startReader();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
        }
        private void startReader()
        {
            Thread tw =new Thread(run);
            tw.Start();
        }
        public virtual void run()
        {
            while(!finished)
            {
                try
                {
                    object response = formatter.Deserialize(stream);
                    Console.WriteLine("response received "+response);
                    if (response is UpdateResponse)
                    {
                        handleUpdate((UpdateResponse)response);
                    }
                    else
                    {
							
                        lock (responses)
                        {
                                					
								 
                            responses.Enqueue((Response)response);
                               
                        }
                        _waitHandle.Set();
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Reading error "+e);
                }
					
            }
        }

        private void handleUpdate(UpdateResponse response)
        {
            if (response is GetSpectacoleResponse)
            {
                Console.WriteLine("Spectacole received");
                GetSpectacoleResponse resp = (GetSpectacoleResponse)response;
                model.SpectacolDTO[] spectacole = resp.Spectacole;
                try
                {
                    client.recievedSpectacole(spectacole);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }
            }
            if ( response is ErrorResponse)
            {
                Console.WriteLine("Error "+ ((ErrorResponse)response).Message);
            }

            if (response is RecievedSpecResponse)
            {
                RecievedSpecResponse resp = (RecievedSpecResponse)response;
                model.SpectacolDTO spectacol = resp.SpectacolDto;
try
                {
                    client.recievedSellingOfTicket(spectacol,Int32.Parse( resp.BiletDto.NumarLocuri),resp.BiletDto.NumeClient);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.StackTrace);
                }
            }
        }
    }
}