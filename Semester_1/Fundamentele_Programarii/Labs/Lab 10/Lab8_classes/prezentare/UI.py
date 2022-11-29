from errors.repo_error import RepoError
from errors.validation_error import ValidError


class UI():
    def __init__(self,service_movie,service_client,service_rentals):
        self.__service_movie=service_movie
        self.__service_client=service_client
        self.__service_rentals=service_rentals
        self.__commands_men={
            "Print Clients": self.__ui_print_clients,
            "Print Movies": self.__ui_print_movies,
            "Print Rentals": self.__ui_print_rentals,
            "Sort clients by name": self.__ui_print_by_name_client,
            "Sort clients by name and rents": self.__ui_print_name_rents,
            "Sort clients by rents": self.__ui_print_clients_by_movie_number,
            "Top 3 Movies": self.__ui_print_the_most_rented_movies,
            "The 30%": self.__ui_print_the_30_precent,
            "Help": self.__ui_help,
            "Create random client": self.__ui_random_client,
            ###############
            "Delete all Client data": self.__ui_delete_client_and_rentals,
            "Delete all Movie data": self.__ui_delete_movie,  # o sa fie in rentals ca stergi id urile alea
            "Client returned": self.__ui_delete_rental,
            "Search client": self.__ui_search_client,
            "Search Movie": self.__ui_search_movie,
           ########################################
            "Add Client": self.__ui_add_client,
            "Modify Client": self.__ui_modify_client,
            ##################################
            "Add Movie": self.__ui_add_movie,
            "Modify Movie": self.__ui_modify_movie,
            ########
            "Add New Rental": self.__ui_add_rental,
            "Least Rentals":self.__ui_least_rentals
            # 7 reports

        }
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
        "print_clients_by_name_and_rents":self.__ui_print_name_rents,
        "print_clients_by_number_of_rented_movies":self.__ui_print_clients_by_movie_number,
        "print_the_most_rented_movies":self.__ui_print_the_most_rented_movies,
        "print_the_first_30%_of_clients":self.__ui_print_the_30_precent,
        "help":self.__ui_help,
        "random_client":self.__ui_random_client,
        "least_rentals":self.__ui_least_rentals
        }
    def __ui_least_rentals(self):
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        rezult = {}
        rezult = self.__service_rentals.unloyal_clients()
        if(len(rezult)==0):
            print("There are not enough clients to create the report!")
            return
        for rez in rezult:
            print(rez)
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
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        rezu={}
        rezu=self.__service_client.sort_by_name()
        for rez in rezu:
            print(rez)
    def __ui_print_name_rents(self):
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        rezult={}
        rezult=self.__service_rentals.sort_name_rents()
        for rez in rezult:
            print(rez)
    def __ui_print_clients_by_movie_number(self):
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        rezult = {}
        rezult = self.__service_rentals.sort_number_rents()
        for rez in rezult:
            print(rez)
    def __ui_print_the_most_rented_movies(self):
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        rezult={}
        rezult=self.__service_rentals.most_rentals()
        for rez in rezult:
            print(rez)
    def __ui_print_the_30_precent(self):
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        rezult = {}
        rezult = self.__service_rentals.first_30()
        if(len(rezult)==0):
            print("There are not enough clients to create the report!")
            return
        for rez in rezult:
            print(rez)
    ####help#####
    def __ui_help(self):
        if (len(self.__params) != 0):
            print("Invalid number of Parameters")
        print(
            "If you chose the command- menu know that the format is:\n       command_name, parameter_1, parameter_2, parameter 3....\n If you want to enter multiple commands at once put \"; \" between commands except the last one!\n")
        print("Commands:\n")
        print("  print_clients\nprint_movies\nprint_rentals\nadd_client, id, name, cnp\nadd_movie, id, name, genre, description\ndelete_client_and_their_rentals, id_client\ndelete_movie, id_movie\nmodify_client, id_client, new_name, new_cnp\nmodify_movie, id_movie, new_name, new_genre, new_description\nsearch_for_client, id\nsearch_for_movie, id\nclient_has_returned, id_rental\nclient_has_rented, id_rental, id_client, id_movie, number_of_days\nprint_clients_alphabetically\nprint_clients_by_name_and_rents\nprint_clients_by_number_of_rented_movies\nprint_the_most_rented_movies\nprint_the_first_30 % _of_clients\nhelp\nrandom_client\nleast_rentals")
    def __ui_help_menu(self):
        pass
    def command_menu(self):
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
                    print("Invalid command!!!! ")
                    h=input("Do you need help? If you want to print the menu with the commands that are available please input y, else input n!\n")
                    if(h=='y'):
                        self.__ui_help()
                    else:
                        continue
    def menu_name(self):
        while True:
            command=input("Enter the name of the command!\n")
            if command=="exit":
                return
            if command=="end":
                return
            if command=="":
                continue
            self.__params=[]
            command=command.strip()
            if(command=="Print Clients"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Print Movies"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Print Rentals"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Sort clients by name"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Sort clients by name and rents"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if(command=="Sort clients by rents"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command ==  "Top 3 Movies"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command ==  "The 30%"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Help"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Create random client"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if(command=="Least Rentals"):
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if(command=="Delete all Client data" or command=="Delete all Movie data" or command=="Client returned" or command=="Search client" or command=="Search Movie"):
                id=int(input("Enter the id:\n"))
                self.__params.append(id)
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Add Client"):
                id_client=int(input("Enter client id:\n"))
                name=input("Client's name:\n")
                CNP=input("CNP of Client:\n")
                self.__params.append(id_client)
                self.__params.append(name)
                self.__params.append(CNP)
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Modify Client"):
                id_client = int(input("Enter the client's id that you want to modify:\n"))
                name = input("New Client's name:\n")
                CNP = input("New CNP of Client:\n")
                self.__params.append(id_client)
                self.__params.append(name)
                self.__params.append(CNP)
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Add Movie"):
                id_movie = int(input("Enter movie id:\n"))
                name = input("Movie's name:\n")
                genre = input("Genre of movie:\n")
                description=input("Enter description of movie:\n")
                self.__params.append(id_movie)
                self.__params.append(name)
                self.__params.append(genre)
                self.__params.append(description)
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Modify Movie"):
                id_movie = int(input("Enter movie id:\n"))
                name = input("New name for movie:\n")
                genre = input("New genre of movie:\n")
                description = input("Modify description of movie:\n")
                self.__params.append(id_movie)
                self.__params.append(name)
                self.__params.append(genre)
                self.__params.append(description)
                try:
                    self.__commands_men[command]()
                except ValueError:
                    print("UI error: invalid numeric type!")
                except ValidError as ve:
                    print(f"Validation error: {ve}")  # validator errors o sa vezi
                except RepoError as re:
                    print(f"Repository error: {re}")
            if (command == "Add New Rental"):
                id_rental=int(input("Enter the id of the rental:\n"))
                id_client=int(input("The id of the client:\n"))
                id_movie=int(input("The id of the movie:\n"))
                days=int(input("Number of days for rental:\n"))
                self.__params.append(id_rental)
                self.__params.append(id_client)
                self.__params.append(id_movie)
                self.__params.append(days)
                if(command in self.__commands_men):
                    try:
                        self.__commands_men[command]()
                    except ValueError:
                        print("UI error: invalid numeric type!")
                    except ValidError as ve:
                        print(f"Validation error: {ve}")  # validator errors o sa vezi
                    except RepoError as re:
                        print(f"Repository error: {re}")
            if(command not in self.__commands_men):
                print("Invalid command!!!! ")
                h = input(
                    "Do you need help? If you want to print the menu with the commands that are available please input y, else input n!\n")
                if (h == 'y'):
                    self.__ui_help()
                else:
                    continue
    def run(self):
        choice=int(input("What kind of menu do you desire? Enter the number corresponding to your choice.\n1. Command Menu\n2. User-friendly menu where you write the command you want\n3. User-friendly menu where you write the number corresponding to the command\n"))
        if(choice==1):
            self.command_menu()
        if(choice==2):
            self.menu_name()
        if(choice==3):
            pass
        else:
            print("There are only 3 kinds of menu 1, 2 and 3. Please enter a valid number!")

