from domain.Shows import Show
from repo.repo_emisiuni import RepoEmisiuni


class FileRepoEmisiuni(RepoEmisiuni):
    def __init__(self,filerepo):
        self.__path=filerepo
        RepoEmisiuni.__init__(self)
    def delete_show_type_and_name(self,name,type):
        RepoEmisiuni.delete_show_type_and_name(self,name,type)
        self.__write_all_to_file()
        return self._shows
    def modify_show_name_type(self,new_show):
        RepoEmisiuni.modify_show_name_type(self,new_show)
        self.__write_all_to_file()
    def search_by_name_type(self,name,type):
        return RepoEmisiuni.search_show_type_and_name(self, name, type)

    def read_all_from_file(self):
        self._shows.clear()
        with open(self.__path,"r") as f:
            lines=f.readlines()
            for line in lines:
                line=line.strip()
                if line!="":
                    params=line.split(",")
                    nume=params[0]
                    tip=params[1]
                    durata=int(params[2])
                    descriere=params[3]
                    show=Show(nume,tip,durata,descriere,False)
                    self._shows.append(show)
            return self._shows
    def __write_all_to_file(self):
        with open(self.__path,"w") as f:
            for el in self._shows:
                f.write(str(el)+"\n")
        return self._shows

    def get_all_shows(self):
        return RepoEmisiuni.get_all_shows(self)
    def len(self):
        pass

