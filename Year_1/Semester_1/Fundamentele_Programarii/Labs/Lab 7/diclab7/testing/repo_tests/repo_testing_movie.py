from domain.domain_client import *
from infrastucura.repository_client import add_client_to_list, add_to_movie_list_of_client
from infrastucura.repository_movies import *


def add_to_movies_list_test():
    movies=[]
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movie = create_movie(id_movie, title, description, genre)
    add_movie_to_list_of_movies(movies,movie)
    id_movie_egal=23
    title_new="Excision"
    description_new="Alienated teen Pauline struggles with the pressures of fitting into high school, pleasing her mother."
    genre_new="horror"
    movie_new=create_movie(id_movie_egal,title_new,description_new,genre_new)
    assert (number_of_movies(movies) == 1)
    try:
        add_movie_to_list_of_movies(movies, movie_new)
        assert False
    except ValueError as ve:
        assert (str(ve) == "movie already exists\n")
    assert (number_of_movies(movies) == 1)


def modify_movie_tests():
    movies = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movie = create_movie(id_movie, title, description, genre)
    id_movie_egal = 23
    title_new = "Excision"
    description_new = "Alienated teen Pauline struggles with the pressures of fitting into high school, pleasing her mother."
    genre_new = "horror"
    movie_modified = create_movie(id_movie_egal, title_new, description_new, genre_new)
    try:
        modify_movie(movies,id_movie,movie_modified)
        assert False
    except ValueError as ve:
        assert str(ve)=="movie does not exist\n"
    add_movie_to_list_of_movies(movies, movie)
    assert (number_of_movies(movies) == 1)
    modify_movie(movies, id_movie, movie_modified)
    assert(get_id_movie(movies[0])==id_movie_egal)
    assert (get_title_movie(movies[0]) == title_new)
    assert (get_genre_movie(movies[0]) == genre_new)
    assert (get_description_movie(movies[0]) == description_new)

def delete_movie_tests():
    movies = []
    clients=[]
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movie = create_movie(id_movie, title, description, genre)
    id = 23
    CNP = 2960206137611
    name = "Hey Trou"
    movies_rent = []
    client = create_client(id, name, CNP, movies_rent)
    add_client_to_list(clients, client)
    try:
        delete_movie(movies,clients,id_movie)
    except ValueError as ve:
        assert str(ve)=="movie does not exist\n"
    add_movie_to_list_of_movies(movies,movie)
    add_to_movie_list_of_client(clients,movies,id,id_movie)
    assert(clients[0]["movies_rent"]==[id_movie])
    delete_movie(movies,clients,id_movie)
    assert(number_of_movies(movies)==0)
    assert(len(clients[0]["movies_rent"])==0)


def search_movie_tests():
    movies = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movie = create_movie(id_movie, title, description, genre)
    try:
        search_movie(movies,id_movie)
        assert False
    except ValueError as ve:
        assert str(ve)=="movie does not exist\n"
    add_movie_to_list_of_movies(movies, movie)
    verify_movie=dict(search_movie(movies,id_movie))
    assert(verify_movie==movie)
