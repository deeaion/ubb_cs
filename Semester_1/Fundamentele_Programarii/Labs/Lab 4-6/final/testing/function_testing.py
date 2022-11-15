
from bussines.functions import *
from bussines.service import *
from ui.ui_functions import *

def test_numar_cheltuieli_ce_se_intampla_intro_zi():
    '''
                se testeaza daca functia auxiliara unde se determina nr cheluieliilor ce satisfac
                 aceasta conditie pentru functia de  stergere cheltuieli dintr-o zi introdusa de user
                :return: - daca assertul este corect
                                -asseertion error daca functia nu este corecta
                '''
    cheltuieliile=[]
    adauga_cheltuiala_service(cheltuieliile,23,'imbracaminte',3232.2)
    zi=23
    assert(numar_cheltuieli_ce_se_intampla_intro_zi(cheltuieliile,zi)==1)
    adauga_cheltuiala_service(cheltuieliile,24,'imbracaminte',3232.2)
    sterge_cheltuiala_dupa_zi_tip(cheltuieliile,23,'imbracaminte')
    assert (numar_cheltuieli_ce_se_intampla_intro_zi(cheltuieliile, zi) == 0)
def test_numar_cheltuieli_ce_se_au_acelasi_tip():
    '''
                se testeaza daca functia auxiliara unde se determina nr cheluieliilor ce satisfac
                 aceasta conditie pentru functia de  stergere cheltuieli de un tip introdus de user
                :return: - daca assertul este corect
                                -asseertion error daca functia nu este corecta
                '''
    cheltuieliile = []
    tip_cautat = 'imbracaminte'
    assert (numar_cheltuieli_ce_se_au_acelasi_tip(cheltuieliile, tip_cautat) == 0)
    zi=23
    tip='imbracaminte'
    suma=3232.2
    adauga_cheltuiala_service(cheltuieliile, zi,tip,suma)
    assert(numar_cheltuieli_ce_se_au_acelasi_tip(cheltuieliile,tip_cautat)==1)
def test_exista_cheltuiala_mai_mici_ca_suma():
    '''
            se testeaza daca functia auxiliara unde se determina nr cheluieliilor ce satisfac
             aceasta conditie pentru functia de  stergere cheltuieli mai mici ca o suma introdusa de user
            :return: - daca assertul este corect
                            -asseertion error daca functia nu este corecta
            '''
    cheltuieliile = []
    suma_cautata = 3234.2
    assert (exista_cheltuiala_mai_mici_ca_suma(cheltuieliile, suma_cautata) == 0)
    zi = 23
    tip = 'imbracaminte'
    suma = 3232.2
    adauga_cheltuiala_service(cheltuieliile, zi, tip, suma)
    assert (exista_cheltuiala_mai_mici_ca_suma(cheltuieliile, suma_cautata) == 1)
def test_stergere_zi():
    '''
            se testeaza daca functia auxiliara pentru functia de ui sterge corect cheltuieliile dintr-o zi introdusa de user
            :return: - daca assertul este corect
                            -asseertion error daca functia nu este corecta
            '''
    cheltuieliile=[]
    adauga_cheltuiala_service(cheltuieliile,24,'imbracaminte',242.2)
    adauga_cheltuiala_service(cheltuieliile, 25, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 24, 'telefon', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 5, 'altele', 24242.2)
    adauga_cheltuiala_service(cheltuieliile, 30, 'imbracaminte', 24242.2)
    zi=24
    t=stergere_zi(cheltuieliile, zi)
    assert(t==[{'zi': 25, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 5, 'tip': 'altele', 'suma': 24242.2},{'zi': 30, 'tip': 'imbracaminte', 'suma': 24242.2}])
def test_stergere_cheltuieli_tip():
    '''
            se testeaza daca functia auxiliara pentru functia de ui sterge corect cheltuieliile de un anumit tip introdus de user
            :return: - daca assertul este corect
                            -asseertion error daca functia nu este corecta
            '''
    cheltuieliile = []
    adauga_cheltuiala_service(cheltuieliile, 24, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 25, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 24, 'telefon', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 5, 'altele', 24242.2)
    adauga_cheltuiala_service(cheltuieliile, 30, 'imbracaminte', 24242.2)
    tip='imbracaminte'
    cheltuieli_sterse=[]
    lista_stearsa=stergere_cheltuieli_tip(cheltuieliile,tip,cheltuieli_sterse)
    assert(lista_stearsa==[{'zi': 24, 'tip': 'telefon', 'suma': 242.2},{'zi': 5, 'tip': 'altele', 'suma': 24242.2}])
def test_stergere_interval_zile():
    '''
            se testeaza daca functia auxiliara pentru functia de ui unde se determina dictionarele ce se vor sterge in lista principala
                     le inregistreaza corect
            :return: - daca assertul este corect
                            -asseertion error daca functia nu este corecta
            '''
    cheltuieliile = []
    adauga_cheltuiala_service(cheltuieliile, 24, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 25, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 24, 'telefon', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 5, 'altele', 24242.2)
    adauga_cheltuiala_service(cheltuieliile, 30, 'imbracaminte', 24242.2)
    zi_inf=24
    zi_sup=25
    lista_cheltuieli_sterse=[]
    pozitia_si_cheltuieliile_din_intervalul_de_zile(cheltuieliile, zi_inf, zi_sup, lista_cheltuieli_sterse)
    assert(lista_cheltuieli_sterse==[{'zi':24, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 25, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 24, 'tip': 'telefon', 'suma': 242.2}])
