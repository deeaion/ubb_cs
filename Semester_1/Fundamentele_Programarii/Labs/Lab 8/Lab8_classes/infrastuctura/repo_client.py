from errors.repo_error import RepoError


class RepoClient:
    def __init__(self):
        self.__clients={}
        self.__clients_by_CNP={}


    def add_client(self,client):
        if client.get_id_client() in self.__clients:
            raise RepoError("client existent")
        if client.get_CNP_client() in self.__clients_by_CNP:
            raise RepoError("client existent cu acelasi CNP!")
        self.__clients[client.get_id_client()]=client
        self.__clients_by_CNP[client.get_CNP_client()]=client

    def delete_client_by_id(self,id_client):
        if id_client not in self.__clients:
            raise RepoError("client does not exist")
        #self.__clients[id_client].deleted()
        del self.__clients[id_client]

    def search_client_by_id(self,id_client):
        if id_client not in self.__clients:
            raise RepoError("client does not exist")
        return self.__clients[id_client]
    def modify_client(self,client):
        if client.get_id_client() not in self.__clients or self.__clients[client.get_id_client()].deleted()==True:
            raise RepoError("client does not exist")
        self.__clients[client.get_id_client()]=client
        self.__clients[client.get_CNP_client()]=client
    def get_all(self):
        clients=[]
        for id_client in self.__clients:
            clients.append(self.__clients[id_client])
        return clients
    def len(self):
        return len(self.__clients)