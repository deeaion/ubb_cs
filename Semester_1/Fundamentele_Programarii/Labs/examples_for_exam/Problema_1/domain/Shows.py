class Show:
    def __init__(self,name,type,time,description,blocked):
        self.__blocked = blocked
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
    def get_blocked_show(self):
        return self.__blocked
    def set_name_show(self,name):
        self.__name=name
    def set_type_show(self,type):
        self.__type=type
    def set_time_show(self,time):
        self.__time=time
    def set_description_show(self,description):
        self.__description=description
    def set_blocked_show(self,blocked):
        self.__blocked=blocked
    def __eq__(self,other):
        return self.__name==other.__name and self.__type==other.__type
    def __str__(self):
        return f"{self.__name},{self.__type},{self.__time},{self.__description}"
