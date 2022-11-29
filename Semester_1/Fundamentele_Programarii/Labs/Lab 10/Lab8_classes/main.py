import random
import string
from testing.domain_tests.main import Domain_tests
from testing.repo_tests.main import Repo_tests
from testing.service_tests.main import Serv_tests
from testing.testing_main import Tests
from testing.val_tests.main import Val_tests
from validation.validate_client import ValidatingClient
from validation.validate_movie import ValidatingMovie
from infrastuctura.repo_movie import RepoMovie
from infrastuctura.repo_client import RepoClient
from business.service_movies import ServiceMovies
from business.service_clients import ServiceClients
from prezentare.UI import UI
from infrastuctura.repo_rentals import RepoRentals
from validation.validate_rentals import ValidatingRentals
from business.service_rentals import ServiceRentals
if __name__=='__main__':
    domain_tests=Domain_tests()
    validator_tests=Val_tests()
    service_tests=Serv_tests()
    repo_tests=Repo_tests()
    tests=Tests(domain_tests,validator_tests,service_tests,repo_tests)
    validating_client=ValidatingClient()
    validating_movie=ValidatingMovie()
    validating_rentals=ValidatingRentals()
    repo_client=RepoClient()
    repo_movie=RepoMovie()
    repo_rentals=RepoRentals()

    service_client=ServiceClients(validating_client,repo_client)
    service_movie=ServiceMovies(validating_movie,repo_movie)
    service_rentals=ServiceRentals(validating_rentals,repo_rentals,repo_client,repo_movie,validating_client,validating_movie)
    UI=UI(service_movie,service_client,service_rentals)
    tests.run()
    UI.run()
