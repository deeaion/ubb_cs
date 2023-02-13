class DTO:
    def __init__(self,time,name,type,description):
        self.__description = description
        self.__time = time
        self.__type = type
        self.__name = name

    def get_name_show(self):
        return self.__name
    def get_type_show(self):
        return self.__type
    def get_time_show(self):
        return self.__time
    def get_description_show(self):
        return self.__description
    def __str__(self):
        return f"{self.__time:<4}{self.__name:<10}{self.__type:<7}{self.__description:<10}"