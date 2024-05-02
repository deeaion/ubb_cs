using System;
using System.Collections.Generic;

namespace protobufGRPC.Services.Utils
{

    public class ProtoUtils
    {
        public static LogInResponse CreateLogInResponse(bool success, string token, string error)
        {
            return new LogInResponse
            {
                Success = success,
                Token = token,
                Error = error
            };
        }

        public static Angajat CreateAngajat(model.Angajat angajat)
        {
            string token;
            if (angajat.Email != null && angajat.Email.Length > 0)
            {
                token = angajat.Email;
            }
            else
            {
                token = angajat.Username;
            }

            return new Angajat
            {
                Token = token,
                Password = angajat.Password
            };
        }

        public static SpectacolDTO CreateSpectacolDTOfromSpec(model.Spectacol spectacol)
        {
            return new SpectacolDTO
            {

                Data = spectacol.Data.ToString(),
                NrLocuriVandute = spectacol.NumarLocuriVandute.ToString(),
                NrLocuriDisponibile = spectacol.NumarLocuriDisponibile.ToString(),

                Artist = spectacol.Artist,
                Locatie = spectacol.Locatie,
                IdSpec = spectacol.Id.ToString(),
            };
        }

        public static SpectacolDTO CreateSpectacolDTOfromDTO(model.SpectacolDTO spectacol)
        {
            return new SpectacolDTO
            {
                Data = spectacol.Data,
                NrLocuriVandute = spectacol.NumarLocuriVandute,
                NrLocuriDisponibile = spectacol.NumarLocuriDisponibile,
                Artist = spectacol.Artist,
                Locatie = spectacol.Locatie,
                IdSpec = spectacol.Id_spectacol,
            };
        }

        public static Bilet createBilet(model.Bilet bilet)
        {
            return new Bilet
            {
                NumeCump = bilet.NumeCumparator,
                Serie = bilet.Serie,
                Spectacol = CreateSpectacolDTOfromSpec(bilet.Spectacol),
                NrLocuri = bilet.NrLocuri.ToString()
            };
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

        public static FestivalResponse getSpectacoleDTOss(List<model.Spectacol> spectacole)
        {
            List<SpectacolDTO> spectacoleDTO = new List<SpectacolDTO>();
            foreach (var spectacol in spectacole)
            {
                spectacoleDTO.Add(CreateSpectacolDTOfromSpec(spectacol));
            }

            var response = new FestivalResponse();
            response.Spectacole.AddRange(spectacoleDTO);
            return response;
        }

    }
}