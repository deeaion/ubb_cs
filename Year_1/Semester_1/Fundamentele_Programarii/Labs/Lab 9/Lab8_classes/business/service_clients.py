import string
import random
from domain.domain_client import Client
class ServiceClients:
    def __init__(self,validating_client,repo_client):
      self.__validating_client=validating_client
      self.__repo_client=repo_client
    def random_name(self):
        length= random.randrange(30)
        if(length==0):
            length+=1
        letters = string.ascii_lowercase
        result_str = ''.join(random.choice(letters) for i in range(length))
        return result_str
    def random_id(self):
        return random.randint(0, 345)
    def random_cnp(self):
        lenght=13
        numbers=['0','1','2','3','4','5','6','7','8','9']
        result_str=''.join(random.choice(numbers) for i in range(lenght))
        return result_str
    def random_client_generator(self):
        client=Client(self.random_id(), self.random_name(), self.random_cnp())
        self.__validating_client.validate(client)
        self.__repo_client.add_client(client)
        return client
    def add_client(self,id_client,name_client,CNP_client):
        client=Client(id_client,name_client,CNP_client)
        self.__validating_client.validate(client)
        self.__repo_client.add_client(client)
        return client
    def modify_client(self,id_client,name_client,CNP_client):
        client=Client(id_client,name_client,CNP_client)
        self.__validating_client.validate(client)
        self.__repo_client.modify_client(client)
    def search_client_by_id(self,id_client):
        return self.__repo_client.search_client_by_id(id_client)

    def sort_by_name(self):
        the_clients=[]
        the_clients=self.get_all_clients()
        the_clients_s=sorted(the_clients, key=lambda x: x.get_name_client())
        return the_clients_s

    #delete is in rentals
    def get_all_clients(self):
        return self.__repo_client.get_all()