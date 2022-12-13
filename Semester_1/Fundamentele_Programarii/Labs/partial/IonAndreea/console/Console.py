from errors.RepoError import RepoError
from errors.ValidError import ValidError


class UI():
    def __init__(self,serv_devices,serv_ops):
        self.__serv_ops = serv_ops
        self.__serv_devices = serv_devices
        self.__comenzi = {
            "1": self.__ui_print_by_type,
            "2": self.__ui_find_by_type_and_brand
        }
    #import the services
    #ui_functions
    def __ui_print_by_type(self):
        if len(self.__params)!=1:
            print("Nr parametri invalid")
            return
        type=self.__params[0]
        list=self.__serv_devices.search_by_type(type)
        if(len(list)==0):
            print("There are no devices with that type")
            return
        for device in list:
            print(device)
    def __ui_find_by_type_and_brand(self):
        if len(self.__params) != 2:
            print("Nr parametri invalid")
            return
        type=self.__params[0]
        brand=self.__params[1]
        list=self.__serv_ops.find_type_brand_nr(type,brand)
        print("Numarul de astfel de deviceuri e:")
        print(list)
    def run(self):
            #import data
            self.__serv_ops.get_all_ops()
            self.__serv_devices.get_all_devices()
            print("Data has been imported")

            while True:
                command = input("Spuneti numarul comenzii\n")
                self.__params = []
                if (command == "0"):
                    return
                if command == "1":
                    #we get all data
                    type = (input("type=\n"))
                    self.__params.append(type)
                    print(self.__params)
                    try:
                        self.__comenzi[command]()
                    except ValueError:
                        print("Ui Error: Invalid Numeric type")
                    except RepoError as re:
                        print(f"Repo Error: {re}")
                    except ValidError as ve:
                        print(f"Valid Error: {ve}")
                if command == "2":
                    #get_all_data
                    type = input("type=")
                    brand = input("\nbrand=")
                    self.__params.append(type)
                    self.__params.append(brand)
                    try:
                        self.__comenzi[command]()
                    except ValueError:
                        print("Ui Error: Invalid Numeric type")
                    except RepoError as re:
                        print(f"Repo Error: {re}")
                    except ValidError as ve:
                        print(f"Valid Error: {ve}")
                if (command not in self.__comenzi):
                    print("Comanda invalida")
                    continue