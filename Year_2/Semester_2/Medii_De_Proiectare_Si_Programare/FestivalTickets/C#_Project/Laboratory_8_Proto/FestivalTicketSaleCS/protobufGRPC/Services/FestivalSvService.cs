using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using Grpc.Core;
using model;
using persistance.Interfaces;
using protobufGRPC.Services.Utils;

namespace protobufGRPC.Services
{

    public class FestivalSvService : FestivalSv.FestivalSvBase
    {
        private IAngajatRepository angajatRepository;
        private ISpectacolRepository spectacolRepository;
        private Angajat angajatLogat;
        private IBiletRepository biletRepository;

        private readonly ConcurrentDictionary<string, IServerStreamWriter<FestivalResponse>> userSessions =
            new ConcurrentDictionary<string, IServerStreamWriter<FestivalResponse>>();


        public FestivalSvService(IAngajatRepository angajatRepository, ISpectacolRepository spectacolRepository,
            IBiletRepository biletRepository)
        {
            this.angajatRepository = angajatRepository;
            this.spectacolRepository = spectacolRepository;
            //this.angajatLogat = angajatLogat;
            this.biletRepository = biletRepository;
        }

        public override Task<LogInResponse> login(Angajat request, ServerCallContext context)
        {
            Console.WriteLine("Hello i am herre");
            model.Angajat angajat = angajatRepository.FindByEmail(request.Token);
            if (angajat == null)
            {
                return Task.FromResult(new LogInResponse
                {
                    Success = false,
                    Token = "",
                    Error = "Angajatul nu exista"
                });
            }

            if (angajat.Password != request.Password)
                return Task.FromResult(new LogInResponse
                {
                    Success = false,
                    Token = "",
                    Error = "Parola incorecta!"
                });
            if (userSessions.ContainsKey(request.Token)) // Using context.Peer as a unique identifier for the stream
            {
                return Task.FromResult(new LogInResponse
                {
                    Success = false,
                    Token = "",
                    Error = "User already logged in."
                });
            }

            //inseamna ca e prima oara
            string sessionToken = Guid.NewGuid().ToString();
            return Task.FromResult(new LogInResponse
            {
                Success = true,
                Token = sessionToken,
                Angajat = ProtoUtils.CreateAngajat(angajat),
                Error = ""
            });
        }

        private void RegisterStream(string username, IServerStreamWriter<FestivalResponse> stream)
        {
            userSessions[username] = stream;
        }

        private void UnregisterStream(string username)
        {
            userSessions.TryRemove(username, out _);
        }

        public override Task<FestivalResponse> logout(Angajat request, ServerCallContext context)
        {
            if (userSessions.TryRemove(request.Token, out _))
            {
                return Task.FromResult(new FestivalResponse
                {
                    ResponseType = FestivalResponse.Types.ResponseType.UserLoggedOut
                });
            }

            return Task.FromResult(new FestivalResponse
            {
                ResponseType = FestivalResponse.Types.ResponseType.Error,
                Error = "Not logged in or already logged out."
            });
        }

        public override async Task<FestivalResponse> sellTicket(Bilet request, ServerCallContext context)
        {
            try
            {
                model.Spectacol spectacol = spectacolRepository.FindOne(Convert.ToInt64(request.Spectacol.IdSpec));

                if (spectacol == null)
                {
                    return new FestivalResponse
                    {
                        ResponseType = FestivalResponse.Types.ResponseType.Error,
                        Error = "Spectacol inexistent!"
                    };
                }

                spectacol.NumarLocuriVandute = spectacol.NumarLocuriVandute + Convert.ToInt32(request.NrLocuri);
                spectacol.NumarLocuriDisponibile = spectacol.NumarLocuriDisponibile - Convert.ToInt32(request.NrLocuri);
                spectacolRepository.Update(spectacol.Id, spectacol);
                model.Bilet bilet =
                    new model.Bilet(request.NumeCump, "dummy", spectacol, Convert.ToInt32(request.NrLocuri));
                model.Bilet biletWithId = biletRepository.Save(bilet);
                string series = GenerateSeries(biletWithId.Id, request.NumeCump, spectacol.Data, spectacol.Id);
                biletWithId.Serie = series;
                biletRepository.Update(biletWithId.Id, biletWithId);
                SpectacolDTO spectacolDto = ProtoUtils.CreateSpectacolDTOfromSpec(spectacol);
                await BroadcastTicketSaleUpdate(spectacolDto);
                return new FestivalResponse
                {
                    ResponseType = FestivalResponse.Types.ResponseType.Ok,
                    Message = "Ticket sold successfully"
                };
            }
            catch (Exception e)
            {
                return new FestivalResponse
                {
                    ResponseType = FestivalResponse.Types.ResponseType.Error,
                    Error = e.Message
                };
            }
        }

