from bussines.functions import *
from bussines.service import *
from bussines.undo import *


#for undo
def ui_adauga_cheltuiala(cheltuieliile,params,stack):
    '''
    adauga o cheltuiala introdusa de user in lista de cheltuieli
    :param cheltuieliile: list, lista de cheltuieli
    :param params: list, in care se afla :ziua cheltuielii-integer, tip-ul cheltuielii-string,suma cheltuielii-float
    :param stack: list, stiva pentru undo
    :return: noua lista cu cheltuiala noua
    '''
    if len(params) != 3:
        print("numar parametri invalid!\n")
        return
    zi_cheltuiala = int(params[0])
    tip_cheltuiala = params[1]
    suma_cheltuiala = float(params[2])
    adauga_cheltuiala_service(cheltuieliile, zi_cheltuiala, tip_cheltuiala, suma_cheltuiala)
    comanda_undo = ("adauga_cheltuiala",creeaza_cheltuiala(zi_cheltuiala,tip_cheltuiala,suma_cheltuiala))
    stack.append(comanda_undo)
def ui_actualizeaza_cheltuiala(cheltuieliile,params,stack):
    '''
    modifica o cheltuiala existenta in sir . Ea se identifica dupa ziua si tipul ei si userul trebuie sa adauge ziua noua, tipul nou, suma noua
    :param cheltuieliile: lista de cheltuieli
    :param params: list, parametrii introdusi de user: zi-int,tip-string al cheltuielii din sir si ziua_noua-int, tip_nou-string, suma_noua-float in care
    va fi modificat
    :param stack: stiva pentru undo
    :return: lista cheltuieliile cu cheltuiala modificata
    '''
    if len(params)!=5:
        print("numar parametri invalid!\n")
        return
    zi_cheltuiala = int(params[0])
    tip_cheltuiala = params[1]
    zi_noua=int(params[2])
    tip_nou=params[3]
    suma_noua= float(params[4])
    cheltuiala=cauta_cheltuiala_dupa_zi_tip_service(cheltuieliile,zi_cheltuiala,tip_cheltuiala)
    cheltuiala_veche=dict(cheltuiala)
    modifica_cheltuiala_dupa_zi_tip_service(cheltuieliile,zi_cheltuiala,tip_cheltuiala,zi_noua,tip_nou,suma_noua)
    cheltuiala_noua=cauta_cheltuiala_dupa_zi_tip_service(cheltuieliile,zi_noua,tip_nou)
    comanda_undo=("undo_modifica_comanda",cheltuiala_veche,cheltuiala_noua)
    stack.append(comanda_undo)
def ui_stergere_zi(cheltuieliile,params,stack):
    '''
    se sterg toate cheltuieliile ce au ziua introdusa de user
    :param cheltuieliile: list, lista de cheltuieli
    :param params: list, unde se afla ziua-integer introdusa de user a carui cheltuieli vor fi sterse
    :param stack: stiva pentru undo
    :return: lista modificata
    '''
    if len(params) != 1:
        print("Nr parametri invalid\n")
        return
    zi_specific=int(params[0])
    cheltuieliile_sterse =[]
    pozitii_cheltuiala = pozitii_si_lista_cheltuieli_ce_au_aceeasi_zi(cheltuieliile, zi_specific,cheltuieliile_sterse)
    stergere_zi(cheltuieliile, zi_specific)
    comanda_undo = ("undo_sterge_zi", cheltuieliile_sterse, pozitii_cheltuiala)
    stack.append(comanda_undo)
def ui_stergere_interval_zile(cheltuieliile,params,stack):
    '''
    se sterg toate cheltuieliile ce sunt intervalul de zile introdus de user
    :param cheltuieliile: list, lista de cheltuieli
    :param params: list, unde se afla zilele-integer, zi_inf si zi_sup introduse de user a caror cheltuieli vor fi sterse
    :param stack: stiva pentru undo
    :return: lista modificata
    '''
    if len(params)!= 2:
        print("Nr parametri invalid\n")
        return
    zi_inf=int(params[0])
    zi_sup=int(params[1])
    if zi_inf>zi_sup:
        print("Intervalul nu este pozibil")
        return
    cheltuieliile_sterse=[]
    pozitii_cheltuiala=pozitia_si_cheltuieliile_din_intervalul_de_zile(cheltuieliile, zi_inf, zi_sup, cheltuieliile_sterse)
    comanda_undo = ("undo_elimina_cheltuieli_dintr_un_interval_de_zile", cheltuieliile_sterse, pozitii_cheltuiala)
    stack.append(comanda_undo)
    for zi in range(zi_inf,zi_sup+1):
        stergere_zi(cheltuieliile,zi)
