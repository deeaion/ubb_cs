from console.Console import Console
from file_repo.File_Repo_Event import FileRepoEvent
from service.Service_Event import ServiceEvents
from validators.Validator import ValidatorEvent

if __name__=='__main__':
    path= "events.txt"
    validator_event=ValidatorEvent()
    repo_events=FileRepoEvent(path)
    service_events=ServiceEvents(repo_events,validator_event)
    UI=Console(service_events)
    UI.run()

