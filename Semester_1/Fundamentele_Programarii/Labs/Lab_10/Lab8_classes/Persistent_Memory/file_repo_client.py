from Persistent_Memory.repo_client import RepoClient
from domain.domain_client import Client


class FileRepoClients(RepoClient):
    def __init__(self, path_to_file):
        RepoClient.__init__(self)
        self.__path_to_file_clients=path_to_file
    def add_client(self,client):
        self.__read_all_from_file()
        RepoClient.add_client(self,client)
        self.__write_all_to_file()
    def modify_client(self,client):
        self.__read_all_from_file()
        RepoClient.modify_client(self,client)
        self.__write_all_to_file()
    def delete_client_by_id(self,id_client):
        self.__read_all_from_file()
        RepoClient.delete_client_by_id(self,id_client)
        self.__write_all_to_file()
    def get_all(self):
        self.__read_all_from_file()
        return RepoClient.get_all(self)
    def search_client_by_id_f(self,id_client):
        self.__read_all_from_file()
        RepoClient.search_client_by_id(self,id_client)
    def len(self):
        self.__read_all_from_file()
        RepoClient.len(self)
        return RepoClient.len(self)
    def __read_all_from_file(self):
        self._clients.clear()  # sterge datele fisierulu
        with open(self.__path_to_file_clients, "r") as f: #deschide fisierul pentru citire
            lines=f.readlines() #citeste liniile

            for line in lines:
                line=line.strip()
                if line!="":
                    parts=line.split(", ")
                    id_client=int(parts[0])
                    name=parts[1]
                    CNP=parts[2]
                    client=Client(id_client,name,CNP)
                    self._clients[id_client]=client


    def __write_all_to_file(self):
        with open(self.__path_to_file_clients, "w") as f:
            for client in self._clients.values():
                f.write(str(client)+"\n")


