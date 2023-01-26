from Errors.RepoError import RepoError


class RepoProducts():
    def __init__(self):
        self._products={}
    def get_all_products(self):
            list=[]
            for id in self._products:
                list.append(self._products[id])
            return list

    def add_product(self,product):
        if product.get_id_product() in self._products:
            raise RepoError("Product with the same id already exist")
        self._products[product.get_id_product()]=product
    def delete_product(self,id):
        if id not in self._products:
            raise RepoError("Product does not exist")
        del self._products[id]
