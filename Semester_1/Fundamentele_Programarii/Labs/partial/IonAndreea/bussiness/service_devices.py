class ServiceDevices():
    def __init__(self,file_repo_devices):
        self.f_repo_dev = file_repo_devices
    def get_all_devices(self):
        return self.f_repo_dev.get_all_devices()
    def search_by_type(self,type):
        list=[]
        all_devices=self.get_all_devices()
        for device in all_devices:
            if device.get_type_device()==type:
                list.append(device)
        return list