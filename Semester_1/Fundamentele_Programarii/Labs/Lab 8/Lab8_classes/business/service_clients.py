import string
from random import random

from domain.domain_client import Client
class ServiceClients:
    def __init__(self,validating_client,repo_client):
      self.__validating_client=validating_client
      self.__repo_client=repo_client
    def random_name(self):
        lenght= random.randint(1, 30)
        letters = string.ascii_lowercase
        result_str = ''.join(random.choice(letters) for i in range(length))
    def random_id(self):
        random.randint(0, 9)
    def random_cnp(self):
        pass
    def random_client_generator(self):
        pass
    def add_client(self,id_client,name_client,CNP_client):
        client=Client(id_client,name_client,CNP_client)
        self.__validating_client.validate(client)
        self.__repo_client.add_client(client)
    def modify_client(self,id_client,name_client,CNP_client):
        client=Client(id_client,name_client,CNP_client)
        self.__validating_client.validate(client)
        self.__repo_client.modify_client(client)
    def search_client_by_id(self,id_client):
        return self.__repo_client.search_client_by_id(id_client)
    #delete is in rentals
    def get_all_clients(self):
        return self.__repo_client.get_all()