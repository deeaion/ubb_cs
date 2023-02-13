import operator

from domain_cheltuiala.domain_cheltuiala import get_zi_cheltuiala, get_tip_cheltuiala
from infrastuctura.repository import cauta_cheltuiala_dupa_zi_tip, cauta_pozitie_in_sir_a_cheltuielii_dupa_zi_si_tip


#to test
def numar_cheltuieli_ce_se_intampla_intro_zi(cheltuieliile,zi):
    r = 0
    for cheltuiala in cheltuieliile:
        if (cheltuiala['zi'] == zi):
            r = r + 1
    return r
def creeaza_lista_interval_de_zile(zi_inf,zi_sup):
    zile=[]
    for zi in range(zi_inf,zi_sup+1):
        zile.append(zi)
    return zile
def pozitia_si_cheltuieliile_din_intervalul_de_zile(cheltuieliile: object, zi_inf: object, zi_sup: object, cheltuieliile_sterse: object) -> object:
    zile=creeaza_lista_interval_de_zile(zi_inf,zi_sup)
    pozitia_cheltuieli_sterse=[]
    for chel in range(0,len(cheltuieliile)):
        if cheltuieliile[chel]['zi'] in zile:
            pozitia_cheltuieli_sterse.append(chel)

            cheltuieliile_sterse.append(cheltuieliile[chel])
    return pozitia_cheltuieli_sterse
def numar_cheltuieli_ce_se_au_acelasi_tip(cheltuieliile,tip):
    r = 0
    for cheltuiala in cheltuieliile:
        if (cheltuiala['tip'] == tip):
            r = r + 1
    return r
def pozitii_cheltuieli_ce_au_acelasi_tip(cheltuieliile,tip):
    pozitii_cheltuieli_in_sir=[]
    for cheltuiala in cheltuieliile:
        if (cheltuiala['tip'] == tip):
            zi=get_zi_cheltuiala(cheltuiala)
            pozitii_cheltuieli_in_sir.append(cauta_pozitie_in_sir_a_cheltuielii_dupa_zi_si_tip(cheltuieliile,zi,tip))
    return pozitii_cheltuieli_in_sir
def pozitii_si_lista_cheltuieli_ce_au_aceeasi_zi(cheltuieliile,zi,cheltuieli_sterse):
    pozitii_cheltuieli_in_sir = []
    for cheltuiala in cheltuieliile:
        if (cheltuiala['zi'] == zi):
            tip= get_tip_cheltuiala(cheltuiala)
            pozitii_cheltuieli_in_sir.append(cauta_pozitie_in_sir_a_cheltuielii_dupa_zi_si_tip(cheltuieliile, zi, tip))
            cheltuieli_sterse.append(cheltuiala)
    return pozitii_cheltuieli_in_sir
def exista_cheltuiala_mai_mici_ca_suma(cheltuieliile,suma):
    r=0
    for cheltuiala in cheltuieliile:
        if (cheltuiala['suma'] < suma):
            r=r+1
    return r
def pozitii_cheltuieli_ce_sunt_mai_mici_ca_suma(cheltuieliile,suma):
    pozitii_cheltuieli_in_sir = []
    for cheltuiala in cheltuieliile:
        if (cheltuiala['suma'] < suma):
            tip = get_tip_cheltuiala(cheltuiala)
            zi=get_zi_cheltuiala(cheltuiala)
            pozitii_cheltuieli_in_sir.append(cauta_pozitie_in_sir_a_cheltuielii_dupa_zi_si_tip(cheltuieliile, zi, tip))
    return pozitii_cheltuieli_in_sir
def stergere_zi(cheltuieliile,zi):
    nr=numar_cheltuieli_ce_se_intampla_intro_zi(cheltuieliile,zi)
    while nr > 0:
        for cheltuiala in cheltuieliile:
            if (cheltuiala['zi'] == zi):
                cheltuieliile.remove(cheltuiala)
        nr = nr - 1
    return cheltuieliile
