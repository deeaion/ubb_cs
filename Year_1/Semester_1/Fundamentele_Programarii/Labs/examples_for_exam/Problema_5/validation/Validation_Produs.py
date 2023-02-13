from Errors.ValidError import ValidError


class Validator():
    def __init__(self):
        pass
    def validator(self,product):
        error=""
        if product.get_id_product()<=0:
            error+="\n invalid id"
        if product.get_name_product()=="":
            error+="\n invalid name"
        if product.get_price_product()<0.0:
            error+="\n invalid price"
        if len(error)>0:
            raise ValidError(error)