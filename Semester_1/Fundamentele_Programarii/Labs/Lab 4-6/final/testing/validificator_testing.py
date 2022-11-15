from domain_cheltuiala.domain_cheltuiala import *
from validificator.validation_of_cheltuiala import valideaza_cheltuiala


def test_cheltuiala_gresita():
    '''
    testeaza validarea unei cheltuielii.
    Se incearca validarea unei cheltuielii greite
    :return: - daca functia ruleaza corect
               ValueError "ziua nu exista!\ntipul nu exista!\npretul nu exista!\n")
    '''
    zi = 23
    tip = "mancare"
    suma = 79.43
    cheltuiala = creeaza_cheltuiala(zi, tip, suma)
    valideaza_cheltuiala(cheltuiala)
    zi_imposibila = 32
    tip_gresit = "factura"
    suma_gresita = -54.90
    cheltuiala_gresita = creeaza_cheltuiala(zi_imposibila, tip_gresit, suma_gresita)
    try:
        valideaza_cheltuiala(cheltuiala_gresita)
        assert False
    except ValueError as ve:
        assert (str(ve) == "ziua nu exista!\ntipul nu exista!\npretul nu exista!\n")
