from domain.domain_client import get_id_client


def number_of_clients(clients):
    return len(clients)
def add_client_to_list(clients, client):
    id=get_id_client(client)
    for client_ in clients:
        if(client_['id']==id):
            raise ValueError("client already exists\n")
    clients.append(client)
def modify_client(clients,id,modified_client):
    found=-1
    for client in range(0,len(clients)):
        if(clients[client]['id']==id):
            found=client
    if(found==-1):
        raise ValueError("client does not exist\n")
    clients[found]=modified_client
def search_client(clients,id_client):
    found = -1
    for client in range(0, len(clients)):
        if (clients[client]['id'] == id_client):
            found = client
    if (found == -1):
        raise ValueError("client does not exist\n")
    return clients[found]
def delete_client(clients,id_client):
    found = -1
    for client in range(0, len(clients)):
        if (clients[client]['id'] == id_client):
            found = client
    if (found == -1):
        raise ValueError("client does not exist\n")
    clients.remove(clients[found])
def return_index_client(clients,id_client):
    found = -1
    for client in range(0, len(clients)):
        if (clients[client]['id'] == id_client):
            found = client
    if (found == -1):
        raise ValueError("client does not exist\n")
    return found
def add_to_movie_list_of_client(clients,movies,id_client,id_movie):
    index_client=return_index_client(clients,id_client)
    found_movie_client=-1
    for i in range(0,len(clients[index_client]["movies_rent"])):
        if(id_movie==clients[index_client]["movies_rent"][i]):
            found_movie_client=i
    if(found_movie_client!=-1):
        raise ValueError("movie already is in rental")
    else:
        found_movie_in_movies=-1
        for movie in range(0,len(movies)):
            if(id_movie==movies[movie]['id_movie']):
                found_movie_in_movies=movie
        if(found_movie_in_movies==-1):
            raise ValueError("you have not registered this movie")
    clients[index_client]["movies_rent"].append(id_movie)
def delete_movie_by_index_from_client(clients,id_client,id_movie):
    index_client = return_index_client(clients, id_client)
    client = clients[index_client]
    found_movie_client = -1
    for movie in range(0, len(client["movies_rent"])):
        if (id_movie == client["movies_rent"][movie]):
            found_movie_client = movie
    if (found_movie_client ==-1):
        raise ValueError("client has not rent this movie\n")
    clients[index_client]["movies_rent"].remove(id_movie)

