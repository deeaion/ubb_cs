
from Persistent_Memory.file_repo_client import FileRepoClients
from Persistent_Memory.file_repo_movie import FileRepoMovie
from Persistent_Memory.file_repo_rentals import FileRepoRentals
from Persistent_Memory.repo_rentals import RepoRentals
from validation.validate_client import ValidatingClient
from validation.validate_movie import ValidatingMovie
from business.service_movies import ServiceMovies
from business.service_clients import ServiceClients
from prezentare.UI import UI
from validation.validate_rentals import ValidatingRentals
from business.service_rentals import ServiceRentals
if __name__=='__main__':
    path_to_file_clients="clients.txt"
    path_to_file_movies="movies.txt"
    path_to_file_rentals="rentals.txt"
    repo_client_f = FileRepoClients(path_to_file_clients)
    repo_movie_f = FileRepoMovie(path_to_file_movies)
    repo_rentals_f = FileRepoRentals(path_to_file_rentals)
    repo_rentals=RepoRentals()
    validating_client=ValidatingClient()
    validating_movie=ValidatingMovie()
    validating_rentals=ValidatingRentals()
    service_client=ServiceClients(validating_client,repo_client_f)
    service_movie=ServiceMovies(validating_movie,repo_movie_f)
    service_rentals=ServiceRentals(validating_rentals,repo_rentals,repo_client_f,repo_movie_f,validating_client,validating_movie,repo_rentals_f)
    UI=UI(service_movie,service_client,service_rentals)
    UI.run()