from domain.domain_client import create_client
from domain.domain_movie import create_movie
from infrastucura.repository_movies import add_movie_to_list_of_movies
from validation.validate_client import valideaza_client


def validate_client_tests():
    movies=[]
    name = "Hey Trou"
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movie=create_movie(id_movie,title,description,genre)
    add_movie_to_list_of_movies(movies,movie)
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    movies_rent = [id_movie]
    client = create_client(id, name, CNP, movies_rent)
    valideaza_client(client,movies)
    id_client_incorrect=-2
    name_incorrect=""
    CNP_incorrect=""
    id_movie_incorrect=65
    movies_rent_incorrect=[id_movie_incorrect]
    client_incorrect=create_client(id_client_incorrect,name_incorrect,CNP_incorrect,movies_rent_incorrect)
    try:
        valideaza_client(client_incorrect,movies)
        assert False
    except ValueError as ve:
        assert str(ve)=="the id needs to be a positive integer\ncnp invalid\nplease enter a name\none of the id's does not correspond to an existing movie\n"

