from domain.DTO_file_rentals import Rental_DTO_file
from domain.DTO_loyal import Loyal_DTO
from domain.DTO_most_rents import Most_Rents_DTO
from domain.DTO_name_rents import Name_Rents_DTO
from domain.domain_client import Client
from domain.domain_movie import Movie
from domain.domain_rentals import Rental


class ServiceRentals:
    def __init__(self,validating_rentals,repo_rentals,repo_client_f,repo_movie_f,validating_client,validating_movie,repo_rentals_f):
        self.__validate_rental = validating_rentals
        self.__repo_rental = repo_rentals
        self.__repo_client = repo_client_f
        self.__repo_movie = repo_movie_f
        self.__validate_client = validating_client
        self.__validate_movie = validating_movie
        self.__repo_rentals_f=repo_rentals_f
    def get_all_dtos(self):
        return self.__repo_rentals_f.get_all()
    def adding_the_DTOS(self):
        dtos=self.get_all_dtos()
        for dto in dtos:
            id_rental=dto.get_id_rental()
            client=self.__repo_client.search_client_by_id(dto.get_id_client())
            movie=self.__repo_movie.search_movie_by_id(dto.get_id_movie())
            days=dto.get_days_rental()
            rental=Rental(id_rental,client,movie,days)
            self.__repo_rental._rentals[id_rental]=rental

    def delete_client_and_rentals(self, id_client):
        client = self.__repo_client.search_client_by_id(id_client)  # returns one student
        rentals = self.__repo_rental.get_all()
        client_rentals = [r for r in rentals if r.get_client() == client]
        for client_rental in client_rentals:
            self.__repo_rental.delete_rental_by_id(client_rental.get_id_rental())
        self.__repo_client.delete_client_by_id(id_client)

    def delete_movie_and_rentals(self, id_movie):
        movie = self.__repo_movie.search_movie_by_id(id_movie)
        rentals = self.__repo_rental.get_all()
        movies_rented = [r for r in rentals if r.get_movie() == movie]
        for movie_rented in movies_rented:
            self.__repo_rental.delete_rental_by_id(movie_rented.get_id_rental())
        self.__repo_movie.delete_movie_by_id(id_movie)

    def delete_rental(self, id_rental):
        self.__repo_rental.delete_rental_by_id(id_rental)

    def modify_client_and_rental(self, id_client, name, CNP): #aici iar nu modifici
        client = Client(id_client, name, CNP)
        self.__validate_client.validate(client)
        self.__repo_client.modify_client(client)
        rentals = self.__repo_rental.get_all()
        client_rentals = [r for r in rentals if r.get_client() == client]
        for client_rental in client_rentals:
            client_rental.set_new_client(client)
        return client

    def modify_movie_and_rental(self, id_movie, name, genre, description): #aici nu tre sa schimbi fisieru
        movie = Movie(id_movie, name, genre, description)
        self.__validate_movie.validate(movie)
        self.__repo_movie.modify_movie(movie)
        rentals = self.__repo_rental.get_all()
        client_rentals = [r for r in rentals if r.get_movie() == movie]
        for client_rental in client_rentals:
            client_rental.set_new_movie(movie)
        return movie

    def add_rental(self, id_rental, id_client, id_movie, days_rented):
        client = self.__repo_client.search_client_by_id(id_client)
        movie = self.__repo_movie.search_movie_by_id(id_movie)
        rental_for_file=Rental_DTO_file(id_rental,id_client,id_movie,days_rented)
        rental = Rental(id_rental, client, movie, days_rented)
        self.__validate_rental.validate(rental)
        self.__repo_rental.add_rental(rental,rental_for_file)
        return rental

    def search_rental(self, id_rental):
        return self.__repo_rental.search_rental_by_id(id_rental)

    def most_rentals(self):
        the_movies = {}
        rentals = self.__repo_rental.get_all()
        for rental in rentals:
            id_movie = rental.get_movie().get_id_movie()
            if id_movie not in the_movies:
                the_movies[id_movie] = 0
            the_movies[id_movie] += 1
        rez = []
        for id_movie in the_movies:
            name = self.__repo_movie.search_movie_by_id(id_movie).get_name_movie()
            number_of_rentals = the_movies[id_movie]
            Number_of_rentals = Most_Rents_DTO(id_movie, name, number_of_rentals)
            rez.append(Number_of_rentals)
        rez_sorted = self.bingo_sort(rez, key=lambda x: x.get_number_of_rentals(), reverse=True)
        return rez_sorted[:3]

    def first_30(self):
        people = {}
        clients = self.__repo_client.get_all()
        rentals = self.__repo_rental.get_all()
        for rental in rentals:
            id_client = rental.get_client().get_id_client()
            if id_client not in people:
                people[id_client] = 0
            people[id_client] += 1
        for client in clients:
            id_client = client.get_id_client()
            if id_client not in people:
                people[id_client] = 0
        rez = []
        for id_client in people:
            name = self.__repo_client.search_client_by_id(id_client).get_name_client()
            number_of_rentals = people[id_client]
            client = Loyal_DTO(name, number_of_rentals)
            rez.append(client)
        rez_s = sorted(rez, key=lambda x: x.get_number_of_rentals(), reverse=True)
        percentage = int(30 / 100 * len(rez_s))
        return rez[:percentage]

    def sort_name_rents(self):
        people = {}
        clients = self.__repo_client.get_all()
        rentals = self.__repo_rental.get_all()
        for rental in rentals:
            id_client = rental.get_client().get_id_client()
            if id_client not in people:
                people[id_client] = 0
            people[id_client] += 1
        for client in clients:
            id_client = client.get_id_client()
            if id_client not in people:
                people[id_client] = 0
        rez = []
        for id_client in people:
            id_c = self.__repo_client.search_client_by_id(id_client).get_id_client()
            name = self.__repo_client.search_client_by_id(id_client).get_name_client()
            cnp = self.__repo_client.search_client_by_id(id_client).get_CNP_client()
            number_of_rentals = people[id_client]
            client = Name_Rents_DTO(id_c, name, cnp, number_of_rentals)
            rez.append(client)
        the_clients_s = sorted(rez, key=lambda x: (x.get_name(), x.get_number_of_rentals()))
        return the_clients_s
    ###IMPLEMENTING BINGO SORT####
    def bingo_sort(self,lista,key=None,reverse=False,cmp=None):
        '''
        la bingo sort trebuie sa tot dai swap pana cand is sorted e true. Deci pana toata lista e sortata
        facem si o functia auxiliara is_sorted care face comparatia. ea returneaza false imediat cand gaseste contradictia
        in interiorul functiei se face swapul prin a,b=b,a
        cand is sorted e true atunci returnam lista sortata
        de asemenea tinem cont de key reverse si cmp. Acestea vor juca un rol in is sorted cand stabilim comparatia
        functia bingo sort este apelata recursiv pana cand avem rezultatul corect
        Pasi bingo sort:
                se apeleaza recursiv pana cand lista e sortata.
                se verifica daca fiecare vecin sunt in ordine daca nu atunci le face swap si iese din for din is_sorted
                tot se apeleaza bingo_sort pana cand au fost swaped toti termeni in ordinea pe care o doresti
                la final e returnata lista
        Functia este foarte neeficienta ca si complexitate in the Worst CASE are O(n^2)
                                                                  Average Case is O(n^2)
                                                                  Best Case is O(n)
        :param lista:lista pentru sortare
        :param key:daca nu e declarata se sorteaza pur si simplu lista dupa el daca nu dupa cheia respectiva ceea ce ne trebuie si noua
        :param reverse:daca e False ca si prestabilit se sorteaza crescator daca e True atunci e False
        :param cmp: untriggered (None) nu schimba ordinea. daca e setat pai atunci el decide cum sunt comparate item-urile
        :return: lista sortata in raport cu parametrii dati
        '''
        #verificam daca lista e sortata sau nu de fiecare data
        if self.is_sorted(lista,key=key,reverse=reverse,cmp=cmp):
            return lista
        else:
            #facem swap-ul pana cand e sortata
            for i in range(len(lista)-1):
                if not self.is_sorted(lista,key=key,reverse=reverse,cmp=cmp):
                    #daca ti-a dat false atunci faci swap
                    lista[i],lista[i+1]=lista[i+1],lista[i]
            #apelam din nou functia
            return self.bingo_sort(lista,key=key,reverse=reverse,cmp=cmp)
    def is_sorted(self,lista,key=None,reverse=False,cmp=None):
        '''
        functia ajutatoare pentru bingo_sort! Aceasta este cea care face comparatia in functie de parametrii dati cand e apelata
        Pentru acestea trebuie sa facem mai multe if-uri. Functia returneaza false in momentul cand gaseste doi termeni care nu respecta
        comparatia!
        Ea va returna true cand totul e sortat
        :param lista:lista de verificat daca e sortata
        :param key:daca e declarata trebuie sa o luam in considerare si trebuie sa facem key(item) daca nu comparam dupa reverse
        daca e True sau False
        :param reverse:spune cum va fi ordonat sirul ! True- descrescator
                                                       False- crescator
        :param cmp:stabileste comparatia dintre cele doua! daca e mentionata key e ignorat.
        :return:True- lista e sortata
                False- lista nu e sortata
        '''
        if cmp is not None:
            for i in range(len(lista)-1):
                if reverse:#daca avem reverse adica desc
                    if cmp(lista[i+1],lista[i])<0:#cmp returneaza neg daca a<b!
                        return False
                else:
                    if cmp(lista[i],lista[i+1])>0:
                        return False
        else:
            #aici daca nu ai cmp facem verificare cu key
            for i in range(len(lista)-1):
                if key is not None:#daca a fost data o cheie!
                    if reverse:
                        if key(lista[i+1]) > key(lista[i]):
                            return False
                    else:
                        if key(lista[i + 1]) < key(lista[i]):
                            return False
                else:
                    #ramura unde verificam doar reverse :)
                    if reverse:
                        if lista[i]<lista[i+1]:
                            return False
                    else:
                        if lista[i]>lista[i+1]:
                            return False
        return True
    def sort_number_rents(self):
        people = {}
        clients = self.__repo_client.get_all()
        rentals = self.__repo_rental.get_all()
        for rental in rentals:
            id_client = rental.get_client().get_id_client()
            if id_client not in people:
                people[id_client] = 0
            people[id_client] += 1
        for client in clients:
            id_client = client.get_id_client()
            if id_client not in people:
                people[id_client] = 0
        rez = []
        for id_client in people:
            id_c = self.__repo_client.search_client_by_id(id_client).get_id_client()
            name = self.__repo_client.search_client_by_id(id_client).get_name_client()
            cnp = self.__repo_client.search_client_by_id(id_client).get_CNP_client()
            number_of_rentals = people[id_client]
            client = Name_Rents_DTO(id_c, name, cnp, number_of_rentals)
            rez.append(client)
        the_clients_s = self.bingo_sort(rez, key=lambda x: (x.get_number_of_rentals()))
        return the_clients_s

    def unloyal_clients(self):
        people = {}
        clients = self.__repo_client.get_all()
        rentals = self.__repo_rental.get_all()
        for rental in rentals:
            id_client = rental.get_client().get_id_client()
            if id_client not in people:
                people[id_client] = 0
            people[id_client] += 1
        for client in clients:
            id_client = client.get_id_client()
            if id_client not in people:
                people[id_client] = 0
        rez = []
        for id_client in people:
            id_c = self.__repo_client.search_client_by_id(id_client).get_id_client()
            name = self.__repo_client.search_client_by_id(id_client).get_name_client()
            cnp = self.__repo_client.search_client_by_id(id_client).get_CNP_client()
            number_of_rentals = people[id_client]
            client = Name_Rents_DTO(id_c, name, cnp, number_of_rentals)
            rez.append(client)
        the_clients_s = sorted(rez, key=lambda x: (x.get_number_of_rentals()))
        return the_clients_s[:3]

    def get_all_rentals(self):
        return self.__repo_rental.get_all()
    def len(self):
        return self.__repo_rental.len()