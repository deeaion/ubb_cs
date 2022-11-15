from testing.domain_tests.domain_testing_client import *
from testing.domain_tests.domain_testing_movies import *
from testing.repo_tests.repo_testing_client import *
from testing.repo_tests.repo_testing_movie import *
from testing.services_tests.services_client_testing import *
from testing.services_tests.services_movie_testing import *
from testing.validation_tests.validate_client_tests import validate_client_tests
from testing.validation_tests.validate_movies_tests import validate_movies_tests


def run_domain_client_tests():
    create_client_tests()
    equal_client_tests()

def run_domain_movies_tests():
    create_movies_tests()
    equal_movies_tests()

def run_repo_client_tests():
    add_to_client_list_test()
    modify_client_tests()
    delete_client_tests()
    search_client_tests()
    add_to_client_movie_list_test()
    delete_movie_from_movie_list_of_client_test()
def run_repo_movies_tests():
    add_to_movies_list_test()
    modify_movie_tests()
    delete_movie_tests()
    search_movie_tests()

def run_services_movies_tests():
    add_movie_services_test()
    modify_movie_services_test()
    search_movie_services_test()
    delete_movie_services_test()

def run_services_client_tests():
    add_client_service_test()
    modify_client_service_test()
    delete_client_service_test()
    search_client_service_test()
    add_movie_to_client_list_service_test()
    delete_movie_from_client_list_service_test()
def run_ui_tests():
    pass

def run_functions_tests():
    pass


def run_validation_tests():
    validate_client_tests()
    validate_movies_tests()


def run_tests():
    run_domain_client_tests()
    print("Teste domain_client trecute cu succes")
    run_domain_movies_tests()
    print("Teste domain_movies trecute cu succes")
    run_repo_client_tests()
    print("Teste repo_clients trecute cu succes")
    run_repo_movies_tests()
    print("Teste repo_clients trecute cu succes")
    run_validation_tests()
    print("Teste validare trecute cu succes")
    run_services_client_tests()
    print("Teste service client trecute cu succes")
    run_services_movies_tests()
    print("Teste service movies trecute cu succes")
    run_functions_tests()
    run_ui_tests()

