from domain.domain_movie import create_movie
from validation.validate_movies import valideaza_movie


def validate_movies_tests():
    id_movie = 23
    title = "Your Lie in April"
    description = "a story about a bully reconciling with its victim"
    genre = "psychological"
    movie = create_movie(id_movie, title, description, genre)
    valideaza_movie(movie)
    id_incorrect=-32
    title_incorrect=""
    description_incorrect=""
    genre_incorrect=""
    movie_incorrect=create_movie(id_incorrect,title_incorrect,description_incorrect,genre_incorrect)
    try:
        valideaza_movie(movie_incorrect)
        assert False
    except ValueError as ve:
        assert str(ve)=="the id needs to be a positive integer\ntitle invalid\nplease enter a description\nplease enter a genre\n"
