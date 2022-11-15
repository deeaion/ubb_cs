from domain.domain_movie import *
def valideaza_movie(movie):
    erori=""
    if(get_id_movie(movie)<0):
        erori+="the id needs to be a positive integer\n"
    if(len(get_title_movie(movie))==0):
        erori+="title invalid\n"
    if(len(get_description_movie(movie))==0):
        erori+="please enter a description\n"
    if(len(get_genre_movie(movie))==0):
        erori+="please enter a genre\n"
    if(len(erori)>0):
        raise ValueError(erori)