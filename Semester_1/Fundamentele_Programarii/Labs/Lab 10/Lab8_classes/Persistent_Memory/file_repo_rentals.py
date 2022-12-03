from domain.DTO_file_rentals import Rental_DTO_file

class FileRepoRentals():
    def __init__(self,path_to_file):
        self.__path_to_file=path_to_file
        self._dto_list={}

    def add_rental_file(self,rental):
        self.__read_all_from_file()
        self._dto_list[rental.get_id_rental()]=rental
        self.__write_all_to_file()
        print(self._dto_list)
    def delete_rental_file(self,id_rental):
        self.__read_all_from_file()
        #if self.__dto_list[id_rental] not in self.__dto_list:
          #  raise RepoError("rental not in file")
        del self._dto_list[id_rental]
        self.__write_all_to_file()
    def get_all(self):
        self.__read_all_from_file()
        rentals_dto = []
        for id in self._dto_list:
            rentals_dto.append(self._dto_list[id])
        return rentals_dto
    def __read_all_from_file(self):
        with open(self.__path_to_file,"r") as f:
            lines=f.readlines()
            self._dto_list.clear()
            for line in lines:
                line=line.strip()
                if line!="":
                    parts=line.split(", ")
                    id_rental=int(parts[0])
                    id_client = int(parts[1])
                    id_movie = int(parts[2])
                    days=int(parts[3])
                    DTO_rental=Rental_DTO_file(id_rental,id_client,id_movie,days)
                    self._dto_list[DTO_rental.get_id_rental()]=DTO_rental
    def __write_all_to_file(self):
        with open(self.__path_to_file, 'w'):
            pass
        with open(self.__path_to_file,"a") as file:
            for dto in self._dto_list.values():
                file.write(str(dto)+"\n")


