using System;
using System.Collections.Generic;
using System.Data;

using log4net;
using model;
using model.Validators.ModelValidators;
using persistance.Exceptions;
using persistance.Interfaces;

namespace persistance.DBRepositories
{
    public class DBSpectacolRepository : ISpectacolRepository
{
    private static readonly ILog log = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

    IDictionary<String, string> props;
    private static SpectacolValidator SpectacolValidator;

    public DBSpectacolRepository(IDictionary<string, string> props)
    {
        log.Info("Creating DBSpectacolRepository");
        this.props = props;
        SpectacolValidator = new SpectacolValidator();
        
    } 
    private Spectacol getSpectacolFromResultSet(IDataReader resultSet) {
        long id_spectacol = resultSet.GetInt64(0);
        string locatie = resultSet.GetString(1);
        DateTime data=new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc);;
        try
        {
            long unixTimeStamp = resultSet.GetInt64(2);
            data= DateTimeOffset.FromUnixTimeMilliseconds(unixTimeStamp).UtcDateTime;

        }
        catch (Exception ex)
        {
            // Handle any potential exceptions, such as format exceptions or invalid data
            Console.WriteLine("Error converting Unix timestamp to DateTime: " + ex.Message);
            // Provide a default value or handle the error as appropriate for your application
            data = DateTime.MinValue;
        }
        
        int nr_locuri_disp = resultSet.GetInt32(3);
        int nr_locuri_vandute = resultSet.GetInt32(4);
        string artist = resultSet.GetString(5);
        Spectacol spectacol = new Spectacol(locatie, data, nr_locuri_disp, nr_locuri_vandute, artist);
        spectacol.Id = id_spectacol;
        return spectacol;
    }

    public IEnumerable<Spectacol> FindAll()
    {
        log.InfoFormat("Entering findAll");
        IDbConnection con = DBUtils.getConnection(props);
        IList<Spectacol> spectacols = new List<Spectacol>();
        using (var comm=con.CreateCommand())
        {
            comm.CommandText = "SELECT id_spectacol,locatie_spectacol,data_spectacol," +
                               "nr_locuri_disponibile_spectacol,nr_locuri_vandute_spectacol,"+
                               "artist from Spectacol";
            using(var dataR=comm.ExecuteReader())
            {
                while(dataR.Read())
                {
                    Spectacol spectacol = getSpectacolFromResultSet(dataR);
                    spectacols.Add(spectacol);
                }
            }
        }
        log.InfoFormat("Exiting Find All!");
        return spectacols;
    }

    public Spectacol FindOne(long id)
    {
        log.InfoFormat("Entering findOne spectacol by id");
        IDbConnection con = DBUtils.getConnection(props);
        if(id==null)
        {
            throw new RepositoryException("Cannot find a Spectacol if id is null!");
        }
        Spectacol spectacol=null;

        using (var comm=con.CreateCommand())
        {
            comm.CommandText = "SELECT id_spectacol,locatie_spectacol,data_spectacol," +
                               "nr_locuri_disponibile_spectacol,nr_locuri_vandute_spectacol," +
                               "artist " + "from Spectacol where id_spectacol = @id";
            IDbDataParameter paramId = comm.CreateParameter();
            paramId.ParameterName = "@id";
            paramId.Value = id;
            comm.Parameters.Add(paramId);
            using(var dataR=comm.ExecuteReader())
            {
                if(dataR.Read())
                {
                    spectacol = getSpectacolFromResultSet(dataR);
                    log.InfoFormat("Exiting findOne with value {0}",spectacol);
                    return spectacol;
                }
            }
        }

        return spectacol;
    }

