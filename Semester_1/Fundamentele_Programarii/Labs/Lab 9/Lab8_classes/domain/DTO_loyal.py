class Loyal_DTO:
    def __init__(self,name,number_of_rentals):
        self.__name=name
        self.__number_of_rentals=number_of_rentals



    def get_name(self):
        return self.__name
    def get_number_of_rentals(self):
        return self.__number_of_rentals

    def __str__(self):
        return f"Client name: {self.__name}\nnumber_of_rentals: {self.__number_of_rentals}"
