class Client:
    def __init__(self,id_client,name_client,CNP_client):
        self.__id_client=id_client
        self.__name_client=name_client
        self.__CNP_client=CNP_client
        self.__deleted= False
    def get_id_client(self):
        return self.__id_client
    def get_name_client(self):
        return self.__name_client
    def get_CNP_client(self):
        return self.__CNP_client

    def set_name_client(self,name_client):
        self.__name_client= name_client
    def set_CNP_client(self,CNP_client):
        self.__CNP_client= CNP_client
    def __eq__(self,other):
        return self.__id_client==other.__id_client or self.__CNP_client==other.__CNP_client
    def __str__(self):
        return f"{self.__id_client}, {self.__name_client}, {self.__CNP_client}"