from domain.domain_client import Client
from infrastuctura.repo_client import RepoClient


class Serv_tests:
    def __init__(self):
        pass
    def service_tests(self):
        self.serv_test_c()
        self.serv_test_m()
        self.serv_test_r()
    def serv_test_c(self):
        self.addc()
        self.modc()
        self.sec()
    def serv_test_m(self):
        self.addm()
        self.modm()
        self.sem()

    def serv_test_r(self):
        self.addr()
        self.modr()
        self.ser()
        self.delc()
        self.delm()
        self.modc()
        self.modm()
    def addc(self):
        rtc = RepoClient()
        id = 25
        name = "Do I work"
        CNP = "2880918378050"
        client = Client(id, name, CNP)
        



    def delc(self):
        pass

    def modc(self):
        pass

    def sec(self):
        pass

    def addm(self):
        pass

    def modm(self):
        pass

    def sem(self):
        pass

    def addr(self):
        pass

    def modr(self):
        pass

    def ser(self):
        pass

    def delm(self):
        pass

