from domain_cheltuiala.domain_cheltuiala import get_zi_cheltuiala, get_tip_cheltuiala, get_suma_cheltuiala

tipuri=["mancare","altele","intretinere","telefon","imbracaminte"]
def verifica_tipul(tip,tipuri):
    '''
    functie pentru a verifica daca tipul cheltuielii dorite spre validare exista.

    :param tip: string-ul cu tipul aferent
    :param tipuri: ["mancare","altele","intretinere","telefon","imbracaminte"]
    :return: True - daca tipul exista
            False- daca tipul nu exitsta
    '''
    i=0
    while(i<len(tipuri)):
        if(tip==tipuri[i]):
            return True
        i+=1
    return False
def valideaza_cheltuiala(cheltuiala):
    '''
    verifica daca ziua exista  si are val intreaga
    (0<zi<=31)
    daca tipul exista ( mancare, intretinere, imbracaminte,
    telefon, altele)
    daca suma cheltuielii este >0.0
    :param cheltuiala:cheltuiala
    :return: - (daca tema este valida)
    :raises ValueError- daca zi nu exista, se concateneaza stringul "ziua nu exista\n" la cod
                        dacat tip-ul nu exista se concateneaza stringul "tipul nu exista\n" la cod
                        daca pretul <=0, se concateneaza stringul "pretul nu exista\n" la cod
                -daca cel putin unul din atributele temei nu este valid:
                   se arunca exceptie de tipul ValueError cu mesajul codului de eroare de tip string
    '''
    erori=""
    if(get_zi_cheltuiala(cheltuiala)<=0 or get_zi_cheltuiala(cheltuiala)>31):
        erori+="ziua nu exista!\n"
    if (verifica_tipul(get_tip_cheltuiala(cheltuiala),["mancare","altele","intretinere","telefon","imbracaminte"])==False):
        erori+="tipul nu exista!\n"
    if(get_suma_cheltuiala(cheltuiala)<0):
        erori+="pretul nu exista!\n"
    if len(erori)>0:
        raise ValueError(erori)
