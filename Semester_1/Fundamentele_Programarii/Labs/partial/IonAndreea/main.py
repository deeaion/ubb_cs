from bussiness.service_devices import ServiceDevices
from bussiness.service_operations import ServiceOp
from console.Console import UI
from repo.file_repo_devices import FileRepoDevices
from repo.file_repo_operations import FileRepoOp

if __name__=='__main__':
    path_to_file=r"C:\Users\Deea\PycharmProjects\IonAndreea\file.txt"
    ##repos##
    repo_devices=FileRepoDevices(path_to_file)
    repo_ops=FileRepoOp(path_to_file)
    #service#
    serv_devices=ServiceDevices(repo_devices)
    serv_ops=ServiceOp(repo_ops,repo_devices)
    #ui#
    UI=UI(serv_devices,serv_ops)
    UI.run()