def stergere_cheltuieli_tip(cheltuieliile,tip,cheltuieli_sterse):
    nr = numar_cheltuieli_ce_se_au_acelasi_tip(cheltuieliile,tip)
    while nr > 0:
        for cheltuiala in cheltuieliile:
            if (cheltuiala['tip'] == tip):
                cheltuieli_sterse.append(cheltuiala)
                cheltuieliile.remove(cheltuiala)
        nr = nr - 1
    return cheltuieliile
def stergere_cheltuieli_mai_mici_ca_suma(cheltuieliile,suma,cheltuieli_sterse):
    nr = exista_cheltuiala_mai_mici_ca_suma(cheltuieliile,suma)
    while nr > 0:
        for cheltuiala in cheltuieliile:
            if (cheltuiala['suma'] <suma):
                cheltuieli_sterse.append(cheltuiala)
                cheltuieliile.remove(cheltuiala)
        nr = nr - 1
    return cheltuieliile
def suma_tipului(cheltuieliile,tip):
    suma_tip=0
    for cheltuiala in cheltuieliile:
        if(cheltuiala['tip']==tip):
            suma_tip+=cheltuiala['suma']
    return suma_tip
def suma_zi(cheltuieliile,zi):
    suma_zi=0
    for cheltuiala in cheltuieliile:
        if(cheltuiala['zi']==zi):
            suma_zi=suma_zi+cheltuiala['suma']
    return suma_zi
def zi_suma_maxima(cheltuieliile):
    zi_max=-1
    suma_max=0
    for zi in range(0,32):
        zi_respectiva=suma_zi(cheltuieliile,zi)
        if(zi_respectiva>suma_max):
            zi_max=zi
            suma_max=zi_respectiva
    return zi_max
#print
def print_cheltuiala(cheltuiala):
    print(cheltuiala)
def sort_by_type(cheltuieliile):
    copie_cheltuieliile=list(cheltuieliile)
    copie_cheltuieliile.sort(key=operator.itemgetter('tip'))
    print(copie_cheltuieliile)
def print_menu():
    print("Daca doriti sa vizualizati comenziile type: comenzi")
    print("Adauga cheltuiala\n")
    print(
            "a.adaugă o nouă cheltuială (se specifică ziua, suma, tipul)- adauga_cheltuiala\n b.actualizează cheltuială (se specifică ziua, suma, tipul)- actualizeaza_cheltuiala\n c.Printeaza lista cheltuieli!- printeaza_lista_cheltuieli\n")

    print("Ștergere \n")
    print("a.Șterge toate cheltuielile pentru ziua dată - stergere_cheltuieli_zi\nb.Șterge cheltuielile pentru un interval de timp- stergere_cheltuieli_interval_zilele \nc.Șterge toate cheltuielile de un anumit tip- stergere_cheltuieli_de_tipul\n")
    print("Cautari\n")
    print("a.Tipărește toate cheltuielile mai mari decât o sumă dată- cheltuieli_mai_mari_decat_o_suma_data\nb.Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă- cheltuieli_mai_mici_dar_mai_devreme \nc. tipărește toate cheltuielile de un anumit tip.- cheltuieli_same_type\n")
    print("Rapoarte\n")
    print("a.Tipărește suma totală pentru un anumit tip de cheltuială- print_cheltuieli_suma_tip_cheltuiala\nb.Găsește ziua în care suma cheltuită e maximă- zi_cheltuieli_maxima\nc.Tipărește toate cheltuielile ce au o anumită sumă-print_aceasi_sum\nd.Tipărește cheltuielile sortate după tip- print_sortate_dupa_tip \n")
    print("Filtrare\n")
    print("a.Elimină toate cheltuielile de un anumit tip- elimina_cheltuieli_de_tipul\nb.Elimină toate cheltuielile mai mici decât o sumă dată- elimina_cheltuieli_mai_mici_ca_suma\n")
    print("Undo\n")
    print("a.Reface ultima operație  – undo\n")