def test_stergere_cheltuieli_mai_mici_ca_suma():
    '''
        se testeaza daca functia auxiliara pentru functia de ui sterge corect cheltuieliile mai mici ca o suma introdusa de user
        :return: - daca assertul este corect
                        -asseertion error daca functia nu este corecta
        '''
    cheltuieliile = []
    adauga_cheltuiala_service(cheltuieliile, 24, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 25, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 24, 'telefon', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 5, 'altele', 24242.2)
    adauga_cheltuiala_service(cheltuieliile, 30, 'imbracaminte', 24242.2)
    suma=290
    cheltuieli_sterse=[]
    t=stergere_cheltuieli_mai_mici_ca_suma(cheltuieliile,suma,cheltuieli_sterse)
    assert(t==[{'zi': 5, 'tip': 'altele', 'suma': 24242.2},{'zi': 30, 'tip': 'imbracaminte', 'suma': 24242.2}])
def test_suma_tipului():
    '''
        se testeaza daca functia auxiliara pentru functia de ui unde se printeaza suma unui anumit tip de cheltuieli returneaza valoarea corecta
        :return: - daca assertul este corect
                        -asseertion error daca functia nu este corecta
        '''
    cheltuieliile = []
    adauga_cheltuiala_service(cheltuieliile, 24, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 25, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 24, 'telefon', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 5, 'altele', 24242.2)
    adauga_cheltuiala_service(cheltuieliile, 30, 'imbracaminte', 24242.2)
    tip="imbracaminte"
    assert (abs(suma_tipului(cheltuieliile,tip)-24726.600000000002)<=0.0000000000000000000002)
def test_suma_zi():
    '''
        se testeaza daca functia auxiliara pentru functia de ui unde se printeaza suma cheltuieliilor dintr-o zi returneaza valoarea corecta
        :return: - daca assertul este corect
                        -asseertion error daca functia nu este corecta
        '''
    cheltuieliile = []
    adauga_cheltuiala_service(cheltuieliile, 24, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 25, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 24, 'telefon', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 5, 'altele', 24242.2)
    adauga_cheltuiala_service(cheltuieliile, 30, 'imbracaminte', 24242.2)
    zi=5
    assert(abs(suma_zi(cheltuieliile,zi)-24242.2)<=0.000000001)
def test_zi_suma_maxima():
    '''
    se testeaza daca functia auxiliara pentru functia de ui unde se printeaza suma maxima returneaza valoarea corecta
    :return: - daca assertul este corect
                    -asseertion error daca functia nu este corecta
    '''
    cheltuieliile = []
    adauga_cheltuiala_service(cheltuieliile, 24, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 25, 'imbracaminte', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 24, 'telefon', 242.2)
    adauga_cheltuiala_service(cheltuieliile, 5, 'altele', 24243.2)
    adauga_cheltuiala_service(cheltuieliile, 30, 'imbracaminte', 24242.2)
    assert(zi_suma_maxima(cheltuieliile)==5)
def test_undo_adauga():
    '''
    testam daca functia undo adauga functioneaza corect
    :return:-
    '''
    stack=[]
    zi=24
    tip='imbracaminte'
    suma=242.2
    zidoi=25
    tipdoi='altele'
    sumadoi=242.2
    #cheltuieliile_intiala=[{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 25, 'tip': 'altele', 'suma': 242.2}]
    cheltuieliile=[]
    params=[zi,tip,suma]
    ui_adauga_cheltuiala(cheltuieliile,params,stack)
    ui_undo(cheltuieliile,params,stack)
    assert(cheltuieliile== [])
def test_undo_elimina_tip():
    '''
    testam daca functia undo functioneaza corect atunci cand reinstauram un tip eliminat
    :return: -
    '''
    stack = []
    zi = 24
    tip = 'imbracaminte'
    suma = 242.2
    zidoi = 25
    tipdoi = 'altele'
    sumadoi = 242.2
    cheltuieliile = []
    params = [zi, tip, suma]
    ui_adauga_cheltuiala(cheltuieliile, params, stack)
    paramsdoi=[zidoi,tipdoi,sumadoi]
    ui_adauga_cheltuiala(cheltuieliile, paramsdoi, stack)
    tipp=[tip]
    ui_elimina_tip(cheltuieliile,tipp,stack)
    assert(cheltuieliile==[{'zi': 25, 'tip': 'altele', 'suma': 242.2}])
    l=[]
    ui_undo(cheltuieliile,l,stack)
    assert(cheltuieliile==[{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 25, 'tip': 'altele', 'suma': 242.2}])
    ui_undo(cheltuieliile,l,stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2}])
