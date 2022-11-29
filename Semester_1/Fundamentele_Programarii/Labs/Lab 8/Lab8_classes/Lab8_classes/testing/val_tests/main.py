from domain.domain_client import Client
from domain.domain_movie import Movie
from domain.domain_rentals import Rental
from validation.validate_client import ValidatingClient
from validation.validate_movie import ValidatingMovie
from validation.validate_rentals import ValidatingRentals


class Val_tests:
    def __init__(self):
        pass


    def val_tests(self):
        self.val_c_tests()
        self.val_m_tests()
        self.val_r_tests()

    def val_c_tests(self):
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
    def val_m_tests(self):
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

    def val_r_tests(self):
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
