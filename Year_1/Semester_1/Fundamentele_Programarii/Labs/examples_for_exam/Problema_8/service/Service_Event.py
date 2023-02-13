import datetime

from domain.Event import Event


class ServiceEvents():
    def __init__(self,repo_events,validator_events):
        self.__validator_events = validator_events
        self.__repo_events = repo_events
    def sort_by_day(self,date):
        lista=[x for x in self.__repo_events.get_all_events() if x.get_date_event()==date]
        list_sorted=sorted(lista,key= lambda x:x.get_hour_event())
        return list_sorted
    def add_event(self,date,time,description):
        event=Event(date,time,description)
        self.__validator_events.validating(event)
        self.__repo_events.add_event(event)
    def get_all_file(self):
        return self.__repo_events.read_all_from_file()
    def export(self,fisier,subsir):
        lista=[x for x in self.__repo_events.get_all_events() if subsir in x.get_description_event()]
        lista_sortata=sorted(lista,key=lambda x:(datetime.datetime.strptime(x.get_date_event(),'%d.%m.%Y'),x.get_hour_event()))
        with open(fisier,"w") as f:
            for el in lista_sortata:
                f.write(str(el))