        private async Task BroadcastTicketSaleUpdate(SpectacolDTO spectacolDto)
        {
            var update = new FestivalResponse
            {
                ResponseType = FestivalResponse.Types.ResponseType.GotFestivalUpdated,

            };

            foreach (var stream in userSessions.Values)
            {
                await stream.WriteAsync(update);
            }
        }


        public override Task<FestivalResponse> getSpectacole(SpectacolDTO request, ServerCallContext context)
        {
            List<model.Spectacol> spectacole = (List<model.Spectacol>)spectacolRepository.FindAll();
            return Task.FromResult(ProtoUtils.getSpectacoleDTOss(spectacole));
        }

        public override Task<FestivalResponse> getArtisti(FestivalRequest request, ServerCallContext context)
        {
            List<string> artisti = (List<string>)spectacolRepository.GetArtisti();
            artisti.Add("None");
            var resp = new FestivalResponse();
            resp.Artist.AddRange(artisti);
            return Task.FromResult(resp);
        }

        public override async Task NotifyStream(IAsyncStreamReader<StreamRequest> requestStream,
            IServerStreamWriter<FestivalResponse> responseStream, ServerCallContext context)
        {
            string token = ""; // We'll obtain this from the client's first message
            if (await requestStream.MoveNext())
            {
                token = requestStream.Current.Token;
                if (ValidateToken(token))
                {
                    // Assume token is valid, and now we're keeping the connection open
                    while (await requestStream.MoveNext()) // Wait for messages, simulating a keep-alive
                    {
                        // For demo, you can send updates periodically or on certain triggers
                        await responseStream.WriteAsync(new FestivalResponse { Message = "Update or Notification" });
                    }
                }
            }
        }

        private bool ValidateToken(string token)
        {
            return true;
        }

        private model.SpectacolDTO convertSpectacolToDTO(model.Spectacol spectacol)
        {
            return new model.SpectacolDTO(spectacol.Locatie, spectacol.Id.ToString(), spectacol.Data.ToString(),
                spectacol.NumarLocuriDisponibile.ToString(), spectacol.NumarLocuriVandute.ToString(), spectacol.Artist);
        }

        private model.Spectacol convertDTOToSpectacol(model.SpectacolDTO spectacolDTO)
        {
            return new model.Spectacol(spectacolDTO.Locatie, DateTime.Parse(spectacolDTO.Data),
                Int32.Parse(spectacolDTO.NumarLocuriDisponibile), Int32.Parse(spectacolDTO.NumarLocuriVandute),
                spectacolDTO.Artist);
        }

        private string GetInitials(string buyer)
        {
            if (string.IsNullOrWhiteSpace(buyer))
            {
                throw new ArgumentException("Buyer cannot be null or whitespace", nameof(buyer));
            }

            string[] names = buyer.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            StringBuilder initials = new StringBuilder();
            foreach (string name in names)
            {
                initials.Append(name[0]);
            }

            return initials.ToString();
        }

        private int GetNumberOfDigits(long number)
        {
            int count = 0;
            while (number > 0)
            {
                number /= 10;
                count++;
            }

            return count;
        }

        private string GetNumberAsString(long number)
        {
            int nrDigits = GetNumberOfDigits(number);
            StringBuilder nr = new StringBuilder();
            for (int i = 0; i < 4 - nrDigits; i++)
            {
                nr.Append("0");
            }

            nr.Append(number.ToString());
            return nr.ToString();
        }

        private string GenerateSeries(long id, string buyer, DateTime date, long id_spectacol)
        {
            StringBuilder series = new StringBuilder("XY");
            series.Append(id_spectacol.ToString());
            series.Append(GetInitials(buyer));
            series.Append(GetNumberAsString(id));
            series.Append(date.Day.ToString());
            series.Append(date.Month.ToString());
            return series.ToString();
        }
    }
}
