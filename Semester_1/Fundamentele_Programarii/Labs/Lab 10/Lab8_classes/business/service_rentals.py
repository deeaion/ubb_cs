from domain.domain_rentals import Rental


class ServiceRentals:
    def __init__(self,validating_rentals,repo_rentals_f,repo_clients_f,repo_movies_f,validating_client,validating_movie):
        self.__validate_rental = validating_rentals
        self.__repo_rental = repo_rentals_f
        self.__repo_client = repo_clients_f
        self.__repo_movie = repo_movies_f
        self.__validate_client = validating_client
        self.__validate_movie = validating_movie

    def add_rental(self,id_rental,id_client,id_movie,days):
        client = self.__repo_client.search_client_by_id_f(id_client)
        print(client)
        movie = self.__repo_movie.search_movie_by_id_f(id_movie)
        rental = Rental(id_rental, client, movie, days)
        self.__validate_rental.validate(rental)
        self.__repo_rental.add_rental(rental)
        return rental
    def get_all_rentals(self):
        return self.__repo_rental.get_all()