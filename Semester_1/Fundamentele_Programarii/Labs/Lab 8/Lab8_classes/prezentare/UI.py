from errors.repo_error import RepoError
from errors.validation_error import ValidError


class UI():
    def __init__(self,service_movie,service_client,service_rentals):
        self.__service_movie=service_movie
        self.__service_client=service_client
        self.__service_rentals=service_rentals
        self.__commands={
            #1 printing_list
        #done
        "print_clients":self.__ui_print_clients,
        "print_movies":self.__ui_print_movies,
        "print_rentals":self.__ui_print_rentals,
        #2 adding_to_list
        "add_client":self.__ui_add_client,
        "add_movie":self.__ui_add_movie,
        #3 delete
        "delete_client_and_their_rentals":self.__ui_delete_client_and_rentals,
        "delete_movie":self.__ui_delete_movie, #o sa fie in rentals ca stergi id urile alea


        #4 modify
        "modify_client":self.__ui_modify_client,
        "modify_movie":self.__ui_modify_movie,
        #5 search
        "search_for_client":self.__ui_search_client,
        "search_for_movie":self.__ui_search_movie,
        #6 manage list of movies of client
        "client_has_returned": self.__ui_delete_rental,
        "client_has_rented":self.__ui_add_rental,
        #7 reports
        "print_clients_alphabetically":self.__ui_print_by_name_client,
        "print_clients_by_number_of_rented_movies":self.__ui_print_clients_by_movie_number,
        "print_the_most_rented_movies":self.__ui_print_the_most_rented_movies,
        "print_the_first_30%_of_clients":self.__ui_print_the_30_precent,
        "help":self.__ui_help
        "random_client":self.__ui_random_client,
        "random_movie":self.__ui_random_movie
        }
    def __ui_random_client(self):
        if len(self.__params) != 0:
            print("nr paramteri invalid")
            return
        self.__service_client.random_client_generator()
    def __ui_random_movie(self):
        pass
    ####printing######
    #done
    def __ui_print_clients(self):
        if len(self.__params)!=0:
            print("nr paramteri invalid")
            return
        clients=self.__service_client.get_all_clients()
        if len(clients)==0:
            print("There are no clients registered")
            return
        for client in clients:
            print(client)
    #tdone
    def __ui_print_movies(self):
        if len(self.__params) != 0:
            print("nr paramteri invalid")
            return
        movies = self.__service_movie.get_all_movies()
        if len(movies) == 0:
            print("There are no movies registered")
            return
        for movie in movies:
            print(movie)
    #######adding###
    #done
    def __ui_add_client(self):
        if len(self.__params)!=3:
            print("numar parametri invalid")
            return
        id_client=int(self.__params[0])
        name_client=self.__params[1]
        CNP_client=self.__params[2]
        self.__service_client.add_client(id_client,name_client,CNP_client)
    #tdone
    def __ui_add_movie(self):
        if(len(self.__params)!=4):
            print("Invalid number of parameters")
        id_movie=int(self.__params[0])
        name_movie=self.__params[1]
        genre_movie=self.__params[2]
        description_movie=self.__params[3]
        self.__service_movie.add_movie(id_movie,name_movie,genre_movie,description_movie)
    #delete
    #done
    def __ui_delete_client_and_rentals(self):
        if(len(self.__params)!=1):
            print("Invalid number of Parameters")
        id_client=int(self.__params[0])
        self.__service_rentals.delete_client_and_rentals(id_client)
        print("Client and their rentals have been deleted")
    #tdone
    def __ui_delete_movie(self):
        if (len(self.__params) != 1):
            print("Invalid number of Parameters")
        id_movie = int(self.__params[0])
        self.__service_rentals.delete_movie_and_rentals(id_movie)
        print("Movie and the rentals afferent to it have been deleted")
    #####modify####
    #done
    def __ui_modify_client(self):
        if len(self.__params) != 3:
            print("numar parametri invalid")
            return
        id_client = int(self.__params[0])
        name_client = self.__params[1]
        CNP_client = self.__params[2]
        self.__service_rentals.modify_client_and_rental(id_client, name_client, CNP_client)
    #tdone
    def __ui_modify_movie(self):
        if len(self.__params) != 4:
            print("numar parametri invalid")
            return
        id_movie = int(self.__params[0])
        name_movie = self.__params[1]
        genre_movie = self.__params[2]
        description_movie = self.__params[3]
        self.__service_rentals.modify_movie_and_rental(id_movie, name_movie, genre_movie,description_movie)
    ######search#####
    #done
    def __ui_search_client(self):
        if (len(self.__params) != 1):
            print("Invalid number of Parameters")
        id_client = int(self.__params[0])
        client=self.__service_client.search_client_by_id(id_client)
        print(f"Client has been found. Details :{client}")
    #done
    def __ui_search_movie(self):
        if (len(self.__params) != 1):
            print("Invalid number of Parameters")
        id_movie = int(self.__params[0])
        movie=self.__service_movie.search_movie_by_id(id_movie)
        print(f"Movie has been found. Details :{movie}")
    ####manage_rentals#####

    def __ui_delete_rental(self):
        if (len(self.__params) != 1):
            print("Invalid number of Parameters")
        id_rental = int(self.__params[0])
        self.__service_rentals.delete_rental(id_rental)
        print("Rental has been deleted")
    def __ui_add_rental(self):
        if (len(self.__params) != 4):
            print("Invalid number of Parameters")
        id_rental =int(self.__params[0])
        id_client =int(self.__params[1])
        id_movie =int(self.__params[2])
        d_rental =int(self.__params[3])
        self.__service_rentals.add_rental(id_rental, id_client, id_movie, d_rental)
    #print rentals
    def __ui_print_rentals(self):
        if(len(self.__params)!=0):
            print("Invalid number of Parameters")

        rentals=self.__service_rentals.get_all_rentals()
        if(len(rentals)==0):
            print("There are no rentals registered")
        for rental in rentals:
            print(rental)
    ####reports##
    def __ui_print_by_name_client(self):
        pass
    def __ui_print_clients_by_movie_number(self):
        pass
    def __ui_print_the_most_rented_movies(self):
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        rezult=self.__service_rentals.most_rentals()
        print(rezult)
    def __ui_print_the_30_precent(self):
        pass
    ####help#####
    def __ui_help(self):
        pass


    def run(self):
        while True:
            commands=input("\nSpecify your desired command to execute:\n")
            commands.strip()
            if(commands=="exit" or commands=="end"):
                return
            if(commands==""):
                continue
            commands = commands.split("; ")
            for command in commands:
                if(command==""):
                    continue
                if(command=="exit"):
                    return
                parti=command.split(", ")
                nume_comanda=parti[0]
                self.__params=parti[1:]

                if nume_comanda in self.__commands:
                    try:
                        self.__commands[nume_comanda]()
                    except ValueError:
                        print("UI error: invalid numeric type!")
                    except ValidError as ve:
                        print(f"Validation error: {ve}")             #validator errors o sa vezi
                    except RepoError as re:
                        print(f"Repository error: {re}")
                else:
                    print("comanda_invalida")
            # command_name=command[0]
            # if(command_name in self.__commands):
            #     if(command_name=="add_client"):
            #         pass
            # else:
            #     print("Invalid command!!!! ")
            #     h=input("Do you need help? If you want to print the menu with the commands that are available please input y, else input n!\n")
            #     if(h=='y'):
            #         self.__ui_help()
            #     else:
            #         continue