

from prezentare.ui_functions import *


def run_ui():
    clients=[]
    movies=[]
    commands_dic={
        #1 printing_list
        "print_clients":ui_print_clients,
        "print_movies":ui_print_movies,
        #2 adding_to_list
        "add_client":ui_add_client,
        "add_movie":ui_add_movie,
        #3 delete
        "delete_client":ui_delete_client,
        "delete_movie":ui_delete_movie,

        #4 modify
        "modify_client":ui_modify_client,
        "modify_movie":ui_modify_movie,
        #5 search
        "search_for_client":ui_search_client,
        "search_for_movie":ui_search_movie,
        #6 manage list of movies of client
        "client_has_returned": ui_delete_movie_from_client,
        "client_has_rented": ui_add_movie_to_client,
        #7 reports
        "print_clients_by_name_of_client":ui_print_by_name_client,
        "print_clients_by_number_of_rented_movies":ui_print_clients_by_movie_number,
        "print_the_most_rented_movies":ui_print_the_most_rented_movies,
        "print_the_first_30%_of_clients":ui_print_the_30_precent,
        "help":ui_help
    }
    while True:
        commands=input(">>>")
        if commands=="":
            continue
        if commands=="exit":
            return
        commands=commands.split("; ")
        for command in commands:
            parti=command.split(", ")
            nume_comanda=parti[0]
            params=parti[1:]
            for param in params:
                param=param.strip()
            if nume_comanda in commands_dic:
                if(len(params)==0):


                    if(nume_comanda=="print_clients"):
                        commands_dic[nume_comanda](clients)
                    elif(nume_comanda=="help"):
                        commands_dic[nume_comanda]()
                    elif(nume_comanda=="print_movies"):
                        commands_dic[nume_comanda](movies)
                    else:
                        commands_dic[nume_comanda](clients,movies)
                if(len(params)==4):
                    if(nume_comanda!="add_client" and nume_comanda!="modify_client"):
                        try:
                            commands_dic[nume_comanda](movies,params)
                        except ValueError as ve:
                            print(ve)
                if(len(params)==2):
                    try:
                        commands_dic[nume_comanda](clients, movies, params)
                    except ValueError as ve:
                        print(ve)
                if(len(params)==1):

                    if(nume_comanda=="delete_client" or nume_comanda=="search_for_client"):
                        try:
                            commands_dic[nume_comanda](clients, params)
                        except ValueError as ve:
                            print(ve)
                    else:
                        try:
                            commands_dic[nume_comanda](clients,movies,params)
                        except ValueError as ve:
                            print(ve)
                if(len(params)>=4 and (nume_comanda=="add_client" or nume_comanda=="modify_client")):
                    try:
                        commands_dic[nume_comanda](clients,movies, params)
                    except ValueError as ve:
                        print(ve)
            else:
                print("comanda invalida!")
