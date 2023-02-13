class ValidatingMovie:
    def __init__(self):
        pass

    def validate(self, movie):
        errors=""
        if movie.get_id_movie()<=0:
            errors+="invalid id\n"
        if movie.get_name_movie()=="":
            errors+="invalid name\n"
        if movie.get_genre_movie()=="":
            errors+="invalid genre\n"
        if movie.get_description_movie()=="":
            errors+="invalid description\n"
        if len(errors)>0:
            raise ValueError(errors)