    public Spectacol Save(Spectacol entity)
    {
        log.InfoFormat("Entering saving task {0}",entity);
        var con = DBUtils.getConnection(props);
        SpectacolValidator.Validate(entity);
        if(entity==null)
        {
            String m="Cannot save angajat if entity is null!\n";
            log.InfoFormat("Sent error from repo {0}",m);
            throw new RepositoryException(m);

        }
        

        using (var comm = con.CreateCommand())
        {
            comm.CommandText = "insert into Spectacol (locatie_spectacol,data_spectacol," +
                               "nr_locuri_disponibile_spectacol," +
                               "nr_locuri_vandute_spectacol,artist) " +
                               "VALUES (@locatieSpect,@dataSpect,@locDispSpec,@locVandSpec,@ArtistSpec)";
            var paramLocatie = comm.CreateParameter();
            paramLocatie.ParameterName = "@locatieSpect";
            paramLocatie.Value = entity.Locatie;
            comm.Parameters.Add(paramLocatie);

            var paramData = comm.CreateParameter();
            DateTime data = entity.Data; // Example DateTime object
            long unixTimestamp = (long)data.Subtract(new DateTime(1970, 1, 1,0,0,0,0)).TotalMilliseconds;
            paramData.ParameterName = "@dataSpect";
            paramData.Value = unixTimestamp;
            comm.Parameters.Add(paramData);

            var paramLocDisp = comm.CreateParameter();
            paramLocDisp.ParameterName = "@locDispSpec";
            paramLocDisp.Value = entity.NumarLocuriDisponibile;
            comm.Parameters.Add(paramLocDisp);

            IDbDataParameter paramlocVand = comm.CreateParameter();
            paramlocVand.ParameterName = "@locVandSpec";
            paramlocVand.Value = entity.NumarLocuriVandute;
            comm.Parameters.Add(paramlocVand);

            IDbDataParameter paramArtist = comm.CreateParameter();
            paramArtist .ParameterName = "@ArtistSpec";
            paramArtist .Value = entity.Artist;
            comm.Parameters.Add(paramArtist );

            var result = comm.ExecuteNonQuery();
            if (result == 0)
                throw new RepositoryException("No task added !");
            return entity;
        }

        return null;
    }

    public Spectacol Delete(long id)
    {
        throw new NotImplementedException();
    }

    public Spectacol Update(long id, Spectacol entity)
    {
        log.InfoFormat("Entering saving task {0}",entity);
        var con = DBUtils.getConnection(props);
        SpectacolValidator.Validate(entity);

        if(entity==null)
        {
            String m="Cannot save angajat if entity is null!\n";
            log.InfoFormat("Sent error from repo {0}",m);
            throw new RepositoryException(m);

        }
        

        using (var comm = con.CreateCommand())
        {
            comm.CommandText = "update Spectacol set locatie_spectacol=@locatieSpect, data_spectacol=@dataSpect," +
                               " nr_locuri_disponibile_spectacol=@locDispSpec, nr_locuri_vandute_spectacol=@locVandSpec," +
                               "artist=@ArtistSpec where id_spectacol=@id";

            var paramLocatie = comm.CreateParameter();
            paramLocatie.ParameterName = "@locatieSpect";
            paramLocatie.Value = entity.Locatie;
            comm.Parameters.Add(paramLocatie);

            var paramData = comm.CreateParameter();
            DateTime data = entity.Data; // Example DateTime object
            long unixTimestamp = (long)data.Subtract(new DateTime(1970, 1, 1,0,0,0,0)).TotalMilliseconds;
            paramData.ParameterName = "@dataSpect";
            paramData.Value = unixTimestamp;
            comm.Parameters.Add(paramData);

            var paramLocDisp = comm.CreateParameter();
            paramLocDisp.ParameterName = "@locDispSpec";
            paramLocDisp.Value = entity.NumarLocuriDisponibile;
            comm.Parameters.Add(paramLocDisp);

            IDbDataParameter paramlocVand = comm.CreateParameter();
            paramlocVand.ParameterName = "@locVandSpec";
            paramlocVand.Value = entity.NumarLocuriVandute;
            comm.Parameters.Add(paramlocVand);

            IDbDataParameter paramArtist = comm.CreateParameter();
            paramArtist .ParameterName = "@ArtistSpec";
            paramArtist .Value = entity.Artist;
            comm.Parameters.Add(paramArtist );
            IDbDataParameter paramID = comm.CreateParameter();
            paramID.ParameterName = "@id";
            paramID.Value = entity.Id;
            comm.Parameters.Add(paramID);

            var result = comm.ExecuteNonQuery();
            if (result == 0)
                throw new RepositoryException("No task added !");
            return entity;
        }

        return null;
    }

    public IEnumerable<Spectacol> FindByArtist(string artist)
    {
        log.InfoFormat("Entering findAll");
        IDbConnection con = DBUtils.getConnection(props);
        IList<Spectacol> spectacols = new List<Spectacol>();
        using (var comm=con.CreateCommand())
        {
            comm.CommandText = "SELECT id_spectacol,locatie_spectacol,data_spectacol," +
                               "nr_locuri_disponibile_spectacol,nr_locuri_vandute_spectacol,"+
                               "artist from Spectacol where artist=@artist";
            IDbDataParameter paramArtist = comm.CreateParameter();
            paramArtist.ParameterName = "@artist";
            paramArtist.Value = artist;
            comm.Parameters.Add(paramArtist);
            using(var dataR=comm.ExecuteReader())
            {
                while(dataR.Read())
                {
                    Spectacol spectacol = getSpectacolFromResultSet(dataR);
                    spectacols.Add(spectacol);
                }
            }
        }
        log.InfoFormat("Exiting Find By Artist!");
        return spectacols;
    }

