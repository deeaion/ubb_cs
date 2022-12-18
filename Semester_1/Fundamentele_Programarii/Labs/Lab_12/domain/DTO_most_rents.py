class Most_Rents_DTO:
    def __init__(self,id_client,movie,number_of_rentals):
        self.__id_client=id_client
        self.__movie=movie
        self.__number_of_rentals=number_of_rentals


    def get_id_client(self):
        return self.__id_client
    def get_movie_name(self):
        return self.__movie
    def get_number_of_rentals(self):
        return self.__number_of_rentals

    def __str__(self):
        return f"{self.__id_client}, {self.__movie}, {self.__number_of_rentals}"
