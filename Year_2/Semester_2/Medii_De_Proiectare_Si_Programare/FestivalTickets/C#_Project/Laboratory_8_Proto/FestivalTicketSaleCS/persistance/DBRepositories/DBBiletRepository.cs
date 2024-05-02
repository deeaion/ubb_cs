using System;
using System.Collections.Generic;
using System.Data;

using log4net;
using model;
using persistance.Exceptions;
using persistance.Interfaces;

namespace persistance.DBRepositories
{
    public class DBBiletRepository : IBiletRepository
    {
        private static readonly ILog log =
            LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

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

        private Spectacol getSpectacolFromResultSet(IDataReader resultSet)
        {
            long id_spectacol = resultSet.GetInt64(0);
            string locatie = resultSet.GetString(1);
            DateTime data = new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc);
            ;
            try
            {
                long unixTimeStamp = resultSet.GetInt64(2);
                data = DateTimeOffset.FromUnixTimeMilliseconds(unixTimeStamp).UtcDateTime;

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

        public Bilet Save(Bilet entity)
        {
            log.InfoFormat("Entering saving task {0}", entity);
            var con = DBUtils.getConnection(props);

            if (entity == null)
            {
                String m = "Cannot save angajat if entity is null!\n";
                log.InfoFormat("Sent error from repo {0}", m);
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

            }

            con = DBUtils.getConnection(props);
            long id = 0;
            using (var com = con.CreateCommand())
            {
                com.CommandText = "select max(id_bilet) as max from Bilet";
                using (var reader = com.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        id = reader.GetInt64(0);
                        entity.Id = id;
                        return entity;
                    }

                }
            }

            return entity;


        }

        private Bilet GetBiletFromDataReader(IDataReader reader)
        {
            long id_bilet = reader.GetInt64(reader.GetOrdinal("id_bilet"));
            string nume_cump = reader.GetString(reader.GetOrdinal("nume_cumparator_bilet"));
            Spectacol spectacol = getSpectacolFromResultSet(reader);
            int nr_locuri_bilet = reader.GetInt32(reader.GetOrdinal("nr_locuri_bilet"));
            string serie = reader.GetString(reader.GetOrdinal("serie_bilet"));
            Bilet bilet = new Bilet(nume_cump, serie, spectacol, nr_locuri_bilet);
            bilet.Id = id_bilet;
            return bilet;
        }

        public Bilet Delete(long id)
        {
            throw new NotImplementedException();
        }

        public Bilet Update(long id, Bilet entity)
        {
            log.InfoFormat("Entering saving task {0}", entity);
            var con = DBUtils.getConnection(props);
            if (entity == null)
            {
                String m = "Cannot update bilet if entity is null!\n";
                log.InfoFormat("Sent error from repo {0}", m);
                throw new RepositoryException(m);

            }

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "update Bilet set serie_bilet= @serie where id_bilet= @id";
                var paramBilet = comm.CreateParameter();
                paramBilet.ParameterName = "@serie";
                paramBilet.Value = entity.Serie;
                comm.Parameters.Add(paramBilet);


                IDbDataParameter paramID = comm.CreateParameter();
                paramID.ParameterName = "@id";
                paramID.Value = entity.Id;
                comm.Parameters.Add(paramID);

                var result = comm.ExecuteNonQuery();
                if (result == 0)
                    throw new RepositoryException("No task added !");
                return entity;
            }
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
}


