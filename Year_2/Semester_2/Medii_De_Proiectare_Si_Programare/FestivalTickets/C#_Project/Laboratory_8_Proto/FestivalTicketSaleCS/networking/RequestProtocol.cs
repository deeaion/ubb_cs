using System;
using model;
using networking.dto;

namespace networking
{
    public interface Request
    {
    }
    [Serializable]
    public class LogInRequest : Request
    {
        private AngajatDTO _angajat;

        public LogInRequest(AngajatDTO angajat)
        {
            _angajat = angajat;
        }

        public virtual AngajatDTO Angajat
        {
            get { return _angajat; }
        }

    }

    [Serializable]
    public class LogOutRequest : Request
    {
        private AngajatDTO _angajat;

        public LogOutRequest(AngajatDTO angajat)
        {
            _angajat = angajat;
        }

        public virtual AngajatDTO Angajat
        {
            get { return _angajat; }
        }
    }

    [Serializable]
    public class SellTicketRequest : Request
    {
        private BiletDTO _bilet;

        public SellTicketRequest(string numeCump,long id_Spectacol,int nrLocuri)
        {
            _bilet=new BiletDTO(id_Spectacol.ToString(),numeCump,nrLocuri.ToString());
        }

        public virtual BiletDTO Bilet
        {
            get { return _bilet; }
        }
    }

    [Serializable]
    public class GetArtistiRequest : Request
    {
        public GetArtistiRequest()
        {
        }
    }

    [Serializable]
    public class GetSpectacoleRequest : Request
    {
        public string Artist { get; set; }
        public string DataSpectacol { get; set; }
        public bool FilterByDate { get; set; }
        public GetSpectacoleRequest(DateTime dateTime,string artist,bool filterByDate=false)
        {
            this.Artist=artist;
            this.DataSpectacol = dateTime.ToString();
            this.FilterByDate = filterByDate;
        }
        
    }
    
}