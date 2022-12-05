import unittest
from unittest import TestCase

from Persistent_Memory.file_repo_client import FileRepoClients
from Persistent_Memory.file_repo_movie import FileRepoMovie
from Persistent_Memory.file_repo_rentals import FileRepoRentals
from Persistent_Memory.repo_client import RepoClient
from Persistent_Memory.repo_movie import RepoMovie
from Persistent_Memory.repo_rentals import RepoRentals
from business.service_clients import ServiceClients
from business.service_movies import ServiceMovies
from business.service_rentals import ServiceRentals
from domain.DTO_file_rentals import Rental_DTO_file
from domain.DTO_most_rents import Most_Rents_DTO
from domain.domain_client import Client
from domain.domain_movie import Movie
from domain.domain_rentals import Rental
from errors.repo_error import RepoError
from validation.validate_client import ValidatingClient
from validation.validate_movie import ValidatingMovie
from validation.validate_rentals import ValidatingRentals


class TestWithSetupA(unittest.TestCase):
    def setUp(self) :
           #client, client_repo
            self.val_c=ValidatingClient()
            self.repo_c=RepoClient()
            self.client=Client(1, "Client", "1234567891011")
            self.client_r=self.repo_c.add_client(self.client)
           #movie,movie_repo
            self.val_m = ValidatingMovie()
            self.repo_m = RepoMovie()
            self.movie = Movie(23, "Movie", "movie genre", "movie description")
            self.movie_n = Movie(23, "NMovie", "nmovie genre", "nmovie description")
            self.movie_i=Movie(5,"iamnothere","i","dk")
            self.movie_r = self.repo_m.add_movie(self.movie)
          #rentals
            self.val_r=ValidatingRentals()
            self.rental=Rental(2,self.client,self.movie,32)
          #dto
            self.DTO=Most_Rents_DTO(1,"Movie",2312)


    def tearDown(self) :
            pass
    def remove_all(self,path):
            with open(path,"w"):
                pass
        #DOMAIN#
    def test_domain(self):
            ##client##
        self.assertTrue(self.client.get_id_client(),1)
        self.assertEqual(self.client.get_CNP_client(),"1234567891011")
        self.assertEqual(self.client.get_name_client(),"Client")

        ##movie##
        self.assertEqual(self.movie.get_id_movie(),23)
        self.assertEqual(self.movie.get_name_movie(),"Movie")
        self.assertEqual(self.movie.get_genre_movie(),"movie genre")
        self.assertEqual(self.movie.get_description_movie(),"movie description")
        self.assertEqual(self.movie,self.movie)
        ##domain rentals##
        self.assertEqual(self.rental.get_id_rental(), 2)
        self.assertEqual(self.rental.get_movie(), self.movie)
        self.assertEqual(self.rental.get_client(), self.client)
        self.assertEqual(self.rental.get_days_rental(), 32)
        self.assertEqual(self.rental,self.rental)
        ##domain DTO##

        self.assertEqual(self.DTO.get_id_client(),1)
        self.assertEqual(self.DTO.get_movie_name(),"Movie")
        self.assertEqual(self.DTO.get_number_of_rentals(),2312)
         ###validator##
        #VAL#
    def test_val_c(self):
        self.val_c.validate(self.client)
        try:
            self.val_c.validate(Client(-5,"",""))
            assert False
        except ValueError as ve:
            pass
    def test_val_m(self):
        self.val_m.validate(self.movie)
        try:
            self.val_m.validate(Movie(-1,"","",""))
            assert False
        except ValueError:
            pass
    def test_val_r(self):
        self.val_r.validate(self.rental)
        try:
            self.val_r.validate(Rental(-6, self.client, self.movie, -21))
            assert False
        except ValueError:
            pass

    #repo_test#
    #repo c#
    #TESTE REPOS#
    def test_add_c(self):
        self.assertEqual(self.repo_c.len(),1)
        self.assertRaises(RepoError,self.repo_c.add_client,self.client)
    def test_modify_c(self):
        self.assertEqual(self.repo_c.len(), 1)
        client_m=Client(1, "I am new", "1234567891011")
        self.repo_c.modify_client(client_m)
        found = self.repo_c.search_client_by_id(1)
        self.assertEqual(found,client_m)
        self.assertEqual(self.repo_c.search_client_by_id(1).get_id_client(),1)
        self.assertEqual(self.repo_c.search_client_by_id(1).get_name_client(), "I am new")
        self.assertEqual(self.repo_c.search_client_by_id(1).get_CNP_client(),"1234567891011")
        client_na = Client(5, "nothere", "1234567891011")
        self.assertRaises(RepoError,self.repo_c.modify_client,client_na)
    def test_search_c(self):
        found = self.repo_c.search_client_by_id(1)
        self.assertEqual(found,self.client)
        self.assertRaises(RepoError, self.repo_c.search_client_by_id, 5)
    def test_delete_c(self):
        self.assertEqual(self.repo_c.len(), 1)
        self.repo_c.delete_client_by_id(1)
        self.assertEqual(self.repo_c.len(), 0)
        self.assertRaises(RepoError, self.repo_c.delete_client_by_id, 5)
    #repo__m#
    def test_add_m(self):
        self.assertEqual(self.repo_m.len(), 1)
        self.assertRaises(RepoError, self.repo_m.add_movie, self.movie)
    def test_modify_movie(self):
        self.assertEqual(self.repo_m.len(), 1)
        self.repo_m.modify_movie(self.movie_n)
        found = self.repo_m.search_movie_by_id(23)
        self.assertEqual(found, self.movie_n)
        #movie_m=Movie(23, "NMovie", "nmovie genre", "nmovie description")
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_id_movie(), 23)
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_name_movie(), "NMovie")
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_genre_movie(), "nmovie genre")
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_description_movie(), "nmovie description")
        self.assertRaises(RepoError, self.repo_m.modify_movie, self.movie_i)
    def test_search_movie(self):
        self.assertEqual(self.repo_m.len(), 1)
        found = self.repo_m.search_movie_by_id(23)
        self.assertEqual(found, self.movie)
        self.assertRaises(RepoError, self.repo_m.search_movie_by_id, 5)
    def test_delete_testsm(self):
        self.assertEqual(self.repo_m.len(), 1)
        self.repo_m.delete_movie_by_id(23)
        self.assertEqual(self.repo_m.len(),0)
        self.assertRaises(RepoError,self.repo_m.delete_movie_by_id,2)
            #repof_m#
