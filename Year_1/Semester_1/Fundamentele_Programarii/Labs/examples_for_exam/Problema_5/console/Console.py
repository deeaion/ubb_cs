from Errors.RepoError import RepoError
from Errors.ValidError import ValidError


class Console():
    def __init__(self,service_products):

        self.__serv_prod=service_products
        self.__comenzi={
            "add":self.__ui_add_product,
            "delete": self.__ui_delete_by_cifra,
            "filter_change":self.__ui_filter_change,
            "undo":self.__ui_undo
        }
        self.__filter_string=""
        self.__number=-1
        self.stack=[]

    def __ui_add_product(self):
        id=int(self.__params[0])
        name = self.__params[1]
        price = float(self.__params[2])
        self.__serv_prod.add_product(id,name,price)

    def __ui_delete_by_cifra(self):
        cifra=int(self.__params[0])
        self.__serv_prod.update_undo(self.stack,cifra)
        self.__serv_prod.delete_by_digit(cifra)


    def __ui_filter_change(self):
        self.__filter_string=self.__params[1]
        self.__number=float(self.__params[0])
        self.__serv_prod.filter_produs(self.__filter_string,self.__number)
        print(f"Filter was changed to: string ={self.__filter_string} and number={self.__number}")
    def __ui_undo(self):
        self.__serv_prod.undo(self.stack)
    def __ui_current_filter(self):
        print(f"Current filter: string ={self.__filter_string} and number={self.__number}")
        lista=self.__serv_prod.filter_produs(self.__filter_string,self.__number)
        #lista=self.__serv_prod.filter(self.__filter_string,self.__number)
        for el in lista:
            print(el)
    def __ui_print(self):
        list=self.__serv_prod.get_all_products()
        for el in list:
            print(el)
    def __ui_menu(self):
        while True:
            self.__ui_current_filter()
            command=input("Give command( Command can be: add, delete, filter_change, undo and exit!)")
            if (command=="exit"):
                return
            if (command==""):
                continue
            self.__params=[]
            if command=="add":
                try:
                    id=int(input("Enter id: "))
                    name=input("Enter the item's name:")
                    price=float(input("Enter the price:"))
                    self.__params.append(id)
                    self.__params.append(name)
                    self.__params.append(price)
                    self.__comenzi[command]()
                except ValueError:
                    print ("UI ERROR!")
                except ValidError as ve:
                    print(f"Validator Error: {ve}")
                except  RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command == "delete":
                try:

                    cifra = int(input("Enter the digit: "))
                    self.__params.append(cifra)
                    self.__comenzi[command]()
                except ValueError:
                    print("UI ERROR!")
                except ValidError as ve:
                    print(f"Validator Error: {ve}")
                except  RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command == "filter_change":
                try:

                    number = float(input("Enter number: "))
                    string = input("Enter the string:")
                    self.__params.append(number)
                    self.__params.append(string)
                    self.__comenzi[command]()
                except ValueError:
                    print("UI ERROR!")
                except ValidError as ve:
                    print(f"Validator Error: {ve}")
                except  RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command == "undo":
                try:
                    self.__comenzi[command]()
                except ValueError:
                    print("UI ERROR!")
                except ValidError as ve:
                    print(f"Validator Error: {ve}")
                except  RepoError as ve:
                    print(f"Repository Error: {ve}")
            if command not in self.__comenzi:
                print("Invalid Command!")
    def run(self):
        print("Data has been imported!")
        self.__serv_prod.get_all_products()
        self.__ui_menu()



