from domain.Device import Device
from errors.RepoError import RepoError


class FileRepoDevices():
    def __init__(self,path_to_file):
        self.__path_to_file=path_to_file
        self._devices={}

    def __read_all_from_file(self):
        with open(self.__path_to_file,"r") as f:
            lines=f.readlines()
            for line in lines:
                if line!="":
                    line=line.strip()
                    parts=line.split(",")
                    model_name=parts[0]
                    type=parts[1]
                    brand=parts[2]
                    nr_devices=int(parts[3])
                    operation=parts[4]
                    device=Device(model_name,type,brand,nr_devices,operation)
                    self._devices[model_name]=device
    def search_by_name(self,device):
        if device not in self._devices:
            raise RepoError("Device does not exist")
        return self._devices[device]
    def get_all_devices(self):
        self.__read_all_from_file()
        devices=[]
        for model_device in self._devices:
            devices.append(self._devices[model_device])
        return devices
