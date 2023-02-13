from domain.domain_client import get_id_client
from domain.domain_movie import get_id_movie
from infrastucura.repository_client import modify_client
from infrastucura.repository_movies import modify_movie


def swap(clients,client_1,client_2):
    client_i=client_1
    modify_client(clients,get_id_client(client_1),client_2)
    modify_client(clients,get_id_client(client_2),client_i)
def swap_m(movies,movie_1,movie_2):
    movie_i=movie_1
    modify_movie(movies,get_id_movie(movie_1),movie_2)
    modify_movie(movies,get_id_movie(movie_2),movie_i)
def sort_by_number_of_movies(clients):
    for i in range(0,len(clients)-1):
        if(len(clients[i]["movies_rent"])>len(clients[i+1]["movies_rent"])):
            swap(clients,clients[i],clients[i+1])
    return clients
def sort_by_name_of_client(clients):
    for i in range(0,len(clients)-1):
        if(clients[i]['name']>clients[i+1]['name']):
            swap(clients,clients[i],clients[i+1])
    return clients
def number_of_rentals(clients,movies):
    number=[0]*len(movies)
    for movie in range(0,len(movies)):
        for client in clients:
            if movies[movie]['id_movie'] in client['movies_rent']:
                number[movie]=number[movie]+1
    return number
def sort_by_number_of_rentals(clients,movies):
    number=number_of_rentals(clients,movies)
    for i in range(0,len(movies)-1):
        if number[i]<number[i+1]:
            swap_m(movies,movies[i],movies[i+1])
def print_client(client):
    print("Client:")
    print("id: " + str(client['id']))
    print("name: " + client['name'])
    print("CNP: " + client['CNP'])
    print("Movies they are currently renting: ")
    print(client['movies_rent'])
def print_movie(movie):
    print("Movie:")
    print("id: " + str(movie['id_movie']))
    print("title: " + movie['title'])
    print("description: " + movie['description'])
    print("genre: " + movie['genre'])
