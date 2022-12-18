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
        return random.randint(0, 10000)
    def random_cnp(self):
        lenght=13
        numbers=['0','1','2','3','4','5','6','7','8','9']
        result_str=''.join(random.choice(numbers) for i in range(lenght))
        return result_str
    def random_client_generator(self):
        client=Client(self.random_id(), self.random_name(), self.random_cnp())
        self.__validating_client.validate(client)
        try:
            self.__repo_client.add_client(client)
        except:
            self.random_client_generator()
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

    def merge_sort(self, arr, key=None, reverse=False, cmp=None):
        if len(arr) <= 1:
            return arr
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        left_s = self.merge_sort(left, key=key, reverse=reverse, cmp=cmp)
        right_s = self.merge_sort(right, key=key, reverse=reverse, cmp=cmp)
        return self.merge(arr, left_s, right_s, key=key, reverse=reverse, cmp=cmp)

    def merge(self, array, left, right, key=None, reverse=False, cmp=None):
        """
            aici avem interclasarea

        :param array:
        :param left: vectorul din stanga
        :param right: vectorul din dreapta
        :param key: conteaza daca avem cheia sau nu caci daca avem cheie sortarea trebuie facuta dupa cheie. daca nu dupa obiectul insusi
        :param reverse:  stabileste cum le compara! daca el e true trebuie sa verifice daca a>b si ordoneaza deci descrescator
        :param cmp: e ca in asm. returneaza numar neg daca a<b
                                            0         daca a=b
                                            numar poz daca a>b
        :return: returneaza vectorii interclasati
        """
        result = []
        left_index = 0 #index vector stang
        right_index = 0 #index vector drept
        #FIRST AND FIRST CREEAM UN COMPARATOR . De ce avem nevoie de el? din cauza parametriilor in plus
        #prima oara trebuie sa vedem daca sortam dupa o cheie ca atunci se complica lucruriile
        if key is not None:
            #verficam cum va fi ordinea
            if reverse:
                comparator = lambda x, y: key(y) > key(x)
            else:
                comparator = lambda x, y: key(x) > key(y)
        #aici cmp normal e x<y si daca avem reverse trebuie sa avem inversul
        elif cmp is not None:
            if reverse:
                comparator = lambda x, y: -cmp(x, y)
            else:
                comparator = cmp
        #daca nu avem nici cmp atunci avem doar dupa reverse sau fara reverse
        else:
            if reverse:
                comparator = lambda x, y: y >x
            else:
                comparator = lambda x, y: x <y

            # merge the two halves until one of them is exhausted
        while left_index < len(left) and right_index < len(right):
            if comparator(left[left_index], right[right_index]) <= 0:
                result.append(left[left_index])
                left_index += 1
            else:
                result.append(right[right_index])
                right_index += 1

            # add the remaining elements, if any, from the left half
            #extend adauga toate elementele de undeva
        result.extend(left[left_index:])

            # add the remaining elements, if any, from the right half
        result.extend(right[right_index:])

        return result

    def sort_by_name(self):
        the_clients=[]
        the_clients = self.get_all_clients()
        the_clients_s = self.merge_sort(the_clients, key=lambda x: x.get_name_client())
        return the_clients_s

    #delete is in rentals
    def get_all_clients(self):
        return self.__repo_client.get_all()
    def len(self):
        return self.__repo_client.len()