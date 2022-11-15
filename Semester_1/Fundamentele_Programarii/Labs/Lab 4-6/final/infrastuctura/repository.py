from domain_cheltuiala.domain_cheltuiala import *
def numar_cheltuieli_lista(l):
    '''
    returneaza nr de cheltuieli din lista l de teme unic identificabile
    prin tip si zi
    :param l:lista cheltuieliilor
    :return:int- nr de cheltuieli
    '''
    return len(l)
def adauga_cheltuiala_lista(cheltuieliile, cheltuiala):
    '''
    adauga cheltuiala la lista daca aceasta intruneste anumite conditiii
    :param cheltuieliile: lista de dictionare
    :param cheltuiala: dictionarul ce contine datele cheltuielii
    :return: adauga la lista cheltuieliile cheltuiala
    ori
              raises ValueError - daca mai exista o astfel de cheltuiala.
                            Doua cheltuieli sunt egale daca au acelasi tip si aceeasi zi
    '''
    for chelt in range(0,numar_cheltuieli_lista(cheltuieliile)):
        if(egal_cheltuiala(cheltuieliile[chelt],cheltuiala)==True):
            raise ValueError("cheltuiala existenta")
    to_add=cheltuiala.copy()
    cheltuieliile.append(to_add)
def cauta_pozitie_in_sir_a_cheltuielii_dupa_zi_si_tip(cheltuieliile,zi,tip):
    '''
    cauta pozitia din sir a unei cheltuielii cerute in functie de id-ul ei compus din zi si tip
    :param cheltuieliile: lista de dictionare de tip cheltuiala
    :param zi: integer,ziua cheltuielii
    :param tip: string, tipul cheltuielii
    :return: integer, pozitia in sir a cheltuielii
                    raises ValueError daca cheltuiala nu exista
    '''
    gasit = -1
    for chel in range(0, numar_cheltuieli_lista(cheltuieliile)):
        if (get_zi_cheltuiala(cheltuieliile[chel]) == zi and get_tip_cheltuiala(cheltuieliile[chel]) == tip):
            gasit = chel
    if (gasit == -1):
        raise ValueError("cheltuiala inexistenta\n")
    return gasit  # return poz in sir
def cauta_cheltuiala_dupa_zi_tip(cheltuieliile,zi,tip):
    '''
    cauta daca cheltuiala se afla in sir dupa id ul ce este compus din zi si tip
    :param cheltuieliile: lista de dictionare
    :param zi: integer, ziua cautata
    :param tip: string, tipul cheltuielii din ziua cautata
    :return: cheltuiala gasita daca se afla in sir cautata cu ajutorul unui comutator gasit ce devine pozitia in sir a acesteia
               daca este gasita
            sau:
                raises ValueError("cheltuiala inexistenta\n") in cazul in care cheltuiala nu se afla in sir
                          se probeaza prin faptul ca gasit va fi -1.

    '''
    gasit=-1
    for chel in range(0,numar_cheltuieli_lista(cheltuieliile)):
        if(get_zi_cheltuiala(cheltuieliile[chel])==zi and get_tip_cheltuiala(cheltuieliile[chel])==tip):
            gasit=chel
    if(gasit==-1):
        raise ValueError("cheltuiala inexistenta\n")
    return cheltuieliile[gasit]#return poz in sir
def sterge_cheltuiala_dupa_zi_tip(cheltuieliile,zi,tip):
    '''
    sterge o cheltuiala dupa id-ul ei compus din zi si tip
    :param cheltuieliile: lista de cheltuieli ce sunt dictionare
    :param zi: integer, ziua cheltuielii dorite pentru stergere
    :param tip: string, tipul cheltuielii din ziua respectiva
    :return: sirul fara cheltuiala daca cheltuiala exista deja in el
                 else:
                     raises ValueError deoarece cheltuiala nu exista in sir
    '''
    gasit = -1
    for chel in range(0, numar_cheltuieli_lista(cheltuieliile)):
        if (get_zi_cheltuiala(cheltuieliile[chel]) == zi and get_tip_cheltuiala(cheltuieliile[chel]) == tip):
            gasit = chel
    if (gasit == -1):
        raise ValueError("cheltuiala inexistenta\n")
    cheltuieliile.remove(cheltuieliile[gasit])
def modifica_cheltuiala_dupa_zi_tip(cheltuieliile,cheltuiala,cheltuiala_modificata):
    '''
    Functie care va modifica/actualiza o cheltuiala deja existenta in sir.
    :param cheltuieliile: list,lista de cheltuieli
    :param cheltuiala: dictionar, cheltuiala dorita spre modificare
    :param cheltuiala_modificata: dicitonar, cheltuiala cu care se va modifica cheltuiala precedenta
    :return: noua cheltuiala modificata daca aceasta se afla in sir
                    cautata inca o data prin comutatorul gasit

            raises ValueError("cheltuiala inexistenta\n") - daca cheltuiala nu se afla in sir
    '''
    zi=get_zi_cheltuiala(cheltuiala)
    tip=get_tip_cheltuiala(cheltuiala)
    gasit=-1
    for chel in range(0, numar_cheltuieli_lista(cheltuieliile)):
        if (get_zi_cheltuiala(cheltuieliile[chel]) == zi and get_tip_cheltuiala(cheltuieliile[chel]) == tip):
            gasit=chel
    if (gasit == -1):
        raise ValueError("cheltuiala inexistenta\n")
    cheltuieliile[gasit] = cheltuiala_modificata
def get_all_cheltuieli_lista(cheltuieliile):
    '''
    preia toate cheltuieliile din lista
    :return:cheltuieliile, lista cu dictionarele cheltuiala
    '''
    return cheltuieliile
