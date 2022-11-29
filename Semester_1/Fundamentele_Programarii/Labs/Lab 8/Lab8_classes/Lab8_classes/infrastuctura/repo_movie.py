from errors.repo_error import RepoError


class RepoMovie:
    def __init__(self):
        self.__movies={}

    def add_movie(self,movie):
        if movie.get_id_movie() in self.__movies:
            raise RepoError("Movie already exists")
        self.__movies[movie.get_id_movie()]=movie

    def delete_movie_by_id(self,id_movie):
        if id_movie not in self.__movies or self.__movies[id_movie].deleted()==True:
            raise RepoError("Movie does not exist")
        del self.__movies[id_movie]
    def modify_movie(self,movie):
        if movie.get_id_movie() not in self.__movies:
            raise RepoError("Movie does not exist")
        self.__movies[movie.get_id_movie()]=movie
    def search_movie_by_id(self,id_movie):
        if id_movie not in self.__movies:
            raise RepoError("Movie does not exist")
        return self.__movies[id_movie]
    def get_number_of_movies(self):
        return len(self.__movies)
    def get_all(self):
        movies=[]
        for id_movie in self.__movies:
            movies.append(self.__movies[id_movie])
        return movies
    def len(self):
        return len(self.__movies)