class Product():
    def __init__(self,id,name,price):
        self.__price = price
        self.__name = name
        self.__id = id
    def get_id_product(self):
        return self.__id
    def get_name_product(self):
        return self.__name
    def get_price_product(self):
        return self.__price
    def __eq__(self, other):
        return self.__id==other.__id
    def __str__(self):
        return f"{self.__id},{self.__name},{self.__price}"

