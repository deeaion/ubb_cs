using System.Data;
using FestivalTicketSale.Model;
using FestivalTicketSale.Repository.Exceptions;
using FestivalTicketSale.Repository.Interfaces;
using log4net;
namespace FestivalTicketSale.Repository.DBRepositories;

public class DBBiletRepository : IBiletRepository
{
    private static readonly ILog log = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

    IDictionary<String, string> props;

    public DBBiletRepository(IDictionary<string, string> props)
    {
        log.Info("Creating DBSpectacolRepository");
        this.props = props;
        
    } 
    public IEnumerable<Bilet> FindAll()
    {
        throw new NotImplementedException();
    }

    public Bilet FindOne(long id)
    {
        throw new NotImplementedException();
    }

    public Bilet Save(Bilet entity)
    {
        log.InfoFormat("Entering saving task {0}",entity);
        var con = DBUtils.getConnection(props);
        if(entity==null)
        {
            String m="Cannot save angajat if entity is null!\n";
            log.InfoFormat("Sent error from repo {0}",m);
            throw new RepositoryException(m);

        }
        

        using (var comm = con.CreateCommand())
        {
            comm.CommandText = "insert into Bilet (nume_cumparator_bilet,id_spectacol," +
                               "nr_locuri_bilet," +
                               "serie_bilet) " +
                               "VALUES (@numeCump,@idSpectacol,@NrLocuri,@serie_bilet)";
            var paramNume = comm.CreateParameter();
            paramNume.ParameterName = "@numeCump";
            paramNume.Value = entity.NumeCumparator;
            comm.Parameters.Add(paramNume);
            
            var paramSpectacol = comm.CreateParameter();
            paramSpectacol.ParameterName = "@idSpectacol";
            paramSpectacol.Value = entity.Spectacol.Id;
            comm.Parameters.Add(paramSpectacol);
           
            var paramNr = comm.CreateParameter();
            paramNr.ParameterName = "@NrLocuri";
            paramNr.Value = entity.NrLocuri;
            comm.Parameters.Add(paramNr);
            
            var paramSerie = comm.CreateParameter();
            paramSerie.ParameterName = "@serie_bilet";
            paramSerie.Value = entity.Serie;
            comm.Parameters.Add(paramSerie);

            var result = comm.ExecuteNonQuery();
            if (result == 0)
                throw new RepositoryException("No task added !");
            return entity;
        }

        return null;
    }

    public Bilet Delete(long id)
    {
        throw new NotImplementedException();
    }

    public Bilet Update(Bilet entity)
    {
        throw new NotImplementedException();
    }

    public IEnumerable<Bilet> FindBySpectacol(Spectacol spectacol)
    {
        throw new NotImplementedException();
    }

    public IEnumerable<Bilet> FindByName(string name)
    {
        throw new NotImplementedException();
    }

    public Bilet FindBySeries(string series)
    {
        throw new NotImplementedException();
    }
}