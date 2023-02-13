from errors.repo_error import RepoError


class RepoRentals:
    def __init__(self):
        self.__rentals={}

    def add_rental(self,rental):
        if(rental.get_id_rental() in self.__rentals):
            raise RepoError("Rental already exists")
        self.__rentals[rental.get_id_rental()]=rental

    def delete_rental_by_id(self,id_rental):
        if id_rental not in self.__rentals:
            raise RepoError("rental does not exist")
        del self.__rentals[id_rental]
    def search_rental_by_id(self,id_rental):
        if id_rental not in self.__rentals:
            raise RepoError("rental does not exist")
        return self.__rentals[id_rental]
    def modify_rental(self,rental):
        if rental.get_id_rental() not in self.__rentals:
            raise RepoError("rental does not exist")
        self.__rentals[rental.get_id_rental()]=rental
    def get_all(self):
        rentals=[]
        for id_rental in self.__rentals:
            rentals.append(self.__rentals[id_rental])
        return rentals
    def len(self):
        return len(self.__rentals)