from bussines.service import *
def undo_adauga_cheltuiala(cheltuieliile,cheltuiala):
    sterge_cheltuiala_dupa_zi_tip(cheltuieliile,get_zi_cheltuiala(cheltuiala),get_tip_cheltuiala(cheltuiala))
def undo_modifica_cheltuiala(cheltuieliile,zi_cheltuiala,tip_cheltuiala,suma_veche,zi_noua,tip_nou):
    modifica_cheltuiala_dupa_zi_tip_service(cheltuieliile,zi_noua,tip_nou,zi_cheltuiala,tip_cheltuiala,suma_veche)
def undo_sterge_tip(cheltuieliile,cheltuiala,index):
    cheltuieliile.insert(index,cheltuiala)
def undo_sterge_zi(cheltuieliile,cheltuiala,index):
    cheltuieliile.insert(index, cheltuiala)
def undo_elimina_mai_mici_ca_suma(cheltuieliile,cheltuiala,index):
    cheltuieliile.insert(index, cheltuiala)
def undo_elimina_cheltuieli_dintr_un_interval_de_zile(cheltuieliile,cheltuiala,index):
    cheltuieliile.insert(index, cheltuiala)