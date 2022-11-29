from domain.domain_client import Client
from domain.domain_movie import Movie
from domain.domain_rentals import Rental
from errors.repo_error import RepoError
from infrastuctura.repo_client import RepoClient
from infrastuctura.repo_movie import RepoMovie
from infrastuctura.repo_rentals import RepoRentals


class Repo_tests:
    def __init__(self):
        pass
    def repo_tests(self):
        self.repo_tests_c()
        self.repo_tests_m()
        self.repo_tests_r()
    def repo_tests_c(self):
        self.add_tests_c()
        self.modify_testsc()
        self.search_testsc()
        self.delete_testsc()
    def add_tests_c(self):
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
    def modify_testsc(self):
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
    def search_testsc(self):
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
    def delete_testsc(self):
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


    def repo_tests_m(self):
        self.add_tests_m()
        self.modify_testsm()
        self.search_testsm()
        self.delete_testsm()

    def add_tests_m(self):
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
    def modify_testsm(self):
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
    def search_testsm(self):
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
    def delete_testsm(self):
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
    def repo_tests_r(self):
        self.add_tr()
        self.del_tr()
        self.sea_tr()
        self.mod_tr()

    def add_tr(self):
        rtm = RepoMovie()
        rtc = RepoClient()
        rtr=RepoRentals()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)

        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        rtm.add_movie(movie)
        rtc.add_client(client)

        id_rental=2
        days=3

        rental=Rental(id_rental,client,movie,days)
        assert (rtr.len()) == 0
        rtr.add_rental(rental)
        assert (rtr.len()) == 1
        try:
            rtr.add_rental(rental)
            assert False
        except RepoError:
            pass

    def del_tr(self):
        rtm = RepoMovie()
        rtc = RepoClient()
        rtr = RepoRentals()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)

        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        rtm.add_movie(movie)
        rtc.add_client(client)

        id_rental = 2
        days = 3

        rental = Rental(id_rental, client, movie, days)
        rtr.add_rental(rental)
        rtr.delete_rental_by_id(id_rental)
        assert (rtr.len())==0
        try:
            rtr.delete_rental_by_id(id_rental)
            assert False
        except RepoError:
            pass

    def sea_tr(self):
        rtm = RepoMovie()
        rtc = RepoClient()
        rtr = RepoRentals()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)

        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        rtm.add_movie(movie)
        rtc.add_client(client)

        id_rental = 2
        days = 3

        rental = Rental(id_rental, client, movie, days)
        try:
            rtr.search_rental_by_id(id_rental)
            assert False
        except RepoError:
            pass
        rtr.add_rental(rental)
        assert (rtr.len()) == 1
        assert(rental==rtr.search_rental_by_id(id_rental))

    def mod_tr(self):
        rtm = RepoMovie()
        rtc = RepoClient()
        rtr = RepoRentals()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)

        id = 25
        name = "Do I work"
        genre = "romance"
        description = "uuuuh"
        movie = Movie(id, name, genre, description)
        rtm.add_movie(movie)
        rtc.add_client(client)

        id_rental = 2
        days = 3
        days_n=32

        rental = Rental(id_rental, client, movie, days)
        rental_n=Rental(id_rental,client,movie,days_n)
        try:
            rtr.modify_rental(rental)
            assert False
        except RepoError:
            pass
        rtr.add_rental(rental)
        assert (rtr.len()) == 1
        rtr.modify_rental(rental_n)
        assert rtr.search_rental_by_id(id_rental).get_id_rental() == id_rental
        assert rtr.search_rental_by_id(id_rental).get_movie() ==movie
        assert rtr.search_rental_by_id(id_rental).get_client() == client
        assert rtr.search_rental_by_id(id_rental).get_days_rental() == days_n