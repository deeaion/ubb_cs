from domain.domain_client import *
from domain.domain_movie import *
from infrastucura.repository_movies import search_movie


def valideaza_client(client,movies):
    erori=""
    if(get_id_client(client)<0):
        erori+="the id needs to be a positive integer\n"
    if(len(get_CNP_client(client))!=13):
        erori+="cnp invalid\n"
    if(len(get_name_client(client))==0):
        erori+="please enter a name\n"
    movies_c=get_movies_client(client)

    movie=0
    mistake=0
    if(len(movies_c)!=0):
        while(movie<len(movies_c)and mistake==0):
            i=0
            found=-1
            while(i<len(movies) and found==-1):
                if(movies[i]["id_movie"]==movies_c[movie]):
                    found=i
                i=i+1
            movie += 1
        if(found==-1):
            mistake=mistake+1

    if(mistake!=0):
        erori+="one of the id's does not correspond to an existing movie\n"
    if(len(erori)>0):
        raise ValueError(erori)

