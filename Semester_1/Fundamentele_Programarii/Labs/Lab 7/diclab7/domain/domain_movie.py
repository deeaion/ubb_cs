def create_movie(id_movie, title, description, genre):
    return {'id_movie':id_movie,
            'title': title,
            'description':description,
            'genre':genre}
def get_genre_movie(movie):
    return movie['genre']


def get_description_movie(movie):
    return movie['description']


def get_title_movie(movie):
    return movie['title']
def get_id_movie(movie):
    return movie["id_movie"]
def equal_movies(movie_1,movie_2):
    return movie_1==movie_2

