from domain.Produs import Product


class ServiceProducts():
    def __init__(self,repo,valid):
        self.__repo = repo
        self.__valid = valid

    def add_product(self,id,name,price):
        product=Product(id,name,price)
        self.__valid.validator(product)
        self.__repo.add_product(product)
    def get_all_products(self):
        return self.__repo.get_all_products()
    def delete_by_digit(self,digit):
        if digit<0 or digit>9:
            raise ValueError("Can't be a digit")
        lista=self.__repo.get_all_products()
        respecta=[]
        for el in lista:
            id=el.get_id_product()
            ok=0
            while(id!=0):
                if(id%10==digit):
                    ok=1
                id/=10
            if (ok==1):
                respecta.append(el)
        for el in respecta:
            self.__repo.delete_product(el.get_id_product())
        return len(respecta)
    def update_undo(self,stack,params):
        list=self.__repo.get_all_products()
        digit=params

        lista_d=[x for x in list if str(digit) in str(x.get_id_product())]
        lista_de_sters=[]
        for i in lista_d:
            lista_de_sters.append(i)
        if len(lista_de_sters)!=0:
            stack.append(lista_de_sters)
        else:
            stack.append([])
    def undo(self,stack):
        if len(stack)==0:
            raise ValueError("Can't undo anymore")
        lista=stack.pop()
        for i in lista:
            self.__repo.add_product(i)


    def filter_produs(self,string,digit):
        lista=self.__repo.get_all_products()
        final=[]
        if string == "" and digit == -1:
            return lista
        for el in lista:
            if string=="" and digit!=-1:
                if el.get_price_product()-digit<0:
                    final.append(el)
            if string!="" and digit==-1:
                if string in el.get_name_product():
                    final.append(el)
            if string!="" and digit!=-1:
                if string in el.get_name_product() and el.get_price_product()<digit:
                    final.append(el)
        return final


