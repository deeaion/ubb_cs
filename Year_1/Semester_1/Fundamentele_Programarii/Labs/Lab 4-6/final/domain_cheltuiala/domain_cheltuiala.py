


def creeaza_cheltuiala(zi,tip,suma):
    '''
    Se creeaza o cheltuiala de tip dictionar
    :param zi: integer, ziua cheltuielii
    :param tip: string , tipul cheltuielii
    :param suma: float, suma cheltuielii
    :return: un dictionar de tip cheltuiala
    '''
    return {'zi':zi,
            'tip':tip,
            'suma':suma}

def get_zi_cheltuiala(cheltuiala):
    '''
    preia ziua din dictionarul cheluiala
    :param cheltuiala: dictionar
    :return: ziua integer cheltuielii
    '''
    return cheltuiala['zi']
def get_tip_cheltuiala(cheltuiala):
    '''
    preia tipul din dictionarul cheltuiala
    :param cheltuiala: dictionar
    :return: tipul de tip string
    '''
    return cheltuiala['tip']
def get_suma_cheltuiala(cheltuiala):
    '''
    preia suma cheltuielii din dictionarul cheltuiala
    :param cheltuiala: dictionar
    :return: suma de tipul float
    '''
    return cheltuiala['suma']
def set_zi_noua_cheltuiala(cheltuiala,zi_noua):
    '''
    seteaza o noua zi pentru o cheltuiala existenta
    :param cheltuiala: dictionarul cu cheltuiala initiala
    :param zi_noua: ziua noua pentru cheltuiala existenta
    :return: cheltuiala cu ziua modificata
    '''
    cheltuiala['zi']=zi_noua
def set_tip_nou_cheltuiala(cheltuiala,tip_nou):
    '''
    seteaza un nout tip pentru o cheltuiala existenta
    :param cheltuiala: dictionarul cu cheltuiala initiala
    :param tip_nou: tipul pentru cheltuiala existenta
    :return: cheltuiala cu tipul modificat
    '''
    cheltuiala['tip']=tip_nou
def set_suma_noua_cheltuiala(cheltuiala,suma_noua):
    '''
    seteaza o noua suma pentru o cheltuiala existenta
    :param cheltuiala: dictionaral cu cheltuiala intiala
    :param suma_noua: suma in care se va schimba ceea a cheltuielii existente
    :return: cheltuiala cu suma modificata
    '''
    cheltuiala['suma']=suma_noua
def egal_cheltuiala(chel_a,chel_b):
    '''
    testeaza daca doua cheltuielii sunt egale. aceasta e adevarata daca
    ziua cheltuielii a este egala cu ziua cheltuielii b
    tipul cheltuielii b este egal cu tipul cheltuielii a
    :param chel_a: chel_a prima cheltuiala ca dictionar
    :param chel_b: chelt_b a doua cheltuiala ca dictionar
    :return: True daca cele doua sunt egale
             False daca cele doua nu sunt egale
    '''
    return (get_zi_cheltuiala(chel_a)==get_zi_cheltuiala(chel_b) and get_tip_cheltuiala(chel_a)==get_tip_cheltuiala(chel_b))
def to_string_cheltuiala(cheltuiala):
    '''
    preia input ul userului
    :param cheltuiala: dictionarul cheltuiala
    :return: f
    '''
    return f"[{get_zi_cheltuiala(cheltuiala)}]{get_tip_cheltuiala(cheltuiala)}:{get_suma_cheltuiala(cheltuiala)}"