    public IEnumerable<Spectacol> FindByDate(DateTime date)
    {
        
        log.InfoFormat("Entering findAll");
        IDbConnection con = DBUtils.getConnection(props);
        IList<Spectacol> spectacols = new List<Spectacol>();
        using (var comm=con.CreateCommand())
        {
            string query = "SELECT * FROM Spectacol WHERE data_spectacol >= @startDate AND data_spectacol < @endDate";
            comm.CommandText = query;
            
            DateTime startOfDa = new DateTime(date.Year, date.Month, date.Day, 0, 0, 0, DateTimeKind.Utc);
            long startDate = (long)(startOfDa - new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc)).TotalMilliseconds;

// Convert to end of day timestamp
            DateTime endOfDa = startOfDa.AddDays(1);
            long endDate = (long)(endOfDa - new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc)).TotalMilliseconds;

            var paramData = comm.CreateParameter();
            paramData.ParameterName = "@startDate";
            paramData.Value = startDate;
            comm.Parameters.Add(paramData);
            var paramDataEnd = comm.CreateParameter();
            paramDataEnd.ParameterName = "@endDate";
            paramDataEnd.Value = endDate;
            comm.Parameters.Add(paramDataEnd);
            using(var dataR=comm.ExecuteReader())
            {
                while(dataR.Read())
                {
                    Spectacol spectacol = getSpectacolFromResultSet(dataR);
                    spectacols.Add(spectacol);
                }
            }
        }
        log.InfoFormat("Exiting Find By Artist!");
        return spectacols;
    }

    public IEnumerable<string> GetArtisti()
    {
        log.InfoFormat("Entering findAll");
        IDbConnection con = DBUtils.getConnection(props);
        IList<string> artisti = new List<string>();
        using (var comm=con.CreateCommand())
        {
            comm.CommandText = "SELECT  DISTINCT  Artist from Spectacol";
            using(var dataR=comm.ExecuteReader())
            {
                while(dataR.Read())
                {
                    string artist = dataR.GetString(0);
                    artisti.Add(artist);
                }
            }
        }
        log.InfoFormat("Exiting Find All!");
        return artisti;
    }

    public IEnumerable<Spectacol> FindByDateandArtist(string artist, DateTime date)
    {
        log.InfoFormat("Entering findAll");
        IDbConnection con = DBUtils.getConnection(props);
        IList<Spectacol> spectacols = new List<Spectacol>();
        using (var comm=con.CreateCommand())
        {
            comm.CommandText = "SELECT id_spectacol , locatie_spectacol, data_spectacol, " +
                               "nr_locuri_disponibile_spectacol ,nr_locuri_vandute_spectacol,"+
                               "artist from Spectacol WHERE data_spectacol >= @startDate AND data_spectacol < @endDate and artist=@artist";
            DateTime startOfDa = new DateTime(date.Year, date.Month, date.Day, 0, 0, 0, DateTimeKind.Utc);
            long startDate = (long)(startOfDa - new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc)).TotalMilliseconds;

// Convert to end of day timestamp
            DateTime endOfDa = startOfDa.AddDays(1);
            long endDate = (long)(endOfDa - new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc)).TotalMilliseconds;

            var paramData = comm.CreateParameter();
            paramData.ParameterName = "@startDate";
            paramData.Value = startDate;
            comm.Parameters.Add(paramData);
            var paramDataEnd = comm.CreateParameter();
            paramDataEnd.ParameterName = "@endDate";
            paramDataEnd.Value = endDate;
            comm.Parameters.Add(paramDataEnd);
            var paramArtist = comm.CreateParameter();
            paramArtist.ParameterName = "@artist";
            paramArtist.Value = artist;
            comm.Parameters.Add(paramArtist);
            using(var dataR=comm.ExecuteReader())
            {
                while(dataR.Read())
                {
                    Spectacol spectacol = getSpectacolFromResultSet(dataR);
                    spectacols.Add(spectacol);
                }
            }
        }
        log.InfoFormat("Exiting Find By Artist!");
        return spectacols;
    }
}
}

