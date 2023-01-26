#main
from console.console import Console
from file_repo.file_repo import FileRepoEmisiuni
from service.service_emisiuni import ServiceEmisiuni
from validation.validating import ValidatingEmisiune




if __name__=='__main__':
    path_to_file='emisiuni.txt'
    repo_emisiuni=FileRepoEmisiuni(path_to_file)
    validating_emisiune=ValidatingEmisiune()
    service_emisiuni=ServiceEmisiuni(validating_emisiune,repo_emisiuni)
    UI=Console(service_emisiuni)
    UI.run()