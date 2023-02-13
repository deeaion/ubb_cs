from domain.domain_movie import create_movie
from infrastucura.repository_movies import *
from validation.validate_movies import *

def add_movie_service(movies,id,title,description,genre):
    movie=create_movie(id,title,description,genre)
    valideaza_movie(movie)
    add_movie_to_list_of_movies(movies,movie)
def modify_movie_service(movies,id_movie,title_new,description_new,genre_new):
    movie=search_movie(movies,id_movie)
    movie_modified=create_movie(id_movie,title_new,description_new,genre_new)
    valideaza_movie(movie_modified)
    modify_movie(movies,id_movie,movie_modified)
def delete_movie_service(movies,clients,id_movie):
    delete_movie(movies,clients,id_movie)
def search_movie_service(movies,id_movie):
    return search_movie(movies,id_movie)
def number_of_movies_services(movies):
    return len(movies)
def movie_list_services(movies):
    return list(movies)