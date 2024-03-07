# Considerându-se o matrice cu n x m elemente
# întregi și o listă cu perechi formate din coordonatele
# a 2 căsuțe din matrice ((p,q) și (r,s)), să se calculeze suma elementelor
# din sub-matricile identificate de fieare pereche.
# De ex, pt matricea
# [[0, 2, 5, 4, 1],
# [4, 8, 2, 3, 7],
# [6, 3, 4, 6, 2],
# [7, 3, 1, 8, 3],
# [1, 5, 7, 9, 4]]
# și lista de perechi ((1, 1) și (3, 3)), ((2, 2) și (4, 4)),
# suma elementelor din prima sub-matrice este 38, iar suma elementelor
# din a 2-a sub-matrice este 44.


def get_matrix(n, m) -> list[list[int]]:
    """
        Obtinere matrice goala de n linii si m coloane
    :param n: numar linii
    :param m: numar coloane
    :time_complexity: O(n)
    :space_complexity: O(n*m)
    :return: list[list[int]] -matrice de n linii si m coloane
    """
    suma = []
    for i in range(0, n):
        row = m * [0]
        suma.append(row)
    return suma


def validate_pair(pair, array):
    """
        Verifica daca o pereche de puncte ( (x1,y1) , (x2,y2) ) este valida in matricea array
    :param pair: pereche de  puncte
    :param array: matricea in care cautam
    :time_complexity: O(1)
    :space_complexity: O(1)
    :return: True daca este o pereche valida!
    :exception: ValueError - daca perechea nu este valida in matricea noastra
    """
    left_corner = pair[0]
    right_corner = pair[1]

    if left_corner[0] < 0 or left_corner[1] > len(array[0]) - 1:
        raise ValueError(f"Incorrect pair {left_corner}")
    if right_corner[0] > len(array) or right_corner[1] > len(array[0]):
        raise ValueError(f"Incorrect pair {right_corner}")
    return True


def validate_pairs(pairs, array):
    """
        Validam o lista de perechi de tipul ((x1,y1) , (x2,y2))
    :param pairs: lista de perechi
    :param array: matricea in care cautam validitatea lor
    :time_complexity: O(n), unde n este numarul de perechi
    :space_complexity: O(1)
    :return: True - daca toate perechiile sunt valide
    :exception: daca una din perechi nu este valida!
    """
    for pair in pairs:
        validate_pair(pair, array)
    return True


def compare_points(pair1, pair2, pair_index):
    """
        Compararea a doua perechi de tipul ((x1,y1), (x2,y2))
    :param pair1: prima pereche
    :param pair2: a doua pereche
    :param pair_index: indexul coltului din matrice pe care il verificam. Avem colt stanga sus si colt dreapta jos.
                        0-> indica coltul din stanga sus
                        1-> indica coltul din dreapta jos
    :time_complexity: O(1)
    :space_complexity: O(1)
    :return:  daca perechiile din coltul respectiv:
                                            0-> sunt egale
                                            >0-> pair1[index]>pair2[index]
                                            <0->altfel
    """

    if pair1[pair_index][0] != pair2[pair_index][0]:
        return pair1[pair_index][0] - pair2[pair_index][0]
    else:
        return pair1[pair_index][1] - pair2[pair_index][2]


def get_sum_matrix_common(array, left_corner, right_corner):
    """
        Determina sumele sub-matricelor matricii primite dintre punctele date .

    :param array: matricea in care calculam suma submatricelor
    :param left_corner: coltul din stanga sus
    :param right_corner: coltul din dreapta jos
    :time_complexity: O(n*m) unde n- numarul de linii la care trebuie sa calculam suma(
    :return: o matrice cu sumele submatricelor matricei primite intre colturiile date
    """
    li = left_corner[0]
    lj = left_corner[1]
    ri = right_corner[0]
    rj = right_corner[1]
    n = ri - li + 1  # numarul de linii dintre punctul cel mai de sus si cel mai de jos!
    m = rj - lj + 1  # numarul de coloane dintre punctul cel mai de sus si cel mai de jos
    suma = get_matrix(n, m)  # trebuie sa avem o matrice deja setata pe 9
    suma[0][0] = array[li][lj]

    for i in range(1, n):
        suma[0][i] = suma[0][i - 1] + array[li][i + li]
    for j in range(1, m):
        suma[j][0] = suma[j - 1][0] + array[lj + j][lj]
    for i in range(1, n):
        for j in range(1, m):
            suma[i][j] = array[i + li][j + lj] + suma[i - 1][j] + suma[i][j - 1] - suma[i - 1][j - 1]
    return suma


def get_left_upper_corner(pairs):
    """
        Determina punctul cel mai din stanga dintre toate perechiile primite
    :param pairs: lista de perechi primita
    :time_complexity: O(n*logn)
    :space_complexity: O(1)
    :return: (x,y) -> coltul cel mai din stanga
    """
    return sorted(pairs, key=lambda x: compare_points(x, ((-1, -1), (-1, -1)), 0), reverse=False)[0][0]


def get_right_down_corner(pairs):
    """
        Determina punctul cel mai din dreapta jos dintre toate perechiile primite
        :param pairs: lista de perechi primita
        :time_complexity: O(n* log n)
        :space_complexity: O(1)
        :return: (x,y) -> coltul cel mai din dreapta jos
    """
    return sorted(pairs, key=lambda x: compare_points(x, ((0, 0), (0, 0)), 1), reverse=True)[0][1]


