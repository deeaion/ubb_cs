class Name_Rents_DTO:
    def __init__(self,id_client,name,cnp,number_of_rentals):
        self.__id_client=id_client
        self.__name=name
        self.__cnp=cnp
        self.__number_of_rentals=number_of_rentals


    def get_id_client(self):
        return self.__id_client
    def get_name(self):
        return self.__name
    def get_cnp(self):
        return self.__cnp
    def get_number_of_rentals(self):
        return self.__number_of_rentals

    def __str__(self):
        return f"Id_client: {self.__id_client}\nName: {self.__name}\n Cnp:{self.__cnp}\nnumber_of_rentals: {self.__number_of_rentals}"