def test_undo_cheltuieli_mai_ieftne():
    '''
    se testeaza printr-o functie de assert daca se face undo corect la stergerea cheltuieliilor mai ieftine decat un anumit pret
    :return: - daca functia este buna
                - Value Error
    '''
    stack = []
    zi = 24
    tip = 'imbracaminte'
    suma = 242.2
    zidoi = 25
    tipdoi = 'altele'
    sumadoi = 300.2
    cheltuieliile = []
    params = [zi, tip, suma]
    ui_adauga_cheltuiala(cheltuieliile, params, stack)
    paramsdoi = [zidoi, tipdoi, sumadoi]
    ui_adauga_cheltuiala(cheltuieliile, paramsdoi, stack)
    ui_elimina_mai_mici_ca_suma(cheltuieliile,[290], stack)
    assert (cheltuieliile == [{'zi': 25, 'tip': 'altele', 'suma': 300.2}])
    ui_undo(cheltuieliile,[], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 25, 'tip': 'altele', 'suma': 300.2}])
    ui_undo(cheltuieliile,[], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2}])
def test_undo_elimina_zi():
    '''
    se testeaza prin functii de asert daca se reface iteratia de a elimina cheltuieliile dintr-o anumita zi
    :return: - daca functia functioneaza corect
                Value Error in caz contrar
    '''
    stack = []
    zi = 24
    tip = 'imbracaminte'
    suma = 242.2
    zidoi = 25
    tipdoi = 'altele'
    sumadoi = 300.2
    cheltuieliile = []
    params = [zi, tip, suma]
    ui_adauga_cheltuiala(cheltuieliile, params, stack)
    paramsdoi = [zidoi, tipdoi, sumadoi]
    ui_adauga_cheltuiala(cheltuieliile, paramsdoi, stack)
    ui_stergere_zi(cheltuieliile, [24], stack)
    assert (cheltuieliile == [{'zi': 25, 'tip': 'altele', 'suma': 300.2}])
    ui_undo(cheltuieliile, [], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 25, 'tip': 'altele', 'suma': 300.2}])
    ui_undo(cheltuieliile, [], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2}])
def test_undo_elimina_interval_zile():
    '''
        se testeaza prin functii de asert daca se reface iteratia de a elimina cheltuieliile dintr-un interval de zile
        :return: - daca functia functioneaza corect
                    Value Error in caz contrar
        '''
    stack = []
    zi = 24
    tip = 'imbracaminte'
    suma = 242.2
    zidoi = 25
    tipdoi = 'altele'
    sumadoi = 300.2
    zitrei=30
    tiptrei='telefon'
    sumatrei=23231.2
    cheltuieliile = []
    params = [zi, tip, suma]
    ui_adauga_cheltuiala(cheltuieliile, params, stack)
    paramsdoi = [zidoi, tipdoi, sumadoi]
    ui_adauga_cheltuiala(cheltuieliile, paramsdoi, stack)
    paramstrei=[zitrei,tiptrei,sumatrei]
    ui_adauga_cheltuiala(cheltuieliile, paramstrei, stack)
    ui_stergere_interval_zile(cheltuieliile, [24,25], stack)
    assert (cheltuieliile == [{'zi': 30, 'tip': 'telefon', 'suma': 23231.2}])
    ui_undo(cheltuieliile, [], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2},
                              {'zi': 25, 'tip': 'altele', 'suma': 300.2},{'zi': 30, 'tip': 'telefon', 'suma': 23231.2}])
    ui_undo(cheltuieliile, [], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2},{'zi': 25, 'tip': 'altele', 'suma': 300.2}])
def test_undo_modifica_cheltuiala():
    '''
    se testeaza prin functii de asert daca se reface iteratia de a modifica o anumita cheltuiala in lista
    :return: - daca functia functioneaza corect
                Value Error in caz contrar
    '''
    stack = []
    zi = 24
    tip = 'imbracaminte'
    suma = 242.2
    zidoi = 25
    tipdoi = 'altele'
    sumadoi = 300.2
    zitrei = 30
    tiptrei = 'telefon'
    sumatrei = 23231.2
    cheltuieliile = []
    params = [zi, tip, suma]
    ui_adauga_cheltuiala(cheltuieliile, params, stack)
    paramsdoi = [zidoi, tipdoi, sumadoi]
    ui_adauga_cheltuiala(cheltuieliile, paramsdoi, stack)
    paramstrei = [zi,tip,zitrei, tiptrei, sumatrei]
    ui_actualizeaza_cheltuiala(cheltuieliile, paramstrei, stack)
    assert (cheltuieliile == [{'zi': 30, 'tip': 'telefon', 'suma': 23231.2},{'zi': 25, 'tip': 'altele', 'suma': 300.2}])
    ui_undo(cheltuieliile, [], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2},
                              {'zi': 25, 'tip': 'altele', 'suma': 300.2}])
    ui_undo(cheltuieliile, [], stack)
    assert (cheltuieliile == [{'zi': 24, 'tip': 'imbracaminte', 'suma': 242.2}])
