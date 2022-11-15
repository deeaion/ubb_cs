from domain_cheltuiala.domain_cheltuiala import *


def testing_creeaza():
    '''
    testeaza daca o cheltuiala de tip dictionar a fost creata corect
    :return: valueerror daca nu functioneaza
    '''
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    assert (zi == get_zi_cheltuiala(cheltuiala))
    assert (tip == get_tip_cheltuiala(cheltuiala))
    assert (abs(suma - get_suma_cheltuiala(cheltuiala)) < 0.00001)
def testing_if_equal_even_if_cheltuieli_sum_dif():
    '''
    testeaza daca doua cheltuieli sunt egale chiar daca au suma diferita
    :return: valueerror daca functiile nu sunt bune
    '''
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    assert (zi == get_zi_cheltuiala(cheltuiala))
    assert (tip == get_tip_cheltuiala(cheltuiala))
    assert (abs(suma - get_suma_cheltuiala(cheltuiala)) < 0.00001)
    suma_noua = 84.342
    set_suma_noua_cheltuiala(cheltuiala, suma_noua)
    assert (abs(suma_noua - get_suma_cheltuiala(cheltuiala)) < 0.00001)
    cheltuiala_aceeasi_zi_tip = creeaza_cheltuiala(zi, tip, suma_noua)
    assert (egal_cheltuiala(cheltuiala, cheltuiala_aceeasi_zi_tip))