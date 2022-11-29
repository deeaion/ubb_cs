class ValidatingRentals:
    def __init__(self):
        pass

    def validate(self, rental):
        errors=[]
        if(rental.get_id_rental()<=0):
            errors+="invalid id"
        if(rental.get_days_rental()<=0):
            errors+="invalid days"
        if(len(errors)>0):
            raise ValueError (errors)
