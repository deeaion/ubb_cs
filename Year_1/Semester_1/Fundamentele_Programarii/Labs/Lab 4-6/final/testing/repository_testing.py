from domain_cheltuiala.domain_cheltuiala import creeaza_cheltuiala, egal_cheltuiala
from infrastuctura.repository import *
def testing_adaugare_si_lungime_existenta_in_lista_cheltuiala_corecta():
    '''
    testeaza daca este adaugata o cheltuiala
    :return: -daca cheltuiala seadauga corect
    '''
    cheltuieliile= []
    assert ((numar_cheltuieli_lista(cheltuieliile)) == 0)
    zi = 23
    tip = "mancare"
    suma = 79.43 #o consideram intr-o data corecta
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    assert((numar_cheltuieli_lista(cheltuieliile))==0)
    adauga_cheltuiala_lista(cheltuieliile,cheltuiala)
    assert ((numar_cheltuieli_lista(cheltuieliile)) == 1)
    alta_zi = 24
    alt_tip = "imbracaminte"
    noua_cheltuiala = creeaza_cheltuiala(alta_zi, alt_tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, noua_cheltuiala)
    assert ((numar_cheltuieli_lista(cheltuieliile)) == 2)
    lista_cheltuiala = (get_all_cheltuieli_lista(cheltuieliile))
    assert (len(lista_cheltuiala) == 2)
    assert (egal_cheltuiala(lista_cheltuiala[0], cheltuiala))
    assert (egal_cheltuiala(lista_cheltuiala[1], noua_cheltuiala))
def testing_adaugare_aceeasi_cheltuiala_in_lista():
    '''
    Se testeaza daca programul asa cum este si cerut nu lasa utilizatorul sa introduca o aceasi cheltuiala
    Doua cheltuieli sunt considerate egale daca au aceeasi zi si acelasi tip
    :return: - daca se poate adauga cheltuiala
                 ValueError="cheltuiala existenta" daca sunt egale
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43  # o consideram intr-o data corecta
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, cheltuiala)
    same_zi = 23
    same_tip = "mancare"
    alta_suma = 7232.2
    alt_cheltuiala = creeaza_cheltuiala(same_zi, same_tip, alta_suma)##incerci sa adaugi o cheltuiala cu acceasi chestie
    try:
        adauga_cheltuiala_lista(cheltuieliile, alt_cheltuiala)
        assert False
    except ValueError as ve:
        assert (str(ve)=="cheltuiala existenta")
def testing_cauta_cheltuiala_existenta():
    '''
    se testeaza daca functia din repo cauta corect in lista de cheltuielii o anumita cheltuiala care suntem siguri ca exista
    :return: - daca o gaseste
                  -AssertionError otherwise
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, cheltuiala)
    cheltuiala_gasita = cauta_cheltuiala_dupa_zi_tip(cheltuieliile, zi, tip)
    assert (egal_cheltuiala(cheltuiala_gasita, cheltuiala))
def testing_cauta_cheltuiala_inexistenta():
    '''
    cauta o cheltuiala de care suntem siguri ca nu exista in sirul de cheltuieli
    :return: ValueError="cheltuiala inexistenta\n" daca cheltuiala nu exista in lista
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, cheltuiala)
    alta_zi = 24
    alt_tip = "imbracaminte"
    noua_cheltuiala = creeaza_cheltuiala(alta_zi, alt_tip, suma)
    try:
        cauta_cheltuiala_dupa_zi_tip(cheltuieliile, alta_zi, alt_tip)
        assert False
    except ValueError as ve:
        assert (str(ve) == "cheltuiala inexistenta\n")
def testing_modifica_cheltuiala_inexistenta():
    '''
    se incearca sa se modifice o cheltuiala de care suntem siguri ca nu exista!
    :return: ValueError="cheltuiala inexistenta\n" daca se incearca modificare unei cheltuieli inexistente
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, cheltuiala)
    alta_zi = 24
    alt_tip = "imbracaminte"
    noua_cheltuiala = creeaza_cheltuiala(alta_zi, alt_tip, suma)
    zi_mod = 25
    tip_mod = "telefon"
    cheltuiala_modificata = creeaza_cheltuiala(zi_mod, tip_mod, 231.2)
    try:
        modifica_cheltuiala_dupa_zi_tip(cheltuieliile,noua_cheltuiala,cheltuiala_modificata)
        assert False
    except ValueError as ve:
        assert (str(ve) == "cheltuiala inexistenta\n")
def testing_sterge_cheltuiala_inexistenta():
    '''
    se incearca stergerea unei cheltuielii de care cunoastem ca nu exista in sir
    :return: ValueError=="cheltuiala inexistenta\n"
        - daca functia nu e corecta
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, cheltuiala)
    alta_zi = 24
    alt_tip = "imbracaminte"
    noua_cheltuiala = creeaza_cheltuiala(alta_zi, alt_tip, suma)
    try:
        sterge_cheltuiala_dupa_zi_tip(cheltuieliile,alta_zi,alt_tip)
        assert False
    except ValueError as ve:
        assert (str(ve) == "cheltuiala inexistenta\n")
def testing_modificare_cheltuiala_existenta():
    '''
    se testeaza daca functia modificare din repo modifica corect o cheltuiala exista in lista cu alte date introduse
    :return: - daca functia a fost implementata corect
                 AssertionError- in caz contrar
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, cheltuiala)
    zi_mod = 25
    tip_mod = "telefon"
    cheltuiala_modificata = creeaza_cheltuiala(zi_mod, tip_mod, 231.2)
    modifica_cheltuiala_dupa_zi_tip(cheltuieliile,cheltuiala, cheltuiala_modificata)
    cheltuiala_gasita = cauta_cheltuiala_dupa_zi_tip(cheltuieliile, zi_mod, tip_mod)
    assert (get_tip_cheltuiala(cheltuiala_gasita) == tip_mod and get_zi_cheltuiala(cheltuiala_gasita) == zi_mod)
    zin=21
    tipn="altele"
    suman=232.2
    zi_moddd=21
    tip_modd="imbracaminte"
    suma_modd=676.2
    cheltuiala_de_mod=creeaza_cheltuiala(zin,tipn,suman)
    adauga_cheltuiala_lista(cheltuieliile,cheltuiala_de_mod)
    cheltuiala_trei=creeaza_cheltuiala(zi_moddd,tip_modd,suma_modd)
    modifica_cheltuiala_dupa_zi_tip(cheltuieliile,cheltuiala_modificata,cheltuiala_trei)
    cheltuiala_gasita = cauta_cheltuiala_dupa_zi_tip(cheltuieliile,zi_moddd, tip_modd)
    assert (get_tip_cheltuiala(cheltuiala_gasita) ==tip_modd and get_zi_cheltuiala(cheltuiala_gasita) == zi_moddd)

def testing_sterge_cheltuiala_existenta():
    '''
    se testeaza daca functia de stergere din repo sterge corect o cheltuiala data dupa zi si tip
    :return: - daca functia a fost implementata corect
                       - AssertionError otherwise
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43  # o consideram intr-o data corecta
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, cheltuiala)
    alta_zi = 24
    alt_tip = "imbracaminte"
    noua_cheltuiala = creeaza_cheltuiala(alta_zi, alt_tip, suma)
    adauga_cheltuiala_lista(cheltuieliile, noua_cheltuiala)
    sterge_cheltuiala_dupa_zi_tip(cheltuieliile, alta_zi, alt_tip)
    assert (numar_cheltuieli_lista(cheltuieliile) == 1)