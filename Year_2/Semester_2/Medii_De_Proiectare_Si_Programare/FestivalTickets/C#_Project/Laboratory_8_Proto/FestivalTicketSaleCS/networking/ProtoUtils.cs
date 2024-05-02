using System;
using System.Collections.Generic;

namespace networking
{
    public class ProtoUtils
    {
        public static FestivalRequest createFilterRequest(string artist,DateTime data)
        {
            String date= data.ToString("yyyy-MM-dd");
            SpectacolDTO spectacolDto = new SpectacolDTO();
            spectacolDto.Artist = artist;
            spectacolDto.Data = date;
            FestivalRequest request = new FestivalRequest();
            request.RequestType = FestivalRequest.Types.RequestType.GetSpectacole;
            request.Spectacol= spectacolDto;
            return request;
            
        }

        public static SpectacolDTO getSpectacolDTOfromSpectDTOModel(model.SpectacolDTO spectacolDto)
        {
            SpectacolDTO spectacol = new SpectacolDTO();
            spectacol.Artist = spectacolDto.Artist;
            spectacol.Data = spectacolDto.Data;
            spectacol.NrLocuriDisponibile = spectacolDto.NumarLocuriDisponibile;
            spectacol.NrLocuriVandute = spectacolDto.NumarLocuriVandute;
            spectacol.Locatie = spectacolDto.Locatie;
            return spectacol;
        }
        public static Bilet setBilet(String nume, int nrLocuri, String numeSpectacol,String idSpectacol)
        {
            Bilet bilet = new Bilet();
            bilet.NumeCump = nume;
            bilet.NrLocuri = nrLocuri.ToString();
            bilet.Spectacol = new SpectacolDTO();
            bilet.Spectacol.IdSpec= idSpectacol;
            return bilet;
        }
        public static FestivalResponse createRecievedSpecResponse(model.SpectacolDTO spectacolDto, int nrLocuri, String nume)
        {
            FestivalResponse response = new FestivalResponse();
            response.ResponseType = FestivalResponse.Types.ResponseType.GotFestivalUpdated;
            SpectacolDTO spectacol = getSpectacolDTOfromSpectDTOModel(spectacolDto);
            response.Spectacol = spectacol;
            response.Bilet = setBilet(nume, nrLocuri, nume, spectacolDto.Id_spectacol);
            return response;
        }

        public static FestivalResponse createUserLoggedOutResponse(String username)
        {
            FestivalResponse response = new FestivalResponse();
            response.ResponseType = FestivalResponse.Types.ResponseType.UserLoggedOut;
            Angajat angajat = new Angajat();
            angajat.Token = username;
            response.Angajat = angajat;
            return response;
        }

        public static model.Angajat createAngajatFromProto(Angajat angajat)
        {
            return new model.Angajat(angajat.Token, angajat.Password);
        }
        public static FestivalResponse createUserLoggedInResponse(Angajat angajat)
        {
            FestivalResponse response = new FestivalResponse();
            response.ResponseType = FestivalResponse.Types.ResponseType.UserLoggedIn;
            Angajat ang = new Angajat();
            ang.Token = angajat.Token;
            ang.Password = angajat.Password;
            response.Angajat = ang;
            return response;
        }

        public static FestivalResponse createGetSpectacoleResponse(model.SpectacolDTO[] spectacole)
        {
            List<SpectacolDTO> spectacoleList = new List<SpectacolDTO>();
            foreach (var spectacol in spectacole)
            {
                SpectacolDTO spectacolDto = new SpectacolDTO();
                spectacolDto.Artist = spectacol.Artist;
                spectacolDto.Data = spectacol.Data;
                spectacolDto.Locatie = spectacol.Locatie;
                spectacolDto.NrLocuriDisponibile = spectacol.NumarLocuriDisponibile;
                spectacolDto.NrLocuriVandute = spectacol.NumarLocuriVandute;
                spectacolDto.IdSpec = spectacol.Id_spectacol;
                spectacoleList.Add(spectacolDto);
            }
            FestivalResponse response = new FestivalResponse();
            response.ResponseType = FestivalResponse.Types.ResponseType.GetFestivalList;
            response.Spectacole.AddRange(spectacoleList);
            return response;
            
        }
        
        public static FestivalResponse createErrorResponse(String text)
        {
            FestivalResponse response = new FestivalResponse();
            response.ResponseType = FestivalResponse.Types.ResponseType.Error;
            response.Error = text;
            return response;
        }
        public static FestivalResponse createOkResponse()
        {
            FestivalResponse response = new FestivalResponse();
            response.ResponseType = FestivalResponse.Types.ResponseType.Ok;
            return response;
        }

        public static FestivalResponse crateGetArtistiResponse(string[] artisti)
        {
            FestivalResponse response = new FestivalResponse();
            response.ResponseType = FestivalResponse.Types.ResponseType.GetArtisti;
            response.Artist.AddRange(artisti);
            return response;
        }
    }
}