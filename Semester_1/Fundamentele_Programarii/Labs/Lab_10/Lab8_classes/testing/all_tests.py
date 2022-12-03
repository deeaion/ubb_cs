from unittest import TestCase

from Persistent_Memory.file_repo_client import FileRepoClients
from Persistent_Memory.file_repo_movie import FileRepoMovie
from Persistent_Memory.file_repo_rentals import FileRepoRentals
from Persistent_Memory.repo_client import RepoClient
from Persistent_Memory.repo_movie import RepoMovie
from Persistent_Memory.repo_rentals import RepoRentals
from business.service_clients import ServiceClients
from business.service_movies import ServiceMovies
from business.service_rentals import ServiceRentals
from domain.DTO_file_rentals import Rental_DTO_file
from domain.DTO_most_rents import Most_Rents_DTO
from domain.domain_client import Client
from domain.domain_movie import Movie
from domain.domain_rentals import Rental
from errors.repo_error import RepoError
from validation.validate_client import ValidatingClient
from validation.validate_movie import ValidatingMovie
from validation.validate_rentals import ValidatingRentals


class Teste(TestCase):
    def remove_all(self,path):
        with open(path,"w"):
            pass
    #DOMAIN#
    def test_domain(self):
        ##client##
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        self.assertEqual(client.get_id_client(),id)
        self.assertEqual(client.get_CNP_client(),CNP)
        self.assertEqual(client.get_name_client(),name)

        ##movie##

        id_m=12
        name_m="A movie"
        genre="romance"
        description=" a description "
        movie= Movie(id_m, name,genre,description)
        self.assertEqual(movie.get_id_movie(),id_m)
        self.assertEqual(movie.get_name_movie(),name)
        self.assertEqual(movie.get_genre_movie(),genre)
        self.assertEqual(movie.get_description_movie(),description)
        self.assertEqual(movie,movie)
        ##domain rentals##
        id_rental=11
        rental_time=21
        rental=Rental(id_rental,client,movie,rental_time)
        self.assertEqual(rental.get_id_rental(), id_rental)
        self.assertEqual(rental.get_movie(), movie)
        self.assertEqual(rental.get_client(), client)
        self.assertEqual(rental.get_days_rental(), rental_time)
        self.assertEqual(rental,rental)
        ##domain DTO##
        number_of_r=2312
        dto=Most_Rents_DTO(id,name_m,number_of_r)
        self.assertEqual(dto.get_id_client(),id)

        self.assertEqual(dto.get_movie_name(),name_m)
        self.assertEqual(dto.get_number_of_rentals(),number_of_r)
        ###validator##
        #VAL#
    def test_val_c(self):
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        val=ValidatingClient()
        val.validate(client)
        try:
            val.validate(Client(-5,"",""))
            assert False
        except ValueError as ve:
            pass
    def test_val_m(self):
        id_m = 12
        name_m = "A movie"
        genre = "romance"
        description = " a description "
        movie = Movie(id_m, name_m, genre, description)
        val=ValidatingMovie()
        try:
            val.validate(Movie(-1,"","",""))
            assert False
        except ValueError:
            pass
    def test_val_r(self):
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        id_m = 12
        name_m = "A movie"
        genre = "romance"
        description = " a description "
        movie = Movie(id_m, name_m, genre, description)
        id_rental = 11
        rental_time = 21
        rental = Rental(id_rental, client, movie, rental_time)
        val = ValidatingRentals()
        try:
            val.validate(Rental(-6, client, movie, -21))
            assert False
        except ValueError:
            pass
        val.validate(rental)

        #repo_test#
        #repo c#
        #TESTE REPOS#
    def test_add_c(self):
        ##client_repo###
        rtc=RepoClient()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        assert(rtc.len())==0
        #add
        rtc.add_client(client)
        assert(rtc.len())==1
        try:
            rtc.add_client(client)
            assert False
        except RepoError:
            pass
    def test_modify_c(self):
        rtc=RepoClient()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        assert (rtc.len()) == 0
        try:
            rtc.modify_client(client)
            assert False
        except RepoError:
            pass
        rtc.add_client(client)
        assert (rtc.len()) == 1
        name_n="i am mod"
        CNP_n="1880918378050"
        client_n=Client(id,name_n,CNP_n)
        rtc.modify_client(client_n)
        assert rtc.search_client_by_id(id).get_id_client() == id
        assert rtc.search_client_by_id(id).get_CNP_client() == CNP_n
        assert rtc.search_client_by_id(id).get_name_client() == name_n
    def test_search_c(self):
        rtc = RepoClient()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        try:
            rtc.search_client_by_id(id)
            assert False
        except RepoError:
            pass
        rtc.add_client(client)
        assert(client==rtc.search_client_by_id(id))
    def test_delete_c(self):
        ##client_repo###
        rtc=RepoClient()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        assert(rtc.len())==0
        #add
        rtc.add_client(client)
        assert(rtc.len())==1
        try:
            rtc.delete_client_by_id(12)
            assert False
        except RepoError:
            pass
        rtc.delete_client_by_id(id)
        assert(rtc.len())==0
        #repo_f_c#
        #repo__m#
    def test_add_m(self):
        rtm = RepoMovie()
        id = 25
        name = "Do I work"
        genre="romance"
        description="uuuuh"
        movie = Movie(id, name, genre,description)
        assert (rtm.len()) == 0
        # add
        rtm.add_movie(movie)
        assert (rtm.len()) == 1
        try:
            rtm.add_movie(movie)
            assert False
        except RepoError:
            pass
    def test_modify_movie(self):
        rtm = RepoMovie()
        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        assert (rtm.len()) == 0
        # add

        try:
            rtm.modify_movie(movie)
            assert False
        except RepoError:
            pass
        rtm.add_movie(movie)
        assert (rtm.len()) == 1
        name_n = "i am mod"
        genre_n="heh"
        description_n="dfdfdfdfdfdfdfdfdf"
        movie_n=Movie(id,name_n,genre_n,description_n)
        rtm.modify_movie(movie_n)
        assert rtm.search_movie_by_id(id).get_id_movie() == id
        assert rtm.search_movie_by_id(id).get_name_movie() == name_n
        assert rtm.search_movie_by_id(id).get_genre_movie() ==genre_n
        assert rtm.search_movie_by_id(id).get_description_movie()==description_n
    def test_search_movie(self):
        rtm = RepoMovie()
        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        assert (rtm.len()) == 0
        try:
            rtm.search_movie_by_id(id)
            assert False
        except RepoError:
            pass
        rtm.add_movie(movie)
        assert movie==rtm.search_movie_by_id(id)
    def test_delete_testsm(self):
        rtm = RepoMovie()
        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        assert (rtm.len()) == 0
        try:
            rtm.delete_movie_by_id(id)
            assert False
        except RepoError:
            pass
        rtm.add_movie(movie)
        assert (rtm.len()) == 1
        rtm.delete_movie_by_id(id)
        assert (rtm.len()) == 0
        #repof_m#
    def test_rentals(self):
        cale_movies=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        cale_rentals=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_rentals.txt"
        cale_clients=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
        rtm =FileRepoMovie(cale_movies)
        rtc =FileRepoClients(cale_clients)
        rtr=RepoRentals(cale_rentals)
        rf=FileRepoRentals(cale_rentals)
        self.remove_all(cale_movies)
        self.remove_all(cale_rentals)
        self.remove_all(cale_clients)
        id = 25
        name = "Do jI work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        rtm.add_movie(movie)
        rtc.add_client(client)
        ###RENTALS####
        id_rental=2
        days=3
        rental=Rental(id_rental,client,movie,days)
        dto=Rental_DTO_file(id_rental,id,id,days)
        assert (rtr.len()) == 0
        rtr.add_rental(rental,dto)
        assert (rtr.len()) == 1
        self.assertEqual(rf.len(),1)
        try:
            rtr.add_rental(rental,dto)
            assert False
        except RepoError:
            pass
        try:
            rtr.search_rental_by_id(25)
            assert False
        except RepoError:
            pass
        assert(rental==rtr.search_rental_by_id(id_rental))
        rtr.delete_rental_by_id(id_rental)
        assert (rtr.len())==0
        assert (rf.len(),0)
        try:
            rtr.delete_rental_by_id(id_rental)
            assert False
        except RepoError:
            pass
    def test_files_clients(self):
            cale_clients_n = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
            self.remove_all(cale_clients_n)
            rtc =FileRepoClients(cale_clients_n)
            id = 25
            name = "Do I work"
            CNP = "2880918378050"
            client = Client(id, name, CNP)
            self.assertEqual(rtc.len(),0)
            rtc.add_client(client)
            self.assertEqual(rtc.len(),1)
            name_n="I have been modified"
            CNP_n= "1234567891011"
            client_n=Client(id,name_n,CNP_n)
            rtc.modify_client(client_n)
            self.assertEqual(rtc.search_client_by_id(id).get_id_client(),id)
            self.assertEqual(rtc.search_client_by_id(id).get_name_client(), name_n)
            self.assertEqual(rtc.search_client_by_id(id).get_CNP_client(), CNP_n)
            rtc.delete_client_by_id(id)
            self.assertEqual(rtc.len(),0)
    def test_movies_files(self):
        cale_movies = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        rtm = FileRepoMovie(cale_movies)
        self.remove_all(cale_movies)
        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        self.assertEqual(rtm.len(),0)
        rtm.add_movie(movie)
        self.assertEqual(rtm.len(),1)
        name_n = "i am mod"
        genre_n = "heh"
        description_n = "dfdfdfdfdfdfdfdfdf"
        movie_n = Movie(id, name_n, genre_n, description_n)
        rtm.modify_movie(movie_n)
        assert rtm.search_movie_by_id(id).get_id_movie() == id
        assert rtm.search_movie_by_id(id).get_name_movie() == name_n
        assert rtm.search_movie_by_id(id).get_genre_movie() == genre_n
        assert rtm.search_movie_by_id(id).get_description_movie() == description_n

        #SERVICE REPOS#

