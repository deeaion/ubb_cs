from domain.DTO_loyal import Loyal_DTO
from domain.DTO_most_rents import Most_Rents_DTO
from domain.DTO_name_rents import Name_Rents_DTO
from domain.domain_client import Client
from domain.domain_movie import Movie
from domain.domain_rentals import Rental


class ServiceRentals:
    def __init__(self, validate_rental, repo_rental,repo_client,repo_movie,validate_client,validate_movie):
        self.__validate_rental = validate_rental
        self.__repo_rental = repo_rental
        self.__repo_client=repo_client
        self.__repo_movie=repo_movie
        self.__validate_client=validate_client
        self.__validate_movie=validate_movie

    def delete_client_and_rentals(self,id_client):
        client=self.__repo_client.search_client_by_id(id_client) #returns one student
        rentals=self.__repo_rental.get_all()
        client_rentals = [r for r in rentals if r.get_client()==client]
        for client_rental in client_rentals:
            self.__repo_rental.delete_rental_by_id(client_rental.get_id_rental())
        self.__repo_client.delete_client_by_id(id_client)
    def delete_movie_and_rentals(self,id_movie):
        movie=self.__repo_movie.search_movie_by_id(id_movie)
        rentals=self.__repo_rental.get_all()
        movies_rented=[r for r in rentals if r.get_movie()==movie]
        for movie_rented in movies_rented:
            self.__repo_rental.delete_rental_by_id(movie_rented.get_id_rental())
        self.__repo_movie.delete_movie_by_id(id_movie)
    def delete_rental(self,id_rental):
        self.__repo_rental.delete_rental_by_id(id_rental)

    def modify_client_and_rental(self,id_client,name,CNP):
        client=Client(id_client,name,CNP)
        self.__validate_client.validate(client)
        self.__repo_client.modify_client(client)
        rentals=self.__repo_rental.get_all()
        client_rentals = [r for r in rentals if r.get_client() == client]
        for client_rental in client_rentals:
            client_rental.set_new_client(client)
    def modify_movie_and_rental(self,id_movie,name,genre,description):
         movie=Movie(id_movie,name,genre,description)
         self.__validate_movie.validate(movie)
         self.__repo_movie.modify_movie(movie)
         rentals=self.__repo_rental.get_all()
         client_rentals=[r for r in rentals if r.get_movie()==movie]
         for client_rental in client_rentals:
             client_rental.set_new_movie(movie)


    def add_rental(self,id_rental,id_client,id_movie,days_rented):
        client=self.__repo_client.search_client_by_id(id_client)
        movie=self.__repo_movie.search_movie_by_id(id_movie)
        rental=Rental(id_rental,client,movie,days_rented)
        self.__validate_rental.validate(rental)
        self.__repo_rental.add_rental(rental)
        return rental
    def search_rental(self,id_rental):
        return self.__repo_rental.search_rental_by_id(id_rental)
    def most_rentals(self):
        the_movies={}
        rentals=self.__repo_rental.get_all()
        for rental in rentals:
            id_movie=rental.get_movie().get_id_movie()
            if id_movie not in the_movies:
                the_movies[id_movie]=0
            the_movies[id_movie]+=1
        rez=[]
        for id_movie in the_movies:
            name=self.__repo_movie.search_movie_by_id(id_movie).get_name_movie()
            number_of_rentals=the_movies[id_movie]
            Number_of_rentals=Most_Rents_DTO(id_movie,name,number_of_rentals)
            rez.append(Number_of_rentals)
        rez_sorted=sorted(rez, key=lambda x:x.get_number_of_rentals(),reverse=True)
        return rez_sorted[:3]
    def first_30(self):
        people={}
        clients=self.__repo_client.get_all()
        rentals=self.__repo_rental.get_all()
        for rental in rentals:
            id_client=rental.get_client().get_id_client()
            if id_client not in people:
                people[id_client]=0
            people[id_client]+=1
        for client in clients:
            id_client=client.get_id_client()
            if id_client not in people:
                people[id_client]=0
        rez=[]
        for id_client in people:
            name=self.__repo_client.search_client_by_id(id_client).get_name_client()
            number_of_rentals=people[id_client]
            client=Loyal_DTO(name,number_of_rentals)
            rez.append(client)
        rez_s=sorted(rez,key=lambda x:x.get_number_of_rentals(), reverse=True)
        percentage=int(30/100*len(rez_s))
        return rez[:percentage]
    def sort_name_rents(self):
        people={}
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
            id_c=self.__repo_client.search_client_by_id(id_client).get_id_client()
            name = self.__repo_client.search_client_by_id(id_client).get_name_client()
            cnp=self.__repo_client.search_client_by_id(id_client).get_CNP_client()
            number_of_rentals = people[id_client]
            client = Name_Rents_DTO(id_c,name,cnp,number_of_rentals)
            rez.append(client)
        the_clients_s = sorted(rez, key=lambda x: (x.get_name(),x.get_number_of_rentals()))
        return the_clients_s
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
        the_clients_s = sorted(rez, key=lambda x: (x.get_number_of_rentals()))
        return the_clients_s
    def get_all_rentals(self):
        return self.__repo_rental.get_all()