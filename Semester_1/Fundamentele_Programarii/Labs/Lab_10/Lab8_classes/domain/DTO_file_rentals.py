class Rental_DTO_file:
    def __init__(self,id_rental,id_client,id_movie,rental_time):
        self.__id_rental=id_rental
        self.__id_client= id_client
        self.__id_movie=id_movie
        self.__rental=rental_time #aici ti cate zile are clientul voie sa aiba filmul rented
        self.__deleted=False

    def get_deleted(self):
        return self.__deleted
    def get_id_rental(self):
        return self.__id_rental
    def get_id_movie(self):
        return self.__id_movie
    def get_id_client(self):
        return self.__id_client
    def get_days_rental(self):
        return self.__rental
    def __equ__(self,other):
        return self.__id_rental==other.__id_rental
    def __str__(self):
        return f"{self.__id_rental}, {self.__id_client}, {self.__id_movie}, {self.__rental}"