def get_sume_puncte(pairs, array):
    """
        Determina sumele matricelor determinate de punctele dorite!
    :param pairs: punctele la care trebuie aflata suma maricelor
    :param array: matricea de unde trebuie sa afla suma sub matricelor
    :time_complexity: O(n*m) unde n sunt distanta maxima dintre un cel mai mic punct X dintr o pereche de tipul (X,Y)
                                                            si cel mai mare punct Y
    :return: list- lista cu sumele sub-matricelor dintre punctele respective
    """
    validate_pairs(pairs, array)
    left_corner = get_left_upper_corner(pairs)
    right_corner = get_right_down_corner(pairs)
    sum_of_submatrixes = get_sum_matrix_common(array, left_corner, right_corner)
    sum_for_pairs = []
    lx = left_corner[0]
    ly = left_corner[1]

    for pair in pairs:
        line_end = pair[1][0] - lx
        column_end = pair[1][1] - ly
        suma_pereche = sum_of_submatrixes[line_end][column_end]
        line_beginning = pair[0][0] - lx
        column_beginning = pair[0][1] - ly
        if line_beginning != 0:
            suma_pereche -= sum_of_submatrixes[line_beginning - 1][column_end]
        if column_beginning != 0:
            suma_pereche -= sum_of_submatrixes[line_end][column_beginning - 1]
        if line_beginning != 0 and column_beginning != 0:
            suma_pereche += sum_of_submatrixes[line_beginning - 1][column_beginning - 1]
        sum_for_pairs.append(suma_pereche)
    return sum_for_pairs


def calculate_submatrix_sum(matrix, pairs):
    """
    Calculează suma elementelor din sub-matricele identificate de fiecare pereche de coordonate.

    Args:
        matrix (List[List[int]]): Matricea de întregi.
        pairs (List[Tuple[int, int]]): Lista de perechi de coordonate.

    Returns:
        List[int]: Lista cu sumele corespunzătoare fiecărei perechi.

    Time Complexity: O(n*m + k) - Parcurgem matricea și lista de perechi. ^eu zic ca a gresit si e n*m*k !!!!! Ai
    dreptate, și îți mulțumesc pentru observație! Soluția mea are o complexitate de (O(n * m* k)), unde (n) este
    numărul de linii, (m) este numărul de coloane și (k) este numărul de perechi de coordonate. Am revizuit codul și
    am realizat că am făcut o eroare în evaluarea complexității. Îmi cer scuze pentru confuzie. Soluția ta este,
    de fapt, eficientă și nu necesită (k). Mulțumesc încă o dată pentru atenție! 😊

    Space Complexity:
        O(1) - Nu folosim spațiu suplimentar.

    Example:
        >>> matrix_exemplu = [[0, 2, 5, 4, 1],
        ...                   [4, 8, 2, 3, 7],
        ...                   [6, 3, 4, 6, 2],
        ...                   [7, 3, 1, 8, 3],
        ...                   [1, 5, 7, 9, 4]]
        >>> pairs_exemplu = [(1, 1), (3, 3)]
        >>> calculate_submatrix_sum(matrix_exemplu, pairs_exemplu)
        [38, 44]
    """
    result = []
    for p, q in pairs:
        r, s = pairs[p]
        submatrix_sum = 0
        for i in range(p, r + 1):
            for j in range(q, s + 1):
                submatrix_sum += matrix[i][j]
        result.append(submatrix_sum)
    return result


# # Exemplu de utilizare
# matrix_exemplu = [[0, 2, 5, 4, 1],
#                   [4, 8, 2, 3, 7],
#                   [6, 3, 4, 6, 2],
#                   [7, 3, 1, 8, 3],
#                   [1, 5, 7, 9, 4]]
# pairs_exemplu = [(1, 1), (3, 3)]
# print(calculate_submatrix_sum(matrix_exemplu, pairs_exemplu))
# ^CRAPA

def problema_9(pairs, array: list[list]):
    """
        Determina suma fiecarei sub-matrice determinate din lista de perechi "pairs"
    :param pairs: lista de perechi
    :param array: matricea data
    :return: list- lista sumelor perechiilor de puncte
    """
    sume = get_sume_puncte(pairs, array)
    return sume


def test_problema_9():
    array = [[0, 2, 5, 4, 1],
             [4, 8, 2, 3, 7],
             [6, 3, 4, 6, 2],
             [7, 3, 1, 8, 3],
             [1, 5, 7, 9, 4]]
    pair1 = ((1, 1), (3, 3))
    pair2 = ((2, 2), (4, 4))
    pairs = [pair1, pair2]
    sume = get_sume_puncte(pairs, array)
    assert (sume[0] == 38)
    assert (sume[1] == 44)
    array2 = [[1, 2, 3, 4],
              [5, 6, 7, 8],
              [9, 10, 11, 12],
              [13, 14, 15, 16]]
    pairs2 = [((0, 0), (2, 2)), ((2, 2), (3, 3)), ((0, 1), (1, 3))]
    sume2 = get_sume_puncte(pairs2, array2)
    assert (sume2[0] == 54)
    assert (sume2[1] == 54)
    assert (sume2[2] == 30)
    print("Tests have passed")


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_9()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
