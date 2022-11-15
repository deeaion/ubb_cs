#params==0
from business.services_client import *
from business.services_movies import *
from prezentare.functions import sort_by_number_of_movies, print_client, sort_by_name_of_client, \
    sort_by_number_of_rentals, print_movie


def ui_print_clients(clients):
    if(number_of_clients_service(clients)==0):
        print("There are no clients registered")
        return 0
    for client in clients:
        print("Client:")
        print("id: "+str(client['id']))
        print("name: "+client['name'])
        print("CNP: "+client['CNP'])
        print("Movies they are currently renting: ")
        print(client['movies_rent'])
def ui_print_movies(movies):
    if (number_of_movies_services(movies) == 0):
        print("There are no movies registered")
        return 0
    for movie in movies:
        print("Movie:")
        print("id: " + str(movie['id_movie']))
        print("title: " + movie['title'])
        print("description: " + movie['description'])
        print("genre: "+movie['genre'])
def ui_print_by_name_client(clients,movies):
    clients_sorted=clients.copy()
    sort_by_name_of_client(clients_sorted)
    for client_s in clients_sorted:
        if(len(client_s)!=0):
            print_client(client_s)
def ui_print_clients_by_movie_number(clients,movies):
    clients_sorted=clients.copy()
    sort_by_number_of_movies(clients_sorted)
    for client_s in clients_sorted:
        print("Name: "+client_s["name"])
        print("Number of movies rented "+str(len(client_s["movies_rent"])))
def ui_print_the_most_rented_movies(clients,movies):
    movies_sorted=movies.copy()
    client_sorted=clients.copy()
    sort_by_number_of_rentals(client_sorted,movies_sorted)
    i=0
    while(i<len(movies_sorted)and i<3):
        print("Numarul "+str(i+1))
        print_movie(movies_sorted[i])
        i+=1

def ui_print_the_30_precent(clients,movies):
    percent=int((30/100)*len(clients))
    if(percent==0):
        print("There are not enough people to calculate this percentage")
        return
    clients_sorted = clients.copy()
    sort_by_number_of_movies(clients_sorted)
    i=0
    while(i<percent):
        print("Name: " + clients_sorted[len(clients_sorted)-i-1]["name"])
        print("Number of movies rented " + str(len(clients_sorted[len(clients_sorted)-i-1]["movies_rent"])))
        i+=1
#params==4
def ui_add_client(clients,movies,params):
    id=int(params[0])
    name=params[1]
    CNP=params[2]

    movies_rent=[int (i) for i in params[3:]]
    if (len(movies_rent) == 1 and movies_rent[0] == -1):
        movies_rent.clear()
    add_client_service(clients, movies, id, name, CNP, movies_rent)
def ui_modify_client(clients,movies,params):
    id_old = int(params[0])
    name_new = params[1]
    CNP_new = params[2]
    movies_rent_new = [int(i) for i in params[3:]]
    if (len(movies_rent_new) == 1 and movies_rent_new[0] == -1):
        movies_rent_new.clear()
    modify_client_service(clients, movies, id_old, name_new, CNP_new, movies_rent_new)
#only movie
def ui_add_movie(movies,params):
    id = int(params[0])
    title = params[1]
    description = params[2]
    genre = params[3]
    add_movie_service(movies,id,title,description,genre)
def ui_modify_movie(movies,params):
    id = int(params[0])
    title_new = params[1]
    description_new = params[2]
    genre_new = params[3]
    modify_movie_service(movies,id,title_new,description_new,genre_new)
#params=1,un id
#clients
def ui_delete_client(clients,params):
    id_client=int(params[0])
    delete_client_service(clients,id_client)
def ui_search_client(clients,params):
    id_client=int(params[0])
    print(search_client_service(clients,id_client))
#movies
def ui_delete_movie(clients,movies,params):
    id_movie=int(params[0])
    delete_movie_service(movies,clients,id_movie)
def ui_search_movie(clients,movies,params):
    id_movie=int(params[0])
    print(search_movie_service(movies,id_movie))
#params==2
def ui_delete_movie_from_client(clients,movies,params):
    id_client=int(params[0])
    id_movie=int(params[1])
    delete_movie_from_movie_list_of_client_service(clients,id_client,id_movie)
def ui_add_movie_to_client(clients,movies,params):
    id_client = int(params[0])
    id_movie = int(params[1])
    add_to_movie_list_of_client_service(clients,movies,id_client,id_movie)
def ui_help():
    pass
