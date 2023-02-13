import random
import string

from domain.domain_movie import Movie


class ServiceMovies:
    def __init__(self, validate_movie, repo_movie):
        self.__validate_movie = validate_movie
        self.__repo_movie = repo_movie
    def random_name(self):
        length= random.randrange(9)
        if(length==0):
            length+=1
        num_words=random.randrange(3)
        if(num_words==0):
            num_words+=1
        letters = string.ascii_lowercase
        title=""
        for i in range(0,num_words):
            result_str = ''.join(random.choice(letters) for i in range(length))
            title+=result_str
            title+=" "
        return title
    def random_id(self):
        return random.randint(0, 10000)
    def random_description(self):
        length=random.randrange(5)
        if (length == 0):
            length += 1
        num_words = random.randrange(4)
        if (num_words == 0):
            num_words += 1
        letters = string.ascii_lowercase
        description=""
        for i in range(0,num_words):
            result_str = ''.join(random.choice(letters) for i in range(length))
            description += result_str
            description+=" "
        return description
    def random_genre(self):
        genres=["romance","school life","psychological","thriller","horror","documentary","historical"]
        return random.choice(genres)
    def random_movie(self):
        movie=Movie(self.random_id(),self.random_name(),self.random_genre(),self.random_description())
        self.__validate_movie.validate(movie)
        try:
            self.__repo_movie.add_movie(movie)
        except:
            self.random_movie()
        return movie

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
