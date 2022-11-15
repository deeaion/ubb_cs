from domain.domain_client import create_client
from domain.domain_movie import *
from infrastucura.repository_client import *
from infrastucura.repository_movies import add_movie_to_list_of_movies


def add_to_client_list_test():
    clients=[]
    id=23
    CNP="2960206137611"
    name="Hey Trou"
    id_movie = 23
    movies_rent = [id_movie]
    client=create_client(id,name,CNP,movies_rent)
    add_client_to_list(clients,client)
    assert(number_of_clients(clients))
    id_egal = 23
    id_movie_nou = 32
    name_nou = "Allison Grace"
    CNP_nou = "6180111164545"
    movies_rent_nou = [id_movie_nou]
    client_nou = create_client(id_egal, name_nou, CNP_nou, movies_rent_nou)
    assert(number_of_clients(clients)==1)
    try:
        add_client_to_list(clients,client_nou)
        assert False
    except ValueError as ve:
        assert (str(ve)=="client already exists\n")
        assert (number_of_clients(clients) == 1)
def add_to_client_movie_list_test():
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    title="Your Lie in April"
    description="a story about a bully reconciling with its victim"
    genre="psychological"
    movie=create_movie(id,title,description,genre)
    movies=[]
    movies_rent = []
    client = create_client(id, name, CNP, movies_rent)
    add_client_to_list(clients,client)
    assert(number_of_clients(clients)==1)
    try:
        add_to_movie_list_of_client(clients,movies,id,id_movie)
        assert False
    except ValueError as ve:
        assert str(ve)=="you have not registered this movie"
    add_movie_to_list_of_movies(movies,movie)
    assert(len(movies)==1)
    assert(len(client["movies_rent"])==0)
    add_to_movie_list_of_client(clients,movies,id,id_movie)
    assert(len(client["movies_rent"])==1)
def delete_movie_from_movie_list_of_client_test():
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movie = create_movie(id, title, description, genre)
    movies = []
    movies_rent = []
    client = create_client(id, name, CNP, movies_rent)
    add_movie_to_list_of_movies(movies,movie)
    add_client_to_list(clients, client)
    assert(len(client["movies_rent"])==0)
    assert (number_of_clients(clients) == 1)
    try:
        delete_movie_by_index_from_client(clients,id,id_movie)
        assert False
    except ValueError as ve:
        assert str(ve)=="client has not rent this movie\n"
    add_to_movie_list_of_client(clients,movies,id,id_movie)
    assert (len(movies) == 1)
    assert (len(client["movies_rent"]) == 1)
    delete_movie_by_index_from_client(clients, id, id_movie)
    assert (len(client["movies_rent"]) == 0)
def modify_client_tests():
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    movies_rent = [id_movie]
    client = create_client(id, name, CNP, movies_rent)
    add_client_to_list(clients, client)
    assert(number_of_clients(clients)==1)
    id_egal = 23
    id_movie_nou = 32
    id_movie_nou_2=23
    name_nou = "Allison Grace"
    CNP_nou = "6180111164545"
    movies_rent_nou = [id_movie_nou,id_movie_nou_2]
    client_modified=create_client(id_egal,name_nou,CNP_nou,movies_rent_nou)
    modify_client(clients,id,client_modified)
    assert(number_of_clients(clients)==1)
    try:
        modify_client(clients,24,client_modified)
        assert False
    except ValueError as ve:
        assert str(ve)=="client does not exist\n"
    assert (number_of_clients(clients) == 1)
def delete_client_tests():
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    movies_rent = [id_movie]
    client = create_client(id, name, CNP, movies_rent)
    add_client_to_list(clients, client)
    assert (number_of_clients(clients) == 1)
    id_new = 26
    id_movie_new = 32
    id_movie_new_2 = 23
    name_new = "Allison Grace"
    CNP_new = "6180111164545"
    movies_rent_new = [id_movie_new, id_movie_new_2]
    client_new = create_client(id_new, name_new, CNP_new, movies_rent_new)
    add_client_to_list(clients, client_new)
    assert (number_of_clients(clients) == 2)
    delete_client(clients,id)
    assert(number_of_clients(clients)==1)
    delete_client(clients,id_new)
    assert(number_of_clients(clients)==0)
def search_client_tests():
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    movies_rent = [id_movie]
    client = create_client(id, name, CNP, movies_rent)
    assert(number_of_clients(clients)==0)
    try:
        search_client(clients,id)
        assert False
    except ValueError as ve:
        assert str(ve)=="client does not exist\n"
    add_client_to_list(clients, client)
    assert (number_of_clients(clients) == 1)
    client_found=search_client(clients,id)
    assert (client_found==client)