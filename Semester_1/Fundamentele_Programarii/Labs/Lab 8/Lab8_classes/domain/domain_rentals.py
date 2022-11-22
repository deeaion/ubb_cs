class Rental:
    def __init__(self,id_rental,client,movie,rental_time):
        self.__id_rental=id_rental
        self.__client= client
        self.__movie=movie
        self.__rental=rental_time #aici ti cate zile are clientul voie sa aiba filmul rented
        self.__deleted=False

    def get_deleted(self):
        return self.__deleted
    def get_id_rental(self):
        return self.__id_rental
    def get_movie(self):
        return self.__movie

    def get_client(self):
        return self.__client
    def get_days_rental(self):
        return self.__rental
    def delete(self):
        self.__deleted=True
    def set_new_client(self,client):
        self.__client=client
    def set_new_movie(self,movie):
        self.__movie=movie
    def __equ__(self,other):
        return self.__id_rental==other.__id_rental or (self.__client==other.__client and self.__movie==other.__movie)
    def __str__(self):
        return f"Rental id:{self.__id_rental}\nDays rented:{self.__rental}\nClient that has rented it:{self.__client}\nThe movie rented:{self.__movie}"