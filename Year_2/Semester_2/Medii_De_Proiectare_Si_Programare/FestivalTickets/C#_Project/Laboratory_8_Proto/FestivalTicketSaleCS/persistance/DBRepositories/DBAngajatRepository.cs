using System.Data;
using System;

using log4net;

using System.Collections.Generic;
using model;
using persistance.Exceptions;
using persistance.Interfaces;

namespace persistance.DBRepositories
{
    public class DBAngajatRepository : IAngajatRepository
    {
        private static readonly ILog log =
            LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        IDictionary<String, string> props;

        public DBAngajatRepository(IDictionary<string, string> props)
        {
            log.Info("Creating DBAngajatRepository");
            this.props = props;

        }

        private Angajat getAngajatFromResultSet(IDataReader dataR)
        {
            long id_angajat = dataR.GetInt64(0);
            string nume_angajat = dataR.GetString(1);
            string prenume_angajat = dataR.GetString(2);
            string username_angajat = dataR.GetString(4);
            string email_angajat = dataR.GetString(3);
            string password = dataR.GetString(5);
            Angajat angajat = new Angajat(nume_angajat, prenume_angajat, email_angajat, username_angajat, password);
            angajat.Id = id_angajat;
            return angajat;
        }


        public IEnumerable<Angajat> FindAll()
        {
            log.InfoFormat("Entering findAll");
            IDbConnection con = DBUtils.getConnection(props);
            IList<Angajat> angajatList = new List<Angajat>();
            using (var comm = con.CreateCommand())
            {
                comm.CommandText =
                    "SELECT id_angajat, nume_angajat, prenume_angajat, email_angajat,username,password from Angajat";
                using (var dataR = comm.ExecuteReader())
                {
                    while (dataR.Read())
                    {
                        Angajat angajat = getAngajatFromResultSet(dataR);
                        angajatList.Add(angajat);
                    }
                }
            }

            log.InfoFormat("Exiting Find All!");
            return angajatList;
        }

        public Angajat FindOne(long id)
        {
            log.InfoFormat("Entering findAll");
            IDbConnection con = DBUtils.getConnection(props);
            if (id == null)
            {
                throw new RepositoryException("Cannot find an Angajat if id is null!");
            }

            Angajat angajat = null;

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "SELECT id_angajat, nume_angajat, " +
                                   "prenume_angajat, email_angajat," +
                                   "username_angajat,password from Angajat" +
                                   "where id_angajat=@id";
                IDbDataParameter paramId = comm.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                comm.Parameters.Add(paramId);
                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        angajat = getAngajatFromResultSet(dataR);
                        log.InfoFormat("Exiting findOne with value {0}", angajat);
                        return angajat;
                    }
                }
            }

            return angajat;
        }

        public Angajat Save(Angajat entity)
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
                comm.CommandText =
                    "insert into Angajat (prenume_angajat,nume_angajat,email_angajat,username,password) " +
                    "VALUES (@prenumeAng,@numeAng,@emailAng,@usernameAng,@passwordAng)";
                var paramId = comm.CreateParameter();
                paramId.ParameterName = "@prenumeAng";
                paramId.Value = entity.Prenume;
                comm.Parameters.Add(paramId);

                var paramDesc = comm.CreateParameter();
                paramDesc.ParameterName = "@numeAng";
                paramDesc.Value = entity.Nume;
                comm.Parameters.Add(paramDesc);

                var paramElems = comm.CreateParameter();
                paramElems.ParameterName = "@emailAng";
                paramElems.Value = entity.Email;
                comm.Parameters.Add(paramElems);

                IDbDataParameter paramOrder = comm.CreateParameter();
                paramOrder.ParameterName = "@usernameAng";
                paramOrder.Value = entity.Username;
                comm.Parameters.Add(paramOrder);

                IDbDataParameter paramAlgo = comm.CreateParameter();
                paramAlgo.ParameterName = "@passwordAng";
                paramAlgo.Value = entity.Password;
                comm.Parameters.Add(paramAlgo);

                var result = comm.ExecuteNonQuery();
                if (result == 0)
                    throw new RepositoryException("No task added !");
                return entity;
            }

            return null;
        }

        public Angajat Delete(long id)
        {
            throw new NotImplementedException();
        }

        public Angajat Update(long id, Angajat entity)
        {
            throw new NotImplementedException();
        }

        public Angajat FindByEmail(string email)
        {
            log.InfoFormat("Entering find one by email");
            IDbConnection con = DBUtils.getConnection(props);
            if (email == null)
            {
                throw new RepositoryException("Cannot find an Angajat if email is null!");
            }

            Angajat angajat = null;

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "SELECT id_angajat, nume_angajat, " +
                                   "prenume_angajat, email_angajat," +
                                   "username, password from Angajat where email_angajat = @emailAng ;";
                IDbDataParameter paramId = comm.CreateParameter();
                paramId.ParameterName = "@emailAng";
                paramId.Value = email;
                comm.Parameters.Add(paramId);
                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        angajat = getAngajatFromResultSet(dataR);
                        log.InfoFormat("Exiting findOne with value {0}", angajat);
                        return angajat;
                    }
                }
            }

            return angajat;
        }

        public Angajat FindByUsername(string username)
        {
            log.InfoFormat("Entering find one by username");
            IDbConnection con = DBUtils.getConnection(props);
            if (username == null)
            {
                throw new RepositoryException("Cannot find an Angajat if username is null!");
            }

            Angajat angajat = null;

            using (var comm = con.CreateCommand())
            {
                comm.CommandText = "SELECT id_angajat, nume_angajat, " +
                                   "prenume_angajat, email_angajat," +
                                   "username,password from Angajat " +
                                   "where username= @usernameAng";
                IDbDataParameter paramId = comm.CreateParameter();
                paramId.ParameterName = "@usernameAng";
                paramId.Value = username;
                comm.Parameters.Add(paramId);
                using (var dataR = comm.ExecuteReader())
                {
                    if (dataR.Read())
                    {
                        angajat = getAngajatFromResultSet(dataR);
                        log.InfoFormat("Exiting findOne with value {0}", angajat);
                        return angajat;
                    }
                }
            }

            return angajat;
        }
    }
}