import unittest

from domain.Device import Device
from domain.Operatiune import Operation


class Test1(unittest.TestCase):
    def setUp(self):
        self.__device=Device("iPhone X","phone","Apple",50,"supply")
        self.__operation=Operation("iPhone X","phone",50,"supply")
        self.path_to_file=r"C:\Users\Deea\PycharmProjects\IonAndreea\testing\file_test.txt"
    def tearDown(self):
        pass
    def test_domain(self):
        self.assertEqual(self.__device.get_model_device(),"iPhone X")
        self.assertEqual(self.__device.get_type_device(), "phone")
        self.assertEqual(self.__device.get_brand_device(), "Apple")
        self.assertEqual(self.__device.get_nr_devices(), 50)
        self.assertEqual(self.__device.get_nr_operation(),"supply")
        self.assertEqual(self.__operation.get_model_device(),"iPhone X")
        self.assertEqual(self.__operation.get_type_device(),"phone")
        self.assertEqual(self.__operation.get_nr_devices(),50)
        self.assertEqual(self.__operation.get_nr_operation(),"supply")
    def test_repo(self):
        pass
    def test_service(self):
        pass
