from domain.domain_movie import Movie


class ServiceMovies:
    def __init__(self, validate_movie, repo_movie):
        self.__validate_movie = validate_movie
        self.__repo_movie = repo_movie
    def add_movie(self,id_movie,name_movie,genre_movie,description_movie):
        movie=Movie(id_movie,name_movie,genre_movie,description_movie)
        self.__validate_movie.validate(movie)
        self.__repo_movie.add_movie(movie)
        return movie
    #delete is in rental
    def modify_movie(self,id_movie,name_movie,genre_movie,description_movie):
        movie=Movie(id_movie,name_movie,genre_movie,description_movie)
        self.__validate_movie.validate(movie)
        self.__repo_movie.modify_movie(movie)
        return movie
    def search_movie_by_id(self,id_movie):
        return self.__repo_movie.search_movie_by_id(id_movie)
    def get_all_movies(self):
        return self.__repo_movie.get_all()

    def len(self):
        return self.__repo_movie.len()
