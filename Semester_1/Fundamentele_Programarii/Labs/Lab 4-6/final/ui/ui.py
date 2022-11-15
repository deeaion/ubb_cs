
from bussines.undo import *
from ui.ui_functions import *
def ruleaza_ui():
    cheltuieliile=[]
    stack = []
    comenzi={
        #1
        "adauga_cheltuiala":ui_adauga_cheltuiala,
        "printeaza_lista_cheltuieli":ui_printeaza_lista_cheltuiala,
        "actualizeaza_cheltuiala":ui_actualizeaza_cheltuiala,
        #2
        "stergere_cheltuieli_zi": ui_stergere_zi,
        "stergere_cheltuieli_interval_zilele":ui_stergere_interval_zile,
        "stergere_cheltuieli_de_tipul": ui_elimina_tip,
        #3
        "print_cheltuieli_mai_mari_ca_suma": ui_print_mai_mari_ca_suma,
        "print_cheltuieli_mai_mici_si_mai_devreme": ui_print_mai_mici_si_mai_devreme,
        "print_cheltuieli_same_type": ui_print_same_type,
        #4

        "print_cheltuieli_suma_tip_cheltuiala":ui_print_sum_same_type,
        "zi_cheltuieli_maxima": ul_zi_suma_maxima,
        "print_aceasi_sum": ui_anumita_suma,
        "print_sortate_dupa_tip": ui_print_sortate_dupa_tip,
        #5
        "elimina_cheltuieli_mai_mici_ca_suma": ui_elimina_mai_mici_ca_suma,
        "elimina_cheltuieli_de_tipul": ui_elimina_tip,
        "undo":ui_undo,
        "help":ui_print_menu,

    }
    while True:
        comanda=input(">>>")
        if comanda=="":
            continue
        if comanda=="exit":
            return
        comanda=comanda.split(";") #curata caracterele invizibile
        for comand in comanda:
            print(comand)
            parti=comand.split()
            nume_comanda=parti[0]
            params=parti[1:]
            for param in params:
                param=param.strip()
            print(params)
            if nume_comanda in comenzi:
                try:
                    comenzi[nume_comanda](cheltuieliile,params,stack)
                except ValueError as ve:
                    print(ve)
            else:
                print("comanda invalida!")