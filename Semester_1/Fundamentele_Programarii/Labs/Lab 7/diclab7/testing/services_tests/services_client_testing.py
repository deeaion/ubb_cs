from business.services_client import *
from business.services_movies import add_movie_service


def add_client_service_test():
    movies = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    add_movie_service(movies,id_movie,title,description,genre)
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    movies_rent = [id_movie]
    assert (number_of_clients_service(clients)==0)
    add_client_service(clients,movies,id,name,CNP,movies_rent)
    assert (number_of_clients(clients)==1)
    id_egal = 23
    id_movie_nou = 23
    name_nou = "Allison Grace"
    CNP_nou = "6180111164545"
    movies_rent_nou = [id_movie_nou]
    assert (number_of_clients_service(clients) == 1)
    try:
        add_client_service(clients,movies,id_egal,name_nou,CNP_nou,movies_rent_nou)
        assert False
    except ValueError as ve:
        assert (str(ve) == "client already exists\n")
        assert (number_of_clients(clients) == 1)
def modify_client_service_test():
    movies = []
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    add_movie_service(movies,id_movie,title,description,genre)
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    movies_rent = [id_movie]
    add_client_service(clients, movies,id,name,CNP,movies_rent)
    assert (number_of_clients(clients) == 1)
    id_egal = 23
    name_nou = "Allison Grace"
    CNP_nou = "6180111164545"
    movies_rent_nou = []

    assert (number_of_clients(clients) == 1)
    try:
        modify_client_service(clients,movies,24,name_nou,CNP_nou,movies_rent_nou)
        assert False
    except ValueError as ve:
        assert str(ve) == "client does not exist\n"
    modify_client_service(clients, movies, id, name_nou, CNP_nou, movies_rent_nou)
    assert (number_of_clients(clients) == 1)
def delete_client_service_test():
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movies = []
    movies_rent = []
    id_movie_new= 32
    title_new = "Excision"
    description_new = "Alienated teen Pauline struggles with the pressures of fitting into high school, pleasing her mother."
    genre_new = "horror"
    add_movie_service(movies,id_movie,title,description,genre)
    assert(len(movies)==1)
    add_movie_service(movies, id_movie_new, title_new, description_new, genre_new)
    assert (len(movies) == 2)
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    movies_rent = [id_movie]
    try:
        delete_client_service(clients,id)
        assert False
    except ValueError as ve:
        assert(str(ve))=="client does not exist\n"
    add_client_service(clients,movies,id,name,CNP,movies_rent)
    assert (number_of_clients(clients) == 1)
    id_new = 26
    name_new = "Allison Grace"
    CNP_new = "6180111164545"
    movies_rent_new = [id_movie,id_movie_new]
    add_client_service(clients,movies,id_new,name_new,CNP_new,movies_rent_new)
    assert (number_of_clients(clients) == 2)
    delete_client(clients, id)
    assert (number_of_clients(clients) == 1)
    delete_client(clients, id_new)
    assert (number_of_clients(clients) == 0)
def search_client_service_test():
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movies = []
    add_movie_service(movies, id_movie, title, description, genre)
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    movies_rent = [id_movie]
    assert (number_of_clients(clients) == 0)
    try:
        search_client_service(clients, id)
        assert False
    except ValueError as ve:
        assert str(ve) == "client does not exist\n"
    add_client_service(clients,movies,id,name,CNP,movies_rent)
    assert (number_of_clients(clients) == 1)
    client_found = search_client_service(clients, id)
    assert (client_found == clients[0])
def add_movie_to_client_list_service_test():
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movies = []
    movies_rent = []
    add_client_service(clients,movies,id,name,CNP,movies_rent)
    assert (number_of_clients(clients) == 1)
    try:
        add_to_movie_list_of_client(clients, movies, id, id_movie)
        assert False
    except ValueError as ve:
        assert str(ve) == "you have not registered this movie"
    add_movie_service(movies, id_movie,title,description,genre)
    assert (len(movies) == 1)
    assert (len(clients[0]["movies_rent"]) == 0)
    add_to_movie_list_of_client_service(clients, movies, id, id_movie)
    assert (len(clients[0]["movies_rent"]) == 1)
def delete_movie_from_client_list_service_test():
    clients = []
    id = 23
    CNP = "2960206137611"
    name = "Hey Trou"

    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"

    movies = []
    movies_rent = []
    add_client_service(clients,movies,id,name,CNP,movies_rent)
    client=clients[0]
    add_movie_service(movies,id_movie,title,description,genre)
    assert (len(client["movies_rent"]) == 0)
    assert (number_of_clients_service(clients) == 1)
    try:
        delete_movie_from_movie_list_of_client_service(clients, id, id_movie)
        assert False
    except ValueError as ve:
        assert str(ve) == "client has not rent this movie\n"
    add_to_movie_list_of_client_service(clients, movies, id, id_movie)
    assert (len(movies) == 1)
    assert (len(client["movies_rent"]) == 1)
    delete_movie_by_index_from_client(clients, id, id_movie)
    assert (len(client["movies_rent"]) == 0)