class TestWithSetupB(unittest.TestCase):
    def setUp(self):
        # client, client_repo
        self.path_c=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
        self.remove_all(self.path_c)
        self.repo_c = FileRepoClients(self.path_c)
        self.client = Client(1, "Client", "1234567891011")
        self.client_m=Client(1, "I am new", "1234567891011")
        self.client_i=Client(5, "nothere", "1234567891011")
        self.client_r = self.repo_c.add_client(self.client)
        # movie,movie_repo
        self.path_m=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        self.remove_all(self.path_m)
        self.repo_m = FileRepoMovie(self.path_m)
        self.movie = Movie(23, "Movie", "movie genre", "movie description")
        self.movie_n = Movie(23, "NMovie", "nmovie genre", "nmovie description")
        self.movie_i = Movie(5, "iamnothere", "i", "dk")
        self.movie_r = self.repo_m.add_movie(self.movie)
        # rentals
        self.val_r = ValidatingRentals()
        self.path_rentals=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_rentals.txt"
        self.remove_all(self.path_rentals)
        self.repo_rm=RepoRentals(self.path_rentals)
        self.repo_rf=FileRepoRentals(self.path_rentals)
        self.rental = Rental(2, self.client, self.movie, 32)
        # dto
        self.dto = Rental_DTO_file(2, 1, 23, 32)
        self.rental_add=self.repo_rm.add_rental(self.rental,self.dto)

    def remove_all(self,path):
            with open(path,"w"):
                pass
    def tearDown(self):
        pass
            ###FILES###
    def test_rentals(self):

        self.assertEqual(self.repo_rm.len(),1)
        self.assertEqual(self.repo_rf.len(), 1)
        self.assertRaises(RepoError,self.repo_rm.add_rental,self.rental,self.dto)
        self.assertRaises(RepoError,self.repo_rm.search_rental_by_id,25)
        found=self.repo_rm.search_rental_by_id(2)
        self.assertEqual(found,self.rental)
        self.repo_rm.delete_rental_by_id(2)
        self.assertEqual(self.repo_rm.len(),0)
        self.assertRaises(RepoError,self.repo_rm.delete_rental_by_id,5)
        self.assertEqual(self.repo_rf.len(),0)
    def test_files_clients(self):
        self.assertEqual(self.repo_c.len(),1)
        self.repo_c.modify_client(self.client_m)
        found = self.repo_c.search_client_by_id(1)
        self.assertEqual(found, self.client_m)
        self.assertEqual(self.repo_c.search_client_by_id(1).get_id_client(), 1)
        self.assertEqual(self.repo_c.search_client_by_id(1).get_name_client(), "I am new")
        self.assertEqual(self.repo_c.search_client_by_id(1).get_CNP_client(), "1234567891011")
        client_na = Client(5, "nothere", "1234567891011")
        self.assertRaises(RepoError, self.repo_c.modify_client, client_na)
        self.repo_c.delete_client_by_id(1)
        self.assertEqual(self.repo_c.len(), 0)
    def test_movies_files(self):
        self.assertEqual(self.repo_m.len(), 1)
        self.assertRaises(RepoError, self.repo_m.add_movie, self.movie)
        self.repo_m.modify_movie(self.movie_n)
        found = self.repo_m.search_movie_by_id(23)
        self.assertEqual(found, self.movie_n)
        # movie_m=Movie(23, "NMovie", "nmovie genre", "nmovie description")
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_id_movie(), 23)
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_name_movie(), "NMovie")
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_genre_movie(), "nmovie genre")
        self.assertEqual(self.repo_m.search_movie_by_id(23).get_description_movie(), "nmovie description")
        self.assertRaises(RepoError, self.repo_m.modify_movie, self.movie_i)
        found = self.repo_m.search_movie_by_id(23)
        self.assertEqual(found, self.movie)
        self.assertRaises(RepoError, self.repo_m.search_movie_by_id, 5)
        self.repo_m.delete_movie_by_id(23)
        self.assertEqual(self.repo_m.len(), 0)
        self.assertRaises(RepoError, self.repo_m.delete_movie_by_id, 2)
            #SERVICE REPOS#
