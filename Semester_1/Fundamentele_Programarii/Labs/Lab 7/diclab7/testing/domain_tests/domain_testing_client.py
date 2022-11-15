from domain.domain_client import *


def create_client_tests():
    id=25
    name="Chris Olly"
    CNP= 2960206137611
    id_movie=23
    movies_rent= [id_movie]
    client= create_client(id,name,CNP,movies_rent)
    assert (get_id_client(client)==id)
    assert (get_name_client(client)==name)
    assert (get_CNP_client(client)==CNP)
    assert (get_movies_client(client)==movies_rent)

def equal_client_tests():
    id = 25
    name = "Chris Olly"
    CNP = 2960206137611
    id_movie=23
    movies_rent = [id_movie]
    client = create_client(id, name, CNP, movies_rent)
    id_egal = 25
    id_movie_nou=32
    name_nou = "Allison Grace"
    CNP_nou = 6180111164545
    movies_rent_nou = [id_movie_nou]
    client_egal = create_client(id_egal, name_nou, CNP_nou, movies_rent_nou)
    assert (equal_client(client,client_egal))


