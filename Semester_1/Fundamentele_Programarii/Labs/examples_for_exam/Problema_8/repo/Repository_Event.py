class RepoEvent():
    def __init__(self):
        self._events=[]
    def add_event(self,event):
        self._events.append(event)
        return event
