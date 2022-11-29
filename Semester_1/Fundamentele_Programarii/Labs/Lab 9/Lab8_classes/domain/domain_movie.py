class Movie:
    def __init__(self,id_movie,name_movie,genre_movie,description_movie):
        self.__id_movie=id_movie
        self.__name_movie=name_movie
        self.__genre_movie=genre_movie
        self.__description_movie=description_movie
        self.__deleted=False
    def deleted(self):
        self.__deleted=True
    def get_id_movie(self):
        return self.__id_movie
    def get_name_movie(self):
        return self.__name_movie
    def get_genre_movie(self):
        return self.__genre_movie
    def get_description_movie(self):
        return self.__description_movie
    def set_name_movie(self,name_movie):
        self.__name_movie=name_movie
    def set_genre_movie(self,genre_movie):
        self.__genre_movie=genre_movie
    def set_description_movie(self,description_movie):
        self.__description_movie=description_movie
    def __eq__(self,other):
        return self.__id_movie==other.__id_movie
    def __str__(self):
        return f"Movie id: {self.__id_movie}\nName of the movie: {self.__name_movie}\nThe genre: {self.__genre_movie}\n Description: {self.__description_movie}"