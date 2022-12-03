from Persistent_Memory.file_repo_client import FileRepoClients
from Persistent_Memory.file_repo_movie import FileRepoMovie
from Persistent_Memory.repo_rentals import RepoRentals
from domain.domain_rentals import Rental


#class FileRepoRentals(RepoRentals,FileRepoClients,FileRepoMovie):
class FileRepoRentals(RepoRentals,RepoClients,RepoMovie):
    def __init__(self,path_to_file):
        RepoRentals.__init__(self)
        FileRepoClients.__init__(self,"clients.txt")
        FileRepoMovie.__init__(self,"movies.txt")
        self.__path_to_file=path_to_file

    def add_rental_f(self,rental):
        self.__read_all_from_file()
        RepoRentals.add_rental(self,rental)
        self.__write_all_to_file()
    def get_all(self):
        self.__read_all_from_file()
        return RepoRentals.get_all(self)
    def __read_all_from_file(self):
        with open(self.__path_to_file,"r") as f:
            lines=f.readlines()
            for line in lines:
                line=line.strip()
                if line!="":
                    parts=line.split("")
                    id_rental=int(parts[0])
                    id_client = int(parts[1])
                    id_movie = int(parts[2])
                    days=int(parts[3])
                    ###
                    client=FileRepoClients.search_client_by_id(self,id_client)
                    movie=FileRepoMovie.search_movie_by_id(self,id_movie)
                    ###
                    rental=Rental(id_rental,client,movie,days)
                    self._rentals[id_rental]=rental

    def __write_all_to_file(self):
        with open(self.__path_to_file,"w") as f:
            for rental in self._rentals.values():
                ###deci eu iau un rental dar vreau sa il scriu in fisier ca id,idc,idr,days
                id_rental=rental.get_id_rental()
                print(id_rental)
                client=rental.get_client()
                id_client=client.get_id_client()
                print(id_client)
                movie=rental.get_movie()
                id_movie=movie.get_id_movie()
                days=rental.get_days_rental()
                f.write(str(id_rental)+", "+str(id_client)+", "+str(id_movie)+", "+str(days)+"\n")


