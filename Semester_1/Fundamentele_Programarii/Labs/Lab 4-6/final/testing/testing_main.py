from testing.domain_testing import *
from testing.function_testing import *
from testing.repository_testing import *
from testing.service_testing import *
from testing.validificator_testing import *
def ruleaza_teste_domain():
    '''
    ruleaza teste domain!
    :return: valueerror daca nu functioneaza
    valueerror daca functiile nu sunt bune
    '''
    testing_creeaza()
    testing_if_equal_even_if_cheltuieli_sum_dif()


def ruleaza_teste_validation():
    '''
    ruleaza teste validare cheltuiala
    :return:
    testeaza validarea unei cheltuielii.
    Se incearca validarea unei cheltuielii greite
    :return: - daca functia ruleaza corect
               ValueError "ziua nu exista!\ntipul nu exista!\npretul nu exista!\n")

    '''
    test_cheltuiala_gresita()

def ruleaza_teste_repo():
    '''
    ruleaza teste repository
    :return:
    '''

    testing_adaugare_si_lungime_existenta_in_lista_cheltuiala_corecta()
    testing_cauta_cheltuiala_existenta()
    testing_adaugare_aceeasi_cheltuiala_in_lista()
    testing_cauta_cheltuiala_inexistenta()
    testing_modifica_cheltuiala_inexistenta()
    testing_sterge_cheltuiala_inexistenta()
    testing_modificare_cheltuiala_existenta()
    testing_sterge_cheltuiala_existenta()

def ruleaza_teste_service():
    testing_adauga_cheltuiala_service()
    testing_cauta_cheltuiala_service()
    testing_modifica_cheltuiala_service()
    testing_stergere_cheltuiala_service()


def ruleaza_teste_functii():
    test_numar_cheltuieli_ce_se_intampla_intro_zi()
    test_numar_cheltuieli_ce_se_au_acelasi_tip()
    test_exista_cheltuiala_mai_mici_ca_suma()
    test_stergere_zi()
    test_stergere_cheltuieli_tip()
    test_stergere_interval_zile()
    test_stergere_cheltuieli_mai_mici_ca_suma()
    test_suma_tipului()
    test_suma_zi()
    test_zi_suma_maxima()
    test_undo_adauga()
    test_undo_elimina_tip()
    test_undo_cheltuieli_mai_ieftne()
    test_undo_elimina_zi()
    test_undo_elimina_interval_zile()
    test_undo_modifica_cheltuiala()
def ruleaza_teste():
    ruleaza_teste_domain()
    print("Teste trecute cu succes")
    ruleaza_teste_validation()
    print("Teste validare cu succes")
    ruleaza_teste_repo()
    print("Teste repo trecute cu succes")
    ruleaza_teste_service()
    print("Teste service trecute cu succes")
    ruleaza_teste_functii()
    print("Teste functii trecute cu succes")
