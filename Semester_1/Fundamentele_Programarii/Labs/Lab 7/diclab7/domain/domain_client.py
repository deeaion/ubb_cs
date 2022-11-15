def create_client(id, name, CNP, movies_rent):
    return {'id':id,
            'name':name,
            'CNP':CNP,
            'movies_rent':movies_rent}

def get_id_client(client):
    return client['id']

def get_name_client(client):
    return client['name']

def get_CNP_client(client):
    return client['CNP']

def get_movies_client(client):
    return client['movies_rent']
def get_len_movies_rent(client):
    return len(client["movies_rent"])
def set_id_client(client,id):
   client['id']=id
def set_name_client(client,name):
    client['name']=name
def set_CNP_client(client,CNP):
    client['CNP']=CNP
def set_movie_list_client(client,movie_list):
    client['movie_list']=movie_list
def equal_client(client, client_egal):
    return (get_id_client(client)==get_id_client(client_egal))
