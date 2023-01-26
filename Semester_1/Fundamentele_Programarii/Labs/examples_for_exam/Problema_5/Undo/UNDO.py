# from service.Service_Produs import ServiceProducts
#
#
# class Undo():
#     def __init__(self,service):
#         self._stack=[]
#         self.__undo_operations={
#             "undo_delete":self.undo_delete,
#             "undo_filtrare":self.undo_filtrare,
#
#         }
#         self.__service = service
#     def undo_change(self,params):
#         self._stack.append(params)
#     def undo(self):
#         if len(self._stack)<1:
#             print("There is nothing to undo")
#             return
#         command=self._stack[-1][0]
#         self.__undo_operations[command]()
#         self.undo_filtrare()
#     def undo_delete(self):
#         if len(self._stack)!=0:
#             lista=self._stack.pop()
#             cifra=lista[0]
#             to_readd=[x for x in lista if str(cifra) in x.get_id_product()]
#             for i in to_readd:
#                 self.__service.add_product(i.get_id_product(),i.get_name_product(),i.get_price_product())
#     def undo_filtrare(self):
#         pass