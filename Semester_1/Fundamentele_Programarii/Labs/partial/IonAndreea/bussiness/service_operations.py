class ServiceOp():
    def __init__(self,file_repo_op,file_repo_devices):
        self.__f_re_op = file_repo_op
        self.__f_re_dev=file_repo_devices
    def get_all_ops(self):
        return self.__f_re_op.get_all_op()
    def find_type_brand_nr(self,type,brand):
        list_op=self.__f_re_op.get_all_op()
        all_things=0
        for op in list_op:
            if(op.get_type_device()==type and op.get_nr_operation()=="supply"):
                device=self.__f_re_dev.search_by_name(op.get_model_device())
                if device.get_brand_device()==brand:
                    all_things=all_things+op.get_nr_devices()
            if (op.get_type_device() == type and op.get_nr_operation() == "sale"):
                device = self.__f_re_dev.search_by_name(op.get_model_device())
                if device.get_brand_device() == brand:
                    all_things = all_things - op.get_nr_devices()
        return all_things