#SERVICE

    def test_service_clients(self):
        cale_c=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
        rtc = FileRepoClients(cale_c)
        self.remove_all(cale_c)
        vtc = ValidatingClient()
        stc = ServiceClients(vtc, rtc)
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        st = stc.add_client(id, name, CNP)
        assert st.get_id_client() == id
        assert st.get_name_client() == name
        assert st.get_CNP_client() == CNP
        try:
            stc.add_client(-5,"","2")
            assert False
        except ValueError as ve:
            pass
        #search
        try:
            stc.search_client_by_id(1)
            assert False
        except RepoError:
            pass
        try:
            stc.add_client(id, name, CNP)
            assert False
        except RepoError as ve:
            pass
        s_f = stc.search_client_by_id(id)
        assert st == s_f
        self.assertEqual(stc.len(),1)
        rtc.delete_client_by_id(id)
        self.assertEqual(stc.len(),0)
        # linked to serv_m

    def test_movie(self):
        cale_m = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        rtm = FileRepoMovie(cale_m)
        self.remove_all(cale_m)
        vtm = ValidatingMovie()
        stm = ServiceMovies(vtm, rtm)
        id = 25
        name = "Do I work"
        genre = "romance"
        description = "i exist man"
        st = stm.add_movie(id, name, genre, description)
        assert st.get_id_movie() == id
        assert st.get_name_movie() == name
        assert st.get_genre_movie() == genre
        assert st.get_description_movie() == description
        try:
            stm.add_movie(-5, "", "","")
            assert False
        except ValueError as ve:
            pass
        # search
        try:
            stm.search_movie_by_id(1)
            assert False
        except RepoError:
            pass
        try:
            stm.add_movie(id, name, genre, description)
            assert False
        except RepoError as ve:
            pass
        s_f = stm.search_movie_by_id(id)
        assert st == s_f
        self.assertEqual(stm.len(), 1)

    def test_rentals_service(self):
        cale_movies = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        cale_rentals = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_rentals.txt"
        cale_clients = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
        rtm = FileRepoMovie(cale_movies)
        rtc = FileRepoClients(cale_clients)
        rtr = RepoRentals(cale_rentals)
        rf = FileRepoRentals(cale_rentals)
        self.remove_all(cale_movies)
        self.remove_all(cale_rentals)
        self.remove_all(cale_clients)
        vtm = ValidatingMovie()
        stm = ServiceMovies(vtm, rtm)
        vtc = ValidatingClient()
        stc = ServiceClients(vtc, rtc)
        vtr = ValidatingRentals()
        str = ServiceRentals(vtr, rtr, rtc, rtm, vtc, vtm,rf)
        client = stc.random_client_generator()
        id_m = 25
        name_m = "Do I work"
        genre_m = "romance"
        description_m = "i exist man"
        movie = stm.add_movie(id_m, name_m, genre_m, description_m)
        idr = 21
        d = 23
        rental = str.add_rental(idr, client.get_id_client(), movie.get_id_movie(), d)
        assert rental.get_id_rental() == idr
        assert rental.get_days_rental() == d
        assert rental.get_movie() == movie
        assert rental.get_client() == client
        try:
            str.search_rental(5)
            assert False
        except RepoError:
            pass
        str.delete_rental(idr)
        try:
            str.search_rental(idr)
        except RepoError:
            pass
        self.assertEqual(str.len(),0)

    def test_delc(self):
        cale_movies = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        cale_rentals = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_rentals.txt"
        cale_clients = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
        rtm = FileRepoMovie(cale_movies)
        rtc = FileRepoClients(cale_clients)
        rtr = RepoRentals(cale_rentals)
        rf = FileRepoRentals(cale_rentals)
        self.remove_all(cale_movies)
        self.remove_all(cale_rentals)
        self.remove_all(cale_clients)
        vtm = ValidatingMovie()
        stm = ServiceMovies(vtm, rtm)
        vtc = ValidatingClient()
        stc = ServiceClients(vtc, rtc)
        vtr = ValidatingRentals()
        str = ServiceRentals(vtr, rtr, rtc, rtm, vtc, vtm, rf)
        client = stc.random_client_generator()
        id_m = 25
        name_m = "Do I work"
        genre_m = "romance"
        description_m = "i exist man"
        movie = stm.add_movie(id_m, name_m, genre_m, description_m)
        idr = 21
        d = 23
        rental = str.add_rental(idr, client.get_id_client(), movie.get_id_movie(), d)
        assert rental.get_id_rental() == idr
        assert rental.get_days_rental() == d
        assert rental.get_movie() == movie
        assert rental.get_client() == client
        name_n="I am new man"
        CNP_n="1234567891011"
        id=client.get_id_client()
        modified_c=str.modify_client_and_rental(id,name_n,CNP_n)
        assert modified_c.get_id_client() == id
        assert modified_c.get_name_client() == name_n
        assert modified_c.get_CNP_client() == CNP_n
        str.delete_client_and_rentals(client.get_id_client())
        try:
            stc.search_client_by_id(client.get_id_client())
        except RepoError:
            pass
        self.assertEqual(str.len(),0)

    def test_del_and_mod_m(self):
        cale_movies = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        cale_rentals = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_rentals.txt"
        cale_clients = r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
        rtm = FileRepoMovie(cale_movies)
        rtc = FileRepoClients(cale_clients)
        rtr = RepoRentals(cale_rentals)
        rf = FileRepoRentals(cale_rentals)
        self.remove_all(cale_movies)
        self.remove_all(cale_rentals)
        self.remove_all(cale_clients)
        vtm = ValidatingMovie()
        stm = ServiceMovies(vtm, rtm)
        vtc = ValidatingClient()
        stc = ServiceClients(vtc, rtc)
        vtr = ValidatingRentals()
        str = ServiceRentals(vtr, rtr, rtc, rtm, vtc, vtm, rf)
        client = stc.random_client_generator()
        id_m = 25
        name_m = "Do I work"
        genre_m = "romance"
        description_m = "i exist man"
        movie = stm.add_movie(id_m, name_m, genre_m, description_m)
        idr = 21
        d = 23
        rental = str.add_rental(idr, client.get_id_client(), movie.get_id_movie(), d)
        assert rental.get_id_rental() == idr
        assert rental.get_days_rental() == d
        assert rental.get_movie() == movie
        assert rental.get_client() == client
        namen="fdfdfdfdf"
        genren="errer"
        movie_n=str.modify_movie_and_rental(id_m,namen,genren,description_m)
        assert movie_n.get_id_movie()==id_m
        self.assertEqual(movie_n.get_name_movie(),namen)
        self.assertEqual(movie_n.get_genre_movie(), genren)
        str.delete_movie_and_rentals(id_m)
        try:
            stm.search_movie_by_id(client.get_id_client())
            assert False
        except RepoError:
            pass
        self.assertEqual(str.len(),0)
