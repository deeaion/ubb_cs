class Event():
    def __init__(self,date,hour,description):
        self.__description = description
        self.__hour = hour
        self.__date = date
    def get_date_event(self):
        return self.__date
    def get_hour_event(self):
        return self.__hour
    def get_description_event(self):
        return self.__description
    def __eq__(self,other):
        return self.__hour==other.__hour and self.__date==other.__date
    def __str__(self):
        return f"{self.__date},{self.__hour},{self.__description}"
