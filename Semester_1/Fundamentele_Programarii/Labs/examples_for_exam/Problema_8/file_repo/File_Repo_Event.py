from domain.Event import Event
from repo.Repository_Event import RepoEvent


class FileRepoEvent(RepoEvent):
    def __init__(self,path):
        RepoEvent.__init__(self)
        self.__path = path
    def add_event(self,event):
        RepoEvent.add_event(self,event)
        self.__write_all_to_file()
    def read_all_from_file(self):
        with open(self.__path,"r") as f:
            lines=f.readlines()
            for line in lines:
                if line!="":
                    line.strip()
                    params=line.split(",")
                    date=params[0]
                    hour=params[1]
                    description=params[2]
                    event=Event(date,hour,description)
                    self._events.append(event)
        return self._events
    def get_all_events(self):
        return self._events
    def __write_all_to_file(self):
        with open(self.__path,"w") as f:
            for el in self._events:
                f.write(str(el))
