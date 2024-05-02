using System;
using model;
using networking.dto;

namespace networking
{
   public interface Response
   {

   }
   
   public interface UpdateResponse : Response
   {
   }

   [Serializable]
   public class OkResponse : Response
   {

   }

   [Serializable]
   public class ErrorResponse : Response
   {
      private string message;

      public ErrorResponse(string message)
      {
         this.message = message;
      }

      public virtual string Message
      {
         get { return message; }
      }
   }

   [Serializable]
   public class GetArtistiResponse : Response
   {
      private string[] artisti;

      public GetArtistiResponse(string[] artisti)
      {
         this.artisti = artisti;
      }

      public virtual string[] Artisti
      {
         get { return artisti; }
      }
      
   }

   [Serializable]
   public class RecievedSpecResponse : UpdateResponse
   {
      private model.SpectacolDTO _spectacolDto;
      private BiletDTO _biletDto;

      public RecievedSpecResponse(model.SpectacolDTO spectacolDto, BiletDTO biletDto)
      {
         _spectacolDto = spectacolDto;
         _biletDto = biletDto;
      }

      public virtual model.SpectacolDTO SpectacolDto
      {
         get { return _spectacolDto; }
      }

      public virtual BiletDTO BiletDto
      {
         get { return _biletDto; }
      }
   }

   [Serializable]
   public class UserLoggedInResponse : Response
   {
      private AngajatDTO _angajatDTO;
      private model.Angajat _angajat;

      public UserLoggedInResponse(string username, string password)
      {
         _angajatDTO = new AngajatDTO(username, password);
         _angajat = new model.Angajat(username, password);
      }

      public virtual AngajatDTO AngajatDTO
      {
         get { return _angajatDTO; }
      }

      public virtual model.Angajat Angajat
      {
         get { return _angajat; }
      }
   }
   [Serializable]
   public class UserLoggedOutResponse : Response
      {
         private AngajatDTO _angajatDto;

         public UserLoggedOutResponse(string username)
         {
            this._angajatDto = new AngajatDTO(username, "");
         }
      }
   [Serializable]
      public class GetSpectacoleResponse : Response
      {
         private model.SpectacolDTO[] _spectacole;

         public GetSpectacoleResponse(model.SpectacolDTO[] spectacole)
         {
            _spectacole = spectacole;
         }

         public virtual model.SpectacolDTO[] Spectacole
         {
            get { return _spectacole; }

         }
      }

   
}