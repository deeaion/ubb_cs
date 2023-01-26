
from console.Console import Console
from file_repo.File_Repo_Produs import FileRepoProducts
from service.Service_Produs import ServiceProducts
from validation.Validation_Produs import Validator

if __name__=='__main__':
    path="produse.txt"
    validator_products=Validator()
    repository_products=FileRepoProducts(path)
    service_products=ServiceProducts(repository_products,validator_products)
    UI=Console(service_products)
    UI.run()