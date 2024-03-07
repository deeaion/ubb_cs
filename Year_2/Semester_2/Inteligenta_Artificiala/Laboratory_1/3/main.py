# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

def problema_3(vector1: list, vector2: list) -> float:
    """
    Determinarea produsului scalar dintre do vectori
    :param vector1: primul vector rar
    :param vector2: al doilea vector rar
    :time_complexity: O(n)
    :space_complexity: O(1)
    :return: float - produsul scalar
            exceptie- daca vectorii nu au lungimi egale
    """
    if len(vector1) != len(vector2):
        raise ValueError("Vectorii nu au lungimi egale!")
    rezultat = 0
    for i in range(0, len(vector1)):
        rezultat += vector1[i] * vector2[i]
    return rezultat


# copilot
def sparse_scalar_product(vector1, vector2):
    """
    Calculează produsul scalar al doi vectori rari.

    Args:
        vector1 (List[float]): Primul vector rar.
        vector2 (List[float]): Al doilea vector rar.

    Returns:
        float: Produsul scalar al celor doi vectori.

    Time Complexity:
        O(n) - Parcurgem doar elementele nenule din vectori.

    Space Complexity:
        O(1) - Nu folosim spațiu suplimentar.

    Example:
        >>> sparse_scalar_product([1, 0, 2, 0, 3], [1, 2, 0, 3, 1])
        4.0
    """
    if len(vector1) != len(vector2):
        raise ValueError("Vectorii trebuie să aibă aceeași dimensiune")

    scalar_product = 0
    for i in range(len(vector1)):
        if vector1[i] != 0 and vector2[i] != 0:
            scalar_product += vector1[i] * vector2[i]

    return scalar_product


def test_problema_3():
    assert (problema_3([1, 0, 2, 0, 3], [1, 2, 0, 3, 1]) == 4)
    v1 = [1, 2, 3]
    v2 = [4, 5, 6]
    assert (problema_3(v1, v2) == 32.0)
    try:
        problema_3([0, 0], [0]) == ValueError
    except ValueError as e:
        assert str(e) == "Vectorii nu au lungimi egale!"
    assert (problema_3([1, 2], [0, 0]) == 0)
    print("Tests have passed!")


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_3()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
