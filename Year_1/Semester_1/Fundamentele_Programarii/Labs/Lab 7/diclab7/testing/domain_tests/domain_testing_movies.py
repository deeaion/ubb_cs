from domain.domain_movie import *


def create_movies_tests():
    id=43
    title="Your Lie in April"
    description="a story of a bully"
    genre="psychological"
    movie=create_movie(id,title,description,genre)
    assert(get_id_movie(movie)==id)
    assert(get_title_movie(movie)==title)
    assert(get_description_movie(movie)==description)
    assert(get_genre_movie(movie)==genre)

def equal_movies_tests():
    pass
