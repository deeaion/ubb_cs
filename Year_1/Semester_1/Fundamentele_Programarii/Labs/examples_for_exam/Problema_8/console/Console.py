import datetime
from datetime import date

from errors.RepoError import RepoError
from errors.ValidError import ValidError


class Console():
    def __init__(self,service_event):
        self.__serv_e = service_event
        self.__commands={"add":self.__ui_add_event,
                         "change_reminder":self.__ui_change_reminder,
                         "export":self.__ui_export}
        self.__date_shown=""
    def __ui_add_event(self):
        date=self.__params[0]
        hour=self.__params[1]
        description=self.__params[2]
        self.__serv_e.add_event(date,hour,description)
    def __ui_reminder(self):
        lista = self.__serv_e.sort_by_day(self.__date_shown)
        for el in lista:
            print(el)
    def __ui_change_reminder(self):
        self.__date_shown=self.__params[0]
        print("Reminder changed!")
    def __ui_export(self):
        fisier=self.__params[0]
        sir=self.__params[1]
        list=self.__serv_e.export(fisier,sir)

    def menu(self):
        while True:
            print(f"Events for {self.__date_shown}:")
            self.__ui_reminder()
            command=input("Dati comanda: (add,change_reminder,export,exit)")
            command.strip()
            if command=="exit":
                return
            if command=="":
                continue
            self.__params=[]
            if command not in self.__commands:
                print("Invalid Command")
                continue
            if command=="add":
                try:
                    print("You choosed to add an event:")
                    date=input("date=")
                    hour=input("hour=")
                    description=input("description=")
                    self.__params.append(date)
                    self.__params.append(hour)
                    self.__params.append(description)
                    self.__commands[command]()
                except ValueError as ve:
                    print(f"Ui error")
                except ValidError as ve:
                    print(f"Validator error: {ve}")
                except RepoError as ve:
                    print(f"Repo error: {ve}")
            if command=="change_reminder":
                try:
                    print("You choosed to change your reminder:")
                    date=input("date=")
                    self.__params.append(date)
                    self.__commands[command]()
                except ValueError as ve:
                    print(f"Ui error")
                except ValidError as ve:
                    print(f"Validator error: {ve}")
                except RepoError as ve:
                    print(f"Repo error: {ve}")
            if command=="export":
                try:
                    print("You choosed to export certain events:")
                    name=input("name_of_file=")
                    description=input("description=")

                    self.__params.append(name)
                    self.__params.append(description)
                    self.__commands[command]()
                except ValueError as ve:
                    print(f"Ui error")
                except ValidError as ve:
                    print(f"Validator error: {ve}")
                except RepoError as ve:
                    print(f"Repo error: {ve}")


    def __ui_current_events(self):
        Date=datetime.datetime.now()
        day=Date.day
        month=str(Date.month)
        year=Date.year
        if len(month)==1:
            month="0"+month
        self.__date_shown="".join(str(day)+"."+str(month)+"."+str(year))


    def run(self):
        lista=self.__serv_e.get_all_file()
        #import all from file

        self.__ui_current_events()
        self.menu()


