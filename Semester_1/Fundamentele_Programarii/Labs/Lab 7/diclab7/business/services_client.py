from domain.domain_client import *
from infrastucura.repository_client import *
from validation.validate_client import *

def add_client_service(clients,movies,id,name,CNP,movies_rent):
    client=create_client(id,name,CNP,movies_rent)
    valideaza_client(client,movies)
    add_client_to_list(clients,client)
def modify_client_service(clients,movies,id_old,name_new,CNP_new,movies_rent_new):
    client=search_client(clients,id_old)
    modified_client=create_client(id_old,name_new,CNP_new,movies_rent_new)
    valideaza_client(modified_client,movies)
    modify_client(clients,id_old,modified_client)
def delete_client_service(clients,id_client):
    delete_client(clients,id_client)
def search_client_service(clients,id_client):
    return search_client(clients,id_client)
def number_of_clients_service(clients):
    return len(clients)
def get_all_clients(clients):
    return list(clients)
def add_to_movie_list_of_client_service(clients,movies,id_client,id_movie):
    add_to_movie_list_of_client(clients,movies,id_client,id_movie)
def delete_movie_from_movie_list_of_client_service(clients,id_client,id_movie):
    delete_movie_by_index_from_client(clients,id_client,id_movie)

