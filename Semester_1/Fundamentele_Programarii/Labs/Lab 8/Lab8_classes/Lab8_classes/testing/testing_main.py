class Tests:
    def __init__(self,domain_tests,validator_tests,service_tests,repo_tests):
        self.__d_tests=domain_tests
        self.__v_tests=validator_tests
        self.__s_tests=service_tests
        self.__r_tests=repo_tests
    def run(self):
        print("Running tests....")
        self.__d_tests.domain_tests()
        print("Domains work....")
        self.__v_tests.val_tests()
        print("Validator works....")
        self.__r_tests.repo_tests()
        print("Repo works....")
        self.__s_tests.service_tests()
        print("Service works! Ready to run!")

