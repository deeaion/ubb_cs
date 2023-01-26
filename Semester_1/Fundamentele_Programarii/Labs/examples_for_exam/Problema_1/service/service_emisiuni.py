import random

from domain.DTO import DTO
from domain.Shows import Show
from errors.ValidError import ValidError


class ServiceEmisiuni:
    def __init__(self,validator,repo):
        self.__repo_em = repo
        self.__val_em = validator
    def service_get_all_shows_file(self):
        return self.__repo_em.read_all_from_file()

    def service_get_all_shows(self):
        return self.__repo_em.get_all_shows()
    def service_delete_all_by_type(self,name,type):
        lista=self.__repo_em.delete_show_type_and_name(name,type)
        return lista
    def service_modify_by_name_type(self,name,type,time,description):
        show_vechi=self.__repo_em.search_by_name_type(name,type)
        new_show=Show(name,type,time,description,show_vechi.get_blocked_show())
        return self.__repo_em.modify_show_name_type(new_show)
    def service_blocare_emisiune(self,type):
        if type=='':
            raise ValidError("Invalid type!")
        lista=[el for el in self.__repo_em.get_all_shows() if el.get_type_show()==type]
        if(len(lista)==0):
            return []
        for el in lista:
            new_show = Show(el.get_name_show(), type,el.get_time_show(), el.get_description_show(),True)
            self.__repo_em.modify_show_name_type(new_show)
        return lista
    def service_generate_program(self,ora_inceput,ora_sfarsit):
        lista=[el for el in self.__repo_em.get_all_shows() if el.get_blocked_show()==False]
        list=[0]*len(lista)
        lista_fol=[]
        rez=[]
        oi=ora_inceput
        os=ora_sfarsit
        oc=oi
        fol=0
        nr=-2
        fol=0
        while oc<os and fol!=len(lista) and len(lista_fol)!=len(lista):

            nr = random.randint(0, len(lista) - 1)
            while (nr not in lista_fol):
                lista_fol.append(nr)
                if list[nr]==0 and oc+lista[nr].get_time_show()<=os:
                    show=DTO(oc,lista[nr].get_name_show(),lista[nr].get_type_show(),lista[nr].get_description_show())
                    rez.append(show)
                    list[nr]=1
                    oc=oc+lista[nr].get_time_show()
                fol=0
                for l in list:
                    if l==1:
                        fol+=1

        if(oc==os):
            return rez
        if fol==len(lista):
            folnou=0
            lista_fol.clear()
            foll=[0]*len(lista)
            while oc!=os and folnou!=len(lista) and len(lista_fol)!=len(lista) :
                if oc > os:
                    ult_time=rez[-1].get_time_show()
                    rez.pop()
                    oc=oc-ult_time
                nr = random.randint(0, len(lista) - 1)
                while nr not in lista_fol:
                    if (foll[nr]==3 or foll[nr]==-3):
                        lista_fol.append(nr)
                    if foll[nr]<3 and oc + lista[nr].get_time_show() <= os:
                        show = DTO(oc, lista[nr].get_name_show(), lista[nr].get_type_show(),"****")
                        rez.append(show)
                        oc = oc + lista[nr].get_time_show()
                        foll[nr] += 1
                    else:
                        foll[nr]=-3
                    for l in foll:
                        if l == 3 or l==-3:
                            folnou += 1
            if (oc == os):
                return rez
            if(folnou==len(lista)):
                return []


