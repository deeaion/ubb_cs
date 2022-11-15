from domain.domain_movie import *


def search_movie(movies, id_movie):
    found = -1
    for movie in range(0, len(movies)):
        if (movies[movie]['id_movie'] == id_movie):
            found = movie
    if (found == -1):
        raise ValueError("movie does not exist\n")
    return movies[found]
def return_movie_index(movies, id_movie):
    found = -1
    for movie in range(0, len(movies)):
        if (movies[movie]['id'] == id_movie):
            found = movie
    if (found == -1):
        raise ValueError("client does not exist\n")
    return found
def add_movie_to_list_of_movies(movies,movie):
    id = get_id_movie(movie)
    for movie_ in movies:
        if (movie_['id_movie'] == id):
            raise ValueError("movie already exists\n")
    movies.append(movie)
def modify_movie(movies,id_movie,modified_movie):
    found=-1
    for movie in range(0,len(movies)):
        if(movies[movie]['id_movie']==id_movie):
            found=movie
    if(found==-1):
        raise ValueError("movie does not exist\n")
    movies[found]=modified_movie
def delete_movie(movies,clients,id_movie):
    found = -1
    for movie in range(0, len(movies)):
        if (movies[movie]['id_movie'] == id_movie):
            found = movie
    if (found == -1):
        raise ValueError("movie does not exist\n")
    movies.remove(movies[found])
    for client in clients:
        delete_movie_of_client_list(client,id_movie)
def delete_movie_of_client_list(client,id_movie):
    found=-1
    id_index=0
    while(found==-1 and id_index<len(client["movies_rent"])):
        if(id_movie==client["movies_rent"][id_index]):
            found=id_index
    if(found!=-1):
        client["movies_rent"].remove(id_movie)
def number_of_movies(movies):
    return len(movies)
