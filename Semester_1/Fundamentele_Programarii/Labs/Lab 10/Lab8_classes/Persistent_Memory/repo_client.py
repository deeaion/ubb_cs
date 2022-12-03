from errors.repo_error import RepoError


class RepoClient:
    def __init__(self):
        self._clients={}


    def add_client(self,client):
        if client.get_id_client() in self._clients:
            raise RepoError("client existent")
        self._clients[client.get_id_client()]=client

    def delete_client_by_id(self,id_client):
        if id_client not in self._clients:
            raise RepoError("client does not exist")
        #self.__clients[id_client].deleted()
        del self._clients[id_client]
    def search_client_by_id(self,id_client):
        if id_client not in self._clients:
            raise RepoError("client does not exist")
        return self._clients[id_client]
    def modify_client(self,client):
        if client.get_id_client() not in self._clients:
            raise RepoError("client does not exist")
        self._clients[client.get_id_client()]=client
    def get_all(self):
        clients=[]
        for id_client in self._clients:
            clients.append(self._clients[id_client])
        return clients
    def len(self):
        return len(self._clients)