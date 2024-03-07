# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
# Pentru un șir cu n elemente care conține valori din mulțimea {1, 2, ..., n - 1}
# astfel încât o singură valoare se repetă de două ori, să se identifice acea valoare
# care se repetă. De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.
def problema_5(sequence:list)->int:
    """
    Determina unica valoare care se repeta de doua ori
    :param sequence: lista in care cautam valoarea care se repeta
    :time_complexity: O(1)
    :space_complexity: O(1)
    :return: int: numarul care se repeta
    """
    #calculam suma a n-1 ( unde n este lungimea vectorului) numere.
    # Celalalt element care ramane din suma totala este elementul cautat
    n=len(sequence)
    sum_Gauss=((n-1)*n)//2
    actual_sum=sum(sequence)
    #number is the difference of them
    return actual_sum-sum_Gauss
def find_duplicate_value(arr):
    """
    Identifică valoarea care se repetă de două ori într-un șir.

    Args:
        arr (List[int]): Șirul de elemente.

    Returns:
        int: Valoarea care se repetă de două ori.

    Time Complexity:
        O(n) - Parcurgem șirul o singură dată.

    Space Complexity:
        O(1) - Nu folosim spațiu suplimentar.

    Example:
        >>> find_duplicate_value([1, 2, 3, 4, 2])
        2
    """
    n = len(arr)
    total_sum = n * (n - 1) // 2
    real_sum = sum(arr)
    return real_sum - total_sum



def test_problema_5():
    assert(problema_5([1,2,3,4,2])==2)
    assert(problema_5([1,2,3,4,3])==3)
    assert(problema_5([1,1,2,3])==1)
    print("Testele au rulat cu success!")
# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_5()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
