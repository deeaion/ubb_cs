from domain.Operatiune import Operation
from errors.RepoError import RepoError


class FileRepoOp():
    def __init__(self,path_to_file):
        self.__path_to_file = path_to_file
        self._ops={}
    def __read_all_from_file(self):
        with open(self.__path_to_file,"r") as f:
            lines=f.readlines()
            for line in lines:
                if line!="":
                    line=line.strip()
                    parts=line.split(",")
                    model_name=parts[0]
                    type=parts[1]
                    nr_devices=int(parts[3])
                    operation=parts[4]
                    operation=Operation(model_name,type,nr_devices,operation)
                    self._ops[model_name]=operation
    def search_op_by_name(self,name):
        if name not in self._ops:
            raise RepoError("Op does not exist")
        return self._ops[name]

    def get_all_op(self):
        self.__read_all_from_file()
        ops=[]
        for op in self._ops:
            ops.append(self._ops[op])
        return ops