def ui_elimina_mai_mici_ca_suma(cheltuieliile,params,stack):
    '''
        se sterg toate cheltuieliile ce au suma mai mica ca cea introdusa de user de user
        :param cheltuieliile: list, lista de cheltuieli
        :param params: list, unde se afla suma-float introdusa de user a carei cheltuieli vor fi sterse
        :param stack: stiva pentru undo
        :return: lista modificata
        '''
    if len(params) != 1:
        print("Nr parametri invalid\n")
        return
    suma = float(params[0])
    cheltuieliile_sterse = []
    pozitii_cheltuiala = pozitii_cheltuieli_ce_sunt_mai_mici_ca_suma(cheltuieliile, suma)
    stergere_cheltuieli_mai_mici_ca_suma(cheltuieliile, suma,cheltuieliile_sterse)
    comanda_undo = ("undo_elimina_mai_mici_ca_suma", cheltuieliile_sterse, pozitii_cheltuiala)
    stack.append(comanda_undo)
def ui_elimina_tip(cheltuieliile,params,stack):
    '''
        se sterg toate cheltuieliile ce au tipul introdus de user
        :param cheltuieliile: list, lista de cheltuieli
        :param params: list, unde se afla tipul-string introdus de user a carui cheltuieli vor fi sterse
        :param stack: stiva pentru undo
        :return: lista modificata
        '''
    if len(params) != 1:
        print("Nr parametri invalid\n")
        return
    tip = params[0]
    cheltuieliile_sterse=[]
    pozitii_cheltuiala=pozitii_cheltuieli_ce_au_acelasi_tip(cheltuieliile,tip)
    stergere_cheltuieli_tip(cheltuieliile, tip,cheltuieliile_sterse)
    comanda_undo=("undo_sterge_tip",cheltuieliile_sterse,pozitii_cheltuiala)
    stack.append(comanda_undo)
#printing functions
def ui_printeaza_lista_cheltuiala(cheltuieliile,params,stack):
    '''
    printeaza fiecare cheltuiala pe un rand
    :param cheltuieliile: list,lista de cheltuieli
    :param params: -
    :param stack: stiva pentru undo
    :return: printeaza lista de cheltuieli
    '''
    if len(params)!=0:
        print("numar parametri invalid\n")
        return
    if numar_cheltuieli_lista(cheltuieliile)==0:
        print("Nu exista cheltuieli introduse\n")
        return
    for cheltuiala in cheltuieliile:
        print_cheltuiala(cheltuiala)
def ui_print_mai_mari_ca_suma(cheltuieliile,params,stack):
    '''
    printeaza cheltuieliile din lista mai mari ca suma introdusa de user
    :param cheltuieliile: list, lista cheltuieliilor
    :param params: suma cu care vor fi comparate sumele cheltuieliilor
    :param stack: stiva pentru undo
    :return: printeaza cheltuieliile mai mari ca suma
    '''
    if len(params)!=1:
        print("Nr parametri invalid\n")
        return
    suma=float(params[0])
    for cheltuiala in cheltuieliile:
        if(cheltuiala['suma']>suma):
            print_cheltuiala(cheltuiala)
def ui_print_mai_mici_si_mai_devreme(cheltuieliile,params,stack):
    '''
    printeaza cheltuieliile mai mici ca o suma si mai devreme precum o data introdusa de user
    :param cheltuieliile: list, lista de cheltuieli
    :param params: suma-float, ziua-integer, cu care vor fi comparate cheltuieliile din lista
    :param stack: stiva pentru undo
    :return: printeaza cheltuieliile ce intrunesc conditia
    '''
    if len(params) != 2:
        print("Nr parametri invalid\n")
        return
    suma_data = float(params[0])
    ziua_data = int(params[1])
    if ziua_data<=0 and ziua_data>31:
        print("Nu exista acesta zi")
        return
    for cheltuiala in cheltuieliile:
        if(cheltuiala['zi']<ziua_data and cheltuiala['suma']<suma_data):
            print_cheltuiala(cheltuiala)
def ui_print_same_type(cheltuieliile,params,stack):
    '''
    printeaza cheltuieliile ce au acelasi tip ca tipul introdus de utilizator
    :param cheltuieliile: list, lista de cheltuieli
    :param params: tipul-string cu care vor fi comparate cheltuieliile
    :param stack: stiva de undo
    :return: printeaza cheltuieliile de tipul specificat
    '''
    if len(params) != 1:
        print("Nr parametri invalid\n")
        return
    tip_specific = params[0]
    for cheltuiala in cheltuieliile:
        if(cheltuiala['tip']==tip_specific):
            print_cheltuiala(cheltuiala)
def ui_print_sum_same_type(cheltuieliile,params,stack):
    '''
    printeaza suma unui tip specificat de user de la tastatura
    :param cheltuieliile: list, lista de cheltuieli
    :param params: tipul- string
    :param stack: stiva de undo
    :return: printeaza toate cheltuieliile ce respecta conditia
    '''
    if len(params)!=1:
        print("Nr parametri invalid\n")
        return
    tip_specific = params[0]
    s = suma_tipului(cheltuieliile,tip_specific)
    print(s)
def ul_zi_suma_maxima(cheltuieliile,params,stack):
    '''
    printeaza ziua in care cheltuieliile au cea mai mare suma
    :param cheltuieliile: list, lista de cheltuieli
    :param params: -
    :param stack: stiva de undo
    :return: printeaza ziua cu cea mai mare suma
    '''
    zi=zi_suma_maxima(cheltuieliile)
    print(zi)
def ui_anumita_suma(cheltuieliile,params,stack):
    '''
    printeaza cheltuieliile ce au aceeasi suma ca suma introdusa de utilizator
    :param cheltuieliile: list, lista de cheltuieli
    :param params: suma-float cu care vor fi comparate cheltuieliile
    :param stack: stiva de undo
    :return: printeaza cheltuieliile de suma specificata
    '''
    if len(params) != 1:
        print("Nr parametri invalid\n")
        return
    suma_s = float(params[0])
    for cheltuiala in cheltuieliile:
        if (cheltuiala['suma'] == suma_s):
            print_cheltuiala(cheltuiala)
def ui_print_sortate_dupa_tip(cheltuieliile,params,stack):
    '''
    se creeaza o copie a cheltuieliilor si se sorteaza dupa tip si apoi se printeaza
    :param cheltuieliile: list, lista de cheltuieli
    :param params: -
    :param stack: stiva de undo
    :return: printeaza lista sortata
    '''
    sort_by_type(cheltuieliile)
def ui_print_menu(cheltuieliile,params,stack):
    '''
    daca user-ul are nevoie de ajutor se printeaza un menu pentru al ajuta
    :param cheltuieliile:list, lista de cheltuieli
    :param params: -
    :param stack: stiva de undo
    :return: printeaza meniul
    '''
    print_menu()
def ui_undo(cheltuieliile,params,stack):
    '''
    functia de refacere a operatiei anterioare
    Se aplica doar pentru cele ce au un efect asupra listei de cheltuieli nu si la printari
    :param cheltuieliile: list,lista de cheltuieli
    :param params: -
    :param stack: lista acumulata de operatii pentru undo
    :return: lista precedenta daca inca se afla ceva in stack
               "Nothing to undo" daca nu mai se poate efectua undo
    '''
    if (len(stack) == 0):
            print("Nothing to undo")
    elif(len(stack)==1):
        sterge_cheltuiala_dupa_zi_tip(cheltuieliile,stack[0][1]['zi'],stack[0][1]['tip'])
        stack.pop()
    elif stack[len(stack) - 1][0] == "adauga_cheltuiala":
        undo_adauga_cheltuiala(cheltuieliile, stack[-1][1])
        stack.pop(-1)
    elif stack[len(stack)-1][0]=="undo_modifica_comanda":
        zi_veche=get_zi_cheltuiala(stack[-1][1])
        tip_vechi=get_tip_cheltuiala(stack[-1][1])
        suma_veche=get_suma_cheltuiala(stack[-1][1])
        zi_noua=get_zi_cheltuiala(stack[-1][2])
        tip_nou=get_tip_cheltuiala(stack[-1][2])
        undo_modifica_cheltuiala(cheltuieliile,zi_veche,tip_vechi,suma_veche,zi_noua,tip_nou)
        stack.pop(-1)
    elif stack[-1][0]=="undo_sterge_tip":
        lung_adaugare=len(stack[-1][1])
        i=0
        while(i<lung_adaugare):
            undo_sterge_tip(cheltuieliile, stack[-1][1][i], stack[-1][2][i])
            i+=1
        stack.pop(-1)
    elif stack[-1][0]=="undo_sterge_zi":
        lung_adaugare = len(stack[-1][1])
        i = 0
        while (i < lung_adaugare):
            undo_sterge_zi(cheltuieliile, stack[-1][1][i], stack[-1][2][i])
            i=i+1
        stack.pop(-1)
    elif stack[-1][0]=="undo_elimina_mai_mici_ca_suma":
        lung_adaugare = len(stack[-1][1])
        i = 0
        while (i < lung_adaugare):
            undo_elimina_mai_mici_ca_suma(cheltuieliile, stack[-1][1][i], stack[-1][2][i])
            i += 1
        stack.pop(-1)
    elif stack[-1][0]=="undo_elimina_cheltuieli_dintr_un_interval_de_zile":
        lung_adaugare = len(stack[-1][1])
        i = 0
        while (i < lung_adaugare):
            undo_elimina_cheltuieli_dintr_un_interval_de_zile(cheltuieliile, stack[-1][1][i], stack[-1][2][i])
            i=i+1
        stack.pop(-1)
