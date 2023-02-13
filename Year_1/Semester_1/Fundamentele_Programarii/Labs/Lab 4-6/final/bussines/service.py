from domain_cheltuiala.domain_cheltuiala import *
from infrastuctura.repository import *
from validificator.validation_of_cheltuiala import *
def adauga_cheltuiala_service(l,zi,tip,suma):
    '''
    pe baza zilei si tipul ce face fiecare cheltuiala unica
    va crea un buget cu cheltuieliile familiei
    algoritmul va incerca sa adauge in lista l de cheltuieli uni identificate prin zi si tip
    :param l:lista de cheltuieli unice
    :param zi:int
    :param tip:string
    :param suma:float
    :return:-(daca cheltuiala este valida si nu exista deja in lista)
    :raises ValueError- daca zi nu exista, se concateneaza stringul "ziua nu exista\n" la cod
                        dacat tip-ul nu exista se concateneaza stringul "tipul nu exista\n" la cod
                        daca pretul <=0, se concateneaza stringul "pretul nu exista\n" la cod
                -daca cel putin unul din atributele temei nu este valid:
                   se arunca exceptie de tipul ValueError cu mesajul codului de eroare de tip string
-(l'=lU {cheltuiala} daca nu exista deja in lista o alta cheltuiala cu aceeasi zi si tip
    rases ValueError:arunca exceptia de tipul ValueError cu mesajul string
    "Cheltuiala invalida"
    '''

    cheltuiala=creeaza_cheltuiala(zi,tip,suma)
    valideaza_cheltuiala(cheltuiala)
    adauga_cheltuiala_lista(l,cheltuiala)
def modifica_cheltuiala_dupa_zi_tip_service(cheltuieliile,zi,tip,zi_noua,tip_nou,suma_noua):
    '''

    :param cheltuieliile: lista de cheltuieli
    :param zi: integer, ziua cheltuielii ce vrea sa fie schimbata
    :param tip: string, tipul cheltuielii din ziua respectiva ce vrea sa fie schimbat
    :param zi_noua: integer, noua zii a cheltuielii
    :param tip_nou: string, noul tip al cheltuielii
    :param suma_noua: float, noua suma a cheltuielii
    :return: cheltuiala modificata daca daca se afla in sir cautata cu ajutorul unui comutator gasit ce devine pozitia in sir a acesteia
             noua cheltuiala modificata daca aceasta se afla in sir
                    cautata inca o data prin comutatorul gasit
            else:
            raises ValueError("cheltuiala inexistenta\n") in cazul in care cheltuiala nu se afla in sir
                          se probeaza prin faptul ca gasit va fi -1.
            raises ValueError("cheltuiala inexistenta\n") - daca cheltuiala nu se afla in sir
    '''
    cheltuiala=cauta_cheltuiala_dupa_zi_tip(cheltuieliile,zi,tip)
    noua_cheltuiala=creeaza_cheltuiala(zi_noua,tip_nou,suma_noua)
    valideaza_cheltuiala(noua_cheltuiala)
    modifica_cheltuiala_dupa_zi_tip(cheltuieliile, cheltuiala, noua_cheltuiala)
def cauta_cheltuiala_dupa_zi_tip_service(cheltuieliile,zi,tip):
    '''
        cauta daca cheltuiala se afla in sir dupa id ul ce este compus din zi si tip
        :param cheltuieliile: lista de dictionare
        :param zi: integer, ziua cautata
        :param tip: string, tipul cheltuielii din ziua cautata
        :return: cheltuiala gasita daca se afla in sir cautata cu ajutorul unui comutator gasit ce devine pozitia in sir a acesteia
                   daca este gasita
                sau:
                    raises ValueError("cheltuiala inexistenta\n") in cazul in care cheltuiala nu se afla in sir
                              se probeaza prin faptul ca gasit va fi -1.'''
    return cauta_cheltuiala_dupa_zi_tip(cheltuieliile,zi,tip)
def sterge_cheltuiala_dupa_zi_tip_service(cheltuieliile, zi,tip):
    '''
    sterge o cheltuiala dupa id-ul ei compus din zi si tip
    :param cheltuieliile: lista de cheltuieli ce sunt dictionare
    :param zi: integer, ziua cheltuielii dorite pentru stergere
    :param tip: string, tipul cheltuielii din ziua respectiva
    :return: sirul fara cheltuiala daca cheltuiala exista deja in el
                 else:
                     raises ValueError deoarece cheltuiala nu exista in sir
    '''
    sterge_cheltuiala_dupa_zi_tip(cheltuieliile,zi,tip)
def numar_cheltuieli_service(l):
    '''
        returneaza nr de cheltuieli din lista l de teme unic identificabile
        prin tip si zi
        :param l:lista cheltuieliilor
        :return:int- nr de cheltuieli
        '''
    return numar_cheltuieli_lista(l)
def get_all_cheltuieli_service(cheltuieliile):
    '''
    returneaza toate cheltuieliile
    :param cheltuieliile:lista
    :return:lista de cheltuieli
    '''
    return get_all_cheltuieli_lista(cheltuieliile)
