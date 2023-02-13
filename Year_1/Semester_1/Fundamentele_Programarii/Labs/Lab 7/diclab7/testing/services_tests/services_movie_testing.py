from business.services_movies import *
from domain.domain_client import create_client
from infrastucura.repository_client import add_client_to_list, add_to_movie_list_of_client


def add_movie_services_test():
    movies = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    assert(number_of_movies_services(movies)==0)
    add_movie_service(movies,id_movie,title,description,genre)
    assert (number_of_movies_services(movies) == 1)
    id_movie_egal = 23
    title_new = "Excision"
    description_new = "Alienated teen Pauline struggles with the pressures of fitting into high school, pleasing her mother."
    genre_new = "horror"
    try:
        add_movie_service(movies, id_movie_egal,title_new,description_new,genre_new)
        assert False
    except ValueError as ve:
        assert (str(ve) == "movie already exists\n")
    assert (number_of_movies(movies) == 1)
def modify_movie_services_test():
    movies = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"

    id_movie_egal = 23
    title_new = "Excision"
    description_new = "Alienated teen Pauline struggles with the pressures of fitting into high school, pleasing her mother."
    genre_new = "horror"

    try:
        modify_movie_service(movies,id_movie,title_new,description_new,genre_new)
        assert False
    except ValueError as ve:
        assert str(ve) == "movie does not exist\n"
    add_movie_service(movies,id_movie,title,description,genre)
    assert (number_of_movies(movies) == 1)
    modify_movie_service(movies, id_movie, title_new,description_new,genre_new)
    assert (get_id_movie(movies[0]) == id_movie_egal)
    assert (get_title_movie(movies[0]) == title_new)
    assert (get_genre_movie(movies[0]) == genre_new)
    assert (get_description_movie(movies[0]) == description_new)
def search_movie_services_test():
    movies = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    try:
        search_movie_service(movies, id_movie)
        assert False
    except ValueError as ve:
        assert str(ve) == "movie does not exist\n"
    add_movie_service(movies, id_movie,title,description,genre)
    movie=search_movie_service(movies,id_movie)
    assert (movie == movies[0])
def delete_movie_services_test():
    movies = []
    clients = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    id = 23
    CNP = 2960206137611
    name = "Hey Trou"
    movies_rent = []
    client = create_client(id, name, CNP, movies_rent)
    add_client_to_list(clients, client)
    try:
        delete_movie_service(movies, clients,id_movie)
    except ValueError as ve:
        assert str(ve) == "movie does not exist\n"
    add_movie_service(movies,id_movie,title,description,genre)
    add_to_movie_list_of_client(clients, movies, id, id_movie)
    assert (clients[0]["movies_rent"] == [id_movie])
    delete_movie_service(movies, clients, id_movie)
    assert (number_of_movies(movies) == 0)
    assert (len(clients[0]["movies_rent"]) == 0)
