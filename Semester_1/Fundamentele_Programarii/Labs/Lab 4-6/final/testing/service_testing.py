from bussines.service import *

def testing_adauga_cheltuiala_service():
    '''
    testam daca functia adauga numai in cazuri corecte cheltuiala
    :return:- daca cheltuiala valideaza toateconditiile
                          ValueError- daca zi nu exista, se concateneaza stringul "ziua nu exista\n" la cod
                        dacat tip-ul nu exista se concateneaza stringul "tipul nu exista\n" la cod
                        daca pretul <=0, se concateneaza stringul "pretul nu exista\n" la cod
                -daca cel putin unul din atributele temei nu este valid:
                   se arunca exceptie de tipul ValueError cu mesajul codului de eroare de tip string
-(l'=lU {cheltuiala} daca nu exista deja in lista o alta cheltuiala cu aceeasi zi si tip
    rases ValueError:arunca exceptia de tipul ValueError cu mesajul string
    "Cheltuiala invalida"
    '''
    cheltuieliile = []
    zi = 23
    tip = "imbracaminte"
    suma = 79.43
    assert (numar_cheltuieli_service(cheltuieliile) == 0)
    adauga_cheltuiala_service(cheltuieliile, zi, tip, suma)
    assert (numar_cheltuieli_service(cheltuieliile) == 1) #verifica daca a crescut
    try:
        adauga_cheltuiala_service(cheltuieliile, zi, tip, suma)
        assert False
    except ValueError as ve:
        assert (str(ve) == "cheltuiala existenta")
    zi_imposibila = 32
    tip_gresit = "factura"
    suma_gresita = -54.90
    try:
        adauga_cheltuiala_service(cheltuieliile, zi_imposibila, tip_gresit, suma_gresita)
        assert False
    except ValueError as ve:
        assert (str(ve) == "ziua nu exista!\ntipul nu exista!\npretul nu exista!\n")
    alt_zi = 22
    alt_tip = "imbracaminte"
    alta_suma = 24324.2
    lista_cheltuieli = get_all_cheltuieli_service(cheltuieliile)
    assert (len(lista_cheltuieli) == 1)
    adauga_cheltuiala_service(cheltuieliile, alt_zi, alt_tip, alta_suma)
    assert (numar_cheltuieli_service(cheltuieliile) == 2)
    assert (len(lista_cheltuieli) == 2)
def testing_cauta_cheltuiala_service():
    '''
    cauta daca o cheltuiala se afla in sir
    :return: cheltuiala daca se afla
         else:
           cheltuiala gasita daca se afla in sir cautata cu ajutorul unui comutator gasit ce devine pozitia in sir a acesteia
                   daca este gasita
                sau:
                    raises ValueError("cheltuiala inexistenta\n") in cazul in care cheltuiala nu se afla in sir
                              se probeaza prin faptul ca gasit va fi -1.'''
    cheltuieliile = []
    zi = 23
    tip = "imbracaminte"
    suma = 79.43
    adauga_cheltuiala_service(cheltuieliile, zi, tip, suma)
    cheltuiala_gasita = cauta_cheltuiala_dupa_zi_tip_service(cheltuieliile, zi, tip)  # verifica daca a fost adaugata
    assert (get_zi_cheltuiala(cheltuiala_gasita) == zi and get_tip_cheltuiala(cheltuiala_gasita) == tip)
    alt_zi = 22
    alt_tip = "imbracaminte"
    try:
        cauta_cheltuiala_dupa_zi_tip_service(cheltuieliile, alt_zi, alt_tip)
        assert False
    except ValueError as ve:
        assert (str(ve) =="cheltuiala inexistenta\n")
def testing_modifica_cheltuiala_service():
    '''
    se testeaza functia de modificare a unei cheltuieli din service
    :return: cheltuiala modificata daca daca se afla in sir cautata cu ajutorul unui comutator gasit ce devine pozitia in sir a acesteia
             noua cheltuiala modificata daca aceasta se afla in sir
                    cautata inca o data prin comutatorul gasit
            else:
            raises ValueError("cheltuiala inexistenta\n") in cazul in care cheltuiala nu se afla in sir
                          se probeaza prin faptul ca gasit va fi -1.
            raises ValueError("cheltuiala inexistenta\n") - daca cheltuiala nu se afla in sir
    '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43
    adauga_cheltuiala_service(cheltuieliile, zi, tip, suma)
    alta_zi = 24
    alt_tip = "imbracaminte"
    alta_suma = 24324.2
    suma_mod=323.2
    tip_mod="altele"
    zi_mod=27
    try:
        modifica_cheltuiala_dupa_zi_tip_service(cheltuieliile,alta_zi,alt_tip,zi_mod,tip_mod,suma_mod)
        assert False
    except ValueError as ve:
        assert(str(ve)=="cheltuiala inexistenta\n")
    modifica_cheltuiala_dupa_zi_tip_service(cheltuieliile, zi, tip, alta_zi, alt_tip, alta_suma)
    cheltuiala_gasita = cauta_cheltuiala_dupa_zi_tip_service(cheltuieliile, alta_zi,alt_tip)
    assert (get_zi_cheltuiala(cheltuiala_gasita) == alta_zi and get_tip_cheltuiala(cheltuiala_gasita) == alt_tip and get_suma_cheltuiala(cheltuiala_gasita)==alta_suma)
def testing_stergere_cheltuiala_service():
    '''
        testeaza daca se sterge o cheltuiala dupa id-ul ei compus din zi si tip
        :return: sirul fara cheltuiala daca cheltuiala exista deja in el
                     else:
                         raises ValueError deoarece cheltuiala nu exista in sir
        '''
    cheltuieliile = []
    zi = 23
    tip = "mancare"
    suma = 79.43
    adauga_cheltuiala_service(cheltuieliile, zi, tip, suma)
    assert (numar_cheltuieli_service(cheltuieliile) == 1)
    alta_zi = 24
    alt_tip = "imbracaminte"
    alta_suma = 24324.2
    try:
            sterge_cheltuiala_dupa_zi_tip_service(cheltuieliile, alta_zi,alt_tip)
            assert False
    except ValueError as ve:
            assert (str(ve) == "cheltuiala inexistenta\n")
    lista_cheltuieli = get_all_cheltuieli_service(cheltuieliile)
    adauga_cheltuiala_service(cheltuieliile,alta_zi,alt_tip,alta_suma)
    assert (len(lista_cheltuieli)== 2)
    sterge_cheltuiala_dupa_zi_tip_service(cheltuieliile, alta_zi, alt_tip)
    assert (len(lista_cheltuieli) == 1)

