from Persistent_Memory.repo_movie import RepoMovie
from domain.domain_movie import Movie


class FileRepoMovie(RepoMovie):

    def __init__(self,path_to_file):
        RepoMovie.__init__(self)
        self.__path_to_file=path_to_file

    def add_movie(self,movie):
        self.__read_all_from_file()
        RepoMovie.add_movie(self,movie)
        self.__write_all_to_file()
    def modify_movie(self,movie):
        self.__read_all_from_file()
        RepoMovie.modify_movie(self,movie)
        self.__write_all_to_file()
    def delete_movie_by_id(self,id_movie):
        self.__read_all_from_file()
        RepoMovie.delete_movie_by_id(self,id_movie)
        self.__write_all_to_file()
    def search_movie_by_id(self,id_movie):
        self.__read_all_from_file()
        RepoMovie.search_movie_by_id(self,id_movie)
        self.__write_all_to_file()
    def get_all(self):
        self.__read_all_from_file()
        return RepoMovie.get_all(self)
    def len(self):
        self.__read_all_from_file()
        return RepoMovie.len(self)
    def __write_all_to_file(self):
        with open(self.__path_to_file,"w") as f:
            for movie in self._movies.values():
                f.write(str(movie)+"\n")

    def __read_all_from_file(self):
        with open(self.__path_to_file,"r") as f:
            lines=f.readlines()
            self._movies.clear()
            for line in lines:
                line=line.strip()
                if line!="":
                    parts=line.split(", ")
                    id_movie=int(parts[0])
                    name=parts[1]
                    genre=parts[2]
                    description=parts[3]
                    movie=Movie(id_movie,name,genre,description)
                    self._movies[id_movie]=movie

