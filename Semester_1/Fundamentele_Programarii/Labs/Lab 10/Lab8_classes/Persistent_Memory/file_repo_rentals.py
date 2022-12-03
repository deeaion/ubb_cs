from Persistent_Memory import repo_client, repo_movie
from Persistent_Memory.repo_movie import RepoMovie
from Persistent_Memory.repo_rentals import RepoRentals
from domain.domain_rentals import Rental
from Persistent_Memory.repo_client import RepoClient


class FileRepoRentals(RepoRentals,RepoClient,RepoMovie):
    def __init__(self,path_to_file):
        RepoRentals.__init__(self)
        RepoClient.__init__(self)
        RepoMovie.__init__(self)
        self.__path_to_file=path_to_file

    def add_rental(self,rental):
        self.__read_from_file()
        RepoRentals.add_rental(self,rental)
        self.__write_to_file()
    def modify_rental(self,rental):
        self.__read_from_file()
        RepoRentals.modify_rental(self,rental)
        self.__write_to_file()
    def get_all(self):
        self.__read_from_file()
        return RepoRentals.get_all(self)
    def delete_rental(self,id_rental):
        self.__read_from_file()
        RepoRentals.delete_rental_by_id(self,id_rental)
        self.__write_to_file()
    def search_rental_by_id(self,id_rental):
        self.__read_from_file()
        return RepoRentals.search_rental_by_id(self,id_rental)
    def len(self):
        self.__read_from_file()
        return RepoRentals.len(self)
    def __read_from_file(self):
        with open(self.__path_to_file,"r") as f:
            lines=f.readlines()
            self._rentals.clear()
            for line in lines:
                line=line.strip()
                if(line!=""):
                    parts=line.split(", ")
                    id_rental=int(parts[0])
                    client=parts[1]
                    print(client)
                    movie=parts[2]
                    print(movie)
                    days=int(parts[3])
                    rental=Rental(id_rental,client,movie,days)
                    self._rentals[id_rental]=rental



    def __write_to_file(self):
        with open(self.__path_to_file, "w") as f:
            for rental in self._rentals.values():
                f.write(str(rental) + "\n")


