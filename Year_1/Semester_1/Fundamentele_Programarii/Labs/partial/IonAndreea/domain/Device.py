class Device():
    def __init__(self,model_name,type,brand,nr_devices,operation):
        self.__operation = operation
        self.__nr_devices = nr_devices
        self.__brand = brand
        self.__type = type
        self.__model_name = model_name
    def get_model_device(self):
        return self.__model_name
    def get_type_device(self):
        return self.__type
    def get_brand_device(self):
        return self.__brand
    def get_nr_devices(self):
        return self.__nr_devices
    def get_nr_operation(self):
        return self.__operation
    def __eq__(self,other):
        return self.__model_name==other.__model_name
    def __str__(self):
        return f"{self.get_model_device()},{self.get_type_device()},{self.get_brand_device()},{self.get_nr_devices()},{self.get_nr_operation()}"