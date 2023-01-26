import unittest


class TestsWithSetupA(unittest.TestCase):
    def setUp(self) :
        self.event=Event("23.01.2022","22:10","HEY")
        self.event_gresit=Event("")
    def tearDown(self) :
        pass
