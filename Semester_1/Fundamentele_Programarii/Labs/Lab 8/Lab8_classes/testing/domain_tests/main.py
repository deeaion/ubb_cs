from domain.DTO_most_rents import Most_Rents_DTO
from domain.domain_client import Client
from domain.domain_movie import Movie
from domain.domain_rentals import Rental


class Domain_tests:
    def __init__(self):
        pass

    def domain_tests(self):
        ##client##
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        assert client.get_id_client() == id
        assert client.get_CNP_client() == CNP
        assert client.get_name_client() == name

        ##movie##

        id_m=12
        name_m="A movie"
        genre="romance"
        description=" a description "
        movie= Movie(id, name,genre,description)
        assert movie.get_id_movie()==id
        assert movie.get_name_movie()==name
        assert movie.get_genre_movie()==genre
        assert movie.get_description_movie()==description

        ##domain rentals##
        id_rental=11
        rental_time=21
        rental=Rental(id_rental,client,movie,rental_time)
        assert rental.get_id_rental()==id_rental
        assert rental.get_movie()==movie
        assert rental.get_client()==client
        assert rental.get_days_rental()==rental_time

        ##domain DTO##
        number_of_r=2312
        dto=Most_Rents_DTO(id,name_m,number_of_r)
        assert dto.get_id_client()==id
        assert dto.get_movie_name()==name_m
        assert dto.get_number_of_rentals()==number_of_r
