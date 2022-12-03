class ValidatingClient:
    def __init__(self):
        pass


    def validate(self,client):
        errors=""
        if client.get_id_client()<0:
            errors+="id invalid\n"
        if client.get_name_client()=="":
            errors+="invalid name\n"
        if len(client.get_CNP_client())!=13:
            errors+="CNP invalid\n"
        if len(errors)>0:
            raise ValueError(errors)