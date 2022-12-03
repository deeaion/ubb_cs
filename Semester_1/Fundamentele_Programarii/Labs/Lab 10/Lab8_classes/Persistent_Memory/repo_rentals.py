from Persistent_Memory.file_repo_rentals import FileRepoRentals
from errors.repo_error import RepoError


class RepoRentals(FileRepoRentals):
    def __init__(self):
        FileRepoRentals.__init__(self,"rentals.txt")
        self._rentals={}
    def add_rental(self,rental,DTO):
        if rental.get_id_rental() in self._rentals:
            raise RepoError("Rental existent")
            return
        self._rentals[rental.get_id_rental()]=rental
        FileRepoRentals.add_rental_file(self,DTO)
    def delete_rental_by_id(self,id_rental):
        if id_rental not in self._rentals:
            raise RepoError("Rental nonexistent")
            return
        del self._rentals[id_rental]
        FileRepoRentals.delete_rental_file(self,id_rental)

    def search_rental_by_id(self,id_rental):
        if id_rental not in self._rentals:
            raise RepoError("Rental nonexistent")
        return self._rentals[id_rental]
    def modify_rental(self,rental):
        if rental.get_id_rental() not in self._rentals:
            raise RepoError("Rental nonexistent")
        self._rentals[rental.get_id_rental()]=rental
    def get_all(self):
        rentals=[]
        for id in self._rentals:
            rentals.append(self._rentals[id])
        return rentals
    def len(self):
        return len(self._rentals)