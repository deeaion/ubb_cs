from domain.Produs import Product
from repository.Repository_Produs import RepoProducts


class FileRepoProducts(RepoProducts):
    def __init__(self,path):
        self.__path=path
        RepoProducts.__init__(self)
    def __read_from_file(self):
        with open(self.__path,"r") as f:
            lines=f.readlines()
            for line in lines:
                if line!="":
                    line.strip()
                    params=line.split(",")
                    id=int(params[0])
                    name=params[1]
                    price=float(params[2])
                    product=Product(id,name,price)
                    self._products[id]=product
    def __write_to_file(self):
        with open(self.__path,"w") as f:
            for el in self._products.values():
                f.write(str(el)+"\n")
    def get_all_products(self):
        self.__read_from_file()
        return RepoProducts.get_all_products(self)
    def add_product(self,product):
        self.__read_from_file()
        RepoProducts.add_product(self,product)
        self.__write_to_file()
    def delete_product(self,id):
        RepoProducts.delete_product(self,id)
        self.__write_to_file()