class TestWithSetupC(unittest.TestCase):

    #SERVICE
    def setUp(self):
        # client, client_repo
        self.path_c=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_clients.txt"
        self.remove_all(self.path_c)
        self.val_c = ValidatingClient()
        self.repo_c = FileRepoClients(self.path_c)
        self.service_c=ServiceClients(self.val_c,self.repo_c)
        self.client = self.service_c.add_client(1, "Client", "1234567891011")
        #clientm(1, "I am new", "1234567891011")
        #clienti: self.client_i=Client(5, "nothere", "1234567891011")
        # movie,movie_repo
        self.path_m=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_movies.txt"
        self.remove_all(self.path_m)
        self.val_m = ValidatingMovie()
        self.repo_m = FileRepoMovie(self.path_m)
        self.service_m = ServiceMovies(self.val_m, self.repo_m)
        self.movie = self.service_m.add_movie(23, "Movie", "movie genre", "movie description")
        #self.movie_n = Movie(23, "NMovie", "nmovie genre", "nmovie description")
        #self.movie_i = Movie(5, "iamnothere", "i", "dk")
        # rentals
        self.val_r = ValidatingRentals()
        self.path_rentals=r"C:\Users\Deea\Desktop\DOCUMENTS\UNI\github\uni_homeworks\Semester_1\Fundamentele_Programarii\Labs\Lab_10\Lab8_classes\testing\test_rentals.txt"
        self.remove_all(self.path_rentals)
        self.repo_rm=RepoRentals(self.path_rentals)
        self.repo_rf=FileRepoRentals(self.path_rentals)
        self.service_r=ServiceRentals(self.val_r,self.repo_rm,self.repo_c,self.repo_m,self.val_c,self.val_m,self.repo_rf)
        self.rental = self.service_r.add_rental(2, 1, 23, 32)
        # dto
        self.dto = Rental_DTO_file(2, 1, 23, 32)
    def remove_all(self,path):
            with open(path,"w"):
                pass
    def tearDown(self):
        pass
    def test_service_clients(self):
        self.assertEqual(self.service_c.len(),1)
        self.assertTrue(self.service_c.search_client_by_id(1).get_id_client(), 1)
        self.assertEqual(self.service_c.search_client_by_id(1).get_CNP_client(), "1234567891011")
        self.assertEqual(self.service_c.search_client_by_id(1).get_name_client(), "Client")
        self.assertRaises(ValueError,self.service_c.add_client,-5,"","2")
        self.assertRaises(RepoError,self.service_c.search_client_by_id,2)
        self.assertRaises(RepoError,self.service_c.add_client,1,"Client","1234567891011")
        found=self.service_c.search_client_by_id(1)
        self.assertEqual(self.client,found)
            # linked to serv_m
    def test_movie(self):
        self.assertEqual(self.service_m.len(), 1)
        self.assertEqual(self.service_m.search_movie_by_id(23).get_id_movie(), 23)
        self.assertEqual(self.service_m.search_movie_by_id(23).get_name_movie(), "Movie")
        self.assertEqual(self.service_m.search_movie_by_id(23).get_genre_movie(), "movie genre")
        self.assertEqual(self.service_m.search_movie_by_id(23).get_description_movie(), "movie description")
        self.assertRaises(ValueError, self.service_m.add_movie, -5, "", "","")
        self.assertRaises(RepoError, self.service_m.search_movie_by_id, 2)
        self.assertRaises(RepoError, self.service_m.add_movie, 23, "Movie", "movie genre","movie description")
        found = self.service_m.search_movie_by_id(23)
        self.assertEqual(self.movie, found)

    def test_rentals_service(self):
        self.assertEqual(self.service_r.len(), 1)
        self.assertEqual(self.service_r.search_rental(2).get_id_rental(), 2)
        self.assertEqual(self.service_r.search_rental(2).get_client(), self.client)
        self.assertEqual(self.service_r.search_rental(2).get_movie(), self.movie)
        self.assertEqual(self.service_r.search_rental(2).get_days_rental(), 32)
        self.assertRaises(RepoError, self.service_r.add_rental, 2,self.rental, self.dto,32)
        self.assertRaises(RepoError, self.service_r.search_rental, 25)
        self.service_r.delete_rental(2)
        self.assertEqual(self.service_r.len(), 0)

    def test_delc(self):
        self.assertEqual(self.service_c.len(), 1)
        self.assertTrue(self.service_c.search_client_by_id(1).get_id_client(), 1)
        new=self.service_r.modify_client_and_rental(1,"I AM NEW","1234567891011")
        found=self.service_c.search_client_by_id(1)
        self.assertEqual(new,found)
        self.assertTrue(self.service_c.search_client_by_id(1).get_id_client(), 1)
        self.assertEqual(self.service_c.search_client_by_id(1).get_CNP_client(), "1234567891011")
        self.assertEqual(self.service_c.search_client_by_id(1).get_name_client(), "I AM NEW")
        self.service_r.delete_client_and_rentals(1)
        self.assertEqual(self.service_r.len(),0)
        self.assertEqual(self.service_c.len(), 0)
        self.assertRaises(RepoError,self.service_c.search_client_by_id,1)

    def test_del_and_mod_m(self):
        self.assertEqual(self.service_m.len(), 1)
        new = self.service_r.modify_movie_and_rental(23, "I AM NEW", "gere", "tutu")
        found = self.service_m.search_movie_by_id(23)
        self.assertEqual(new, found)
        self.assertTrue(self.service_m.search_movie_by_id(23).get_id_movie(), 23)
        self.assertEqual(self.service_m.search_movie_by_id(23).get_name_movie(), "I AM NEW")
        self.assertEqual(self.service_m.search_movie_by_id(23).get_genre_movie(), "gere")
        self.assertTrue(self.service_m.search_movie_by_id(23).get_description_movie(), "tutu")
        self.service_r.delete_movie_and_rentals(23)
        self.assertEqual(self.service_r.len(), 0)
        self.assertEqual(self.service_m.len(), 0)
        self.assertRaises(RepoError, self.service_m.search_movie_by_id,23)
if __name__=='__main__':
    unittest.main()
