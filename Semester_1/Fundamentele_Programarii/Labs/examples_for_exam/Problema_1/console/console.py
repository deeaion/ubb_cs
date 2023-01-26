from termcolor import colored

from errors.RepoError import RepoError
from errors.ValidError import ValidError


class Console():
    def __init__(self, service_emisiuni):
        self.__serv_e = service_emisiuni
        self.__comenzi={
            "delete":self.__ui_stergere_emisiune,
            "modify":self.__ui_modificare_emisiune,
            "generate":self.__ui_generare_program,
            "block type":self.__ui_blocare_tip,
            "print_all":self.__ui_print_emisiuni
        }
    def __ui_stergere_emisiune(self):
        name=self.__params[0]
        type=self.__params[1]
        self.__serv_e.service_delete_all_by_type(name, type)
    def __ui_modificare_emisiune(self):
        name = self.__params[0]
        type = self.__params[1]
        durata=int(self.__params[2])
        descriere=self.__params[3]
        self.__serv_e.service_modify_by_name_type(name,type,durata,descriere)
    def __ui_generare_program(self):
        ora_inceput=int(self.__params[0])
        ora_sfarsit=int(self.__params[1])
        lista=self.__serv_e.service_generate_program(ora_inceput,ora_sfarsit)
        o="Ora"
        n="Nume"
        t="Tip"
        d="Descriere"
        if(lista is None):
            print("It was imposible to generate such a program!")
            return
        print(f"{o:<4}{n:<10}{t:<7}{d:<10}")
        for el in lista:
            print(el)
    def __ui_blocare_tip(self):
        type = self.__params[0]
        lista=self.__serv_e.service_blocare_emisiune(type)
        if(len(lista)==0):
            print(f"There is no such type as {type}")
        else:
            print("The blocked tv shows are:")
            for el in lista:
                print(el)
    def __ui_print_emisiuni(self):
        lista=self.__serv_e.service_get_all_shows()
        lista_n=[el for el in lista if el.get_blocked_show()==False]
        for el in lista_n:
            print(el)
    def meniu(self):
        while True:
            command=input("Your command is?(delete,modify,generate random program,block type,print_all,exit")
            if command=="":
                continue
            if command=="exit":
                return
            self.__params=[]
            if command=="delete":
                try:
                    name=input("name=\n")
                    type=input("type=\n")
                    self.__params.append(name)
                    self.__params.append(type)
                    self.__comenzi[command]()
                except ValueError:
                    print("Ui Error: Invalid type")
                except ValidError as ve:
                    print(f"Validation Error: {ve}")
                except RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command=="modify":
                try:
                    name=input("name=")
                    type=input("type=")
                    durata=int(input("durata="))
                    descriere=input("descriere=")

                    self.__params.append(name)
                    self.__params.append(type)
                    self.__params.append(durata)
                    self.__params.append(descriere)
                    self.__comenzi[command]()
                except ValueError:
                    print("Ui Error: Invalid type")
                except ValidError as ve:
                    print(f"Validation Error: {ve}")
                except RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command == "generate":
                try:
                    ora_inceput =int(input("The hour when it begins="))
                    ora_sfarsit= int(input("The hour when it end="))


                    self.__params.append(ora_inceput)
                    self.__params.append(ora_sfarsit)
                    self.__comenzi[command]()
                except ValueError:
                    print("Ui Error: Invalid type")
                except ValidError as ve:
                    print(f"Validation Error: {ve}")
                except RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command=="block type":
                try:
                    type=input("type=\n")
                    self.__params.append(type)
                    self.__comenzi[command]()
                except ValueError:
                    print("Ui Error: Invalid type")
                except ValidError as ve:
                    print(f"Validation Error: {ve}")
                except RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command=="print_all":
                try:
                    self.__comenzi[command]()
                except ValueError:
                    print("Ui Error: Invalid type")
                except ValidError as ve:
                    print(f"Validation Error: {ve}")
                except RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command not in self.__comenzi:
                print(colored("Invalid Command!",'red'))
                continue






    def run(self):
        #importa datele din fisier
        self.__serv_e.service_get_all_shows_file()
        print("All data has been imported!")
        #meniu
        self.meniu()

