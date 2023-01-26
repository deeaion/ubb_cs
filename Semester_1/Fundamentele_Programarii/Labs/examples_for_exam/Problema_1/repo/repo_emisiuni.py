from errors.RepoError import RepoError


class RepoEmisiuni():
    def __init__(self):
        self._shows=[]

    def get_all_shows(self):
        return self._shows
    def delete_show_type_and_name(self,name,type):
        lenght=self.lenght()
        self._shows=[el for el in self._shows if el.get_name_show()!=name and el.get_type_show()!=type]
        if len(self._shows)==lenght:
            raise RepoError ("Show does not exist")
        for el in self._shows:
            if el.get_name_show()==name and el.get_type_show()==type and el.get_blocked_show()==True:
                raise RepoError ("Show has been blocked")
        return self._shows
    def modify_show_name_type(self,new_show):
        lenght = self.lenght()
        gasit=-1
        for el in range(lenght):
            if new_show.get_name_show()==self._shows[el].get_name_show() and new_show.get_type_show()==self._shows[el].get_type_show():
                if self._shows[el].get_blocked_show()==False:
                    gasit=el
                    self._shows[el]=new_show
                    return self._shows[el]
        if gasit==-1:
            raise RepoError("Show does not exist/Show has been blocked")
    def lenght(self):
        return len(self._shows)

    def search_show_type_and_name(self, name, type):
        lenght = self.lenght()
        gasit = 0
        for el in self._shows:
            if el.get_name_show() == name and el.get_type_show() == type and el.get_blocked_show() == False:
                return el
        else:
            raise RepoError("Show does not exist!")



