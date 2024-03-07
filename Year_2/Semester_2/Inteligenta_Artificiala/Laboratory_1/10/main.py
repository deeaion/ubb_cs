
def problema_10(array:list[list]):
    """
        Determinare linia care are cele mai multe elemente egale cu 1
    :param array: matricea in care cautam
    :time_complexity: O(n)
    :space_complexity: O(1)
    :return: linia unde avem cei mai multi 1
    """
    n=len(array)
    m=len(array[0])
    linie=0
    i = 0
    j = m-1
    while(i<n):
        while(j>=0):
            if(array[i][j]==0):
                break
            else:
                j-=1
                linie=i
        i+=1
    return linie+1
def row_with_max_ones_naive(matrix):
    """
    Găsește indexul liniei care conține cele mai multe elemente de 1 într-o matrice binară.

    Args:
        matrix (List[List[int]]): Matricea binară sortată crescător pe linii.

    Returns:
        int: Indexul liniei cu cele mai multe 1-uri.

    Time Complexity:
        O(m*n) - Parcurgem fiecare element din matrice.

    Space Complexity:
        O(1) - Nu folosim spațiu suplimentar.

    Example:
        >>> matrix_exemplu = [[0, 0, 0, 1, 1],
        ...                   [0, 1, 1, 1, 1],
        ...                   [0, 0, 1, 1, 1]]
        >>> row_with_max_ones_naive(matrix_exemplu)
        1
    """
    max_ones = 0
    max_row_index = -1

    for i, row in enumerate(matrix):
        ones_count = row.count(1)
        if ones_count > max_ones:
            max_ones = ones_count
            max_row_index = i

    return max_row_index
def row_with_max_ones_binary_search(matrix):
    """
    Găsește indexul liniei care conține cele mai multe elemente de 1 într-o matrice binară.

    Args:
        matrix (List[List[int]]): Matricea binară sortată crescător pe linii.

    Returns:
        int: Indexul liniei cu cele mai multe 1-uri.

    Time Complexity:
        O(m*log(n)) - Parcurgem fiecare linie și aplicăm căutarea binară.

    Space Complexity:
        O(1) - Nu folosim spațiu suplimentar.

    Example:
        >>> matrix_exemplu = [[0, 0, 0, 1, 1],
        ...                   [0, 1, 1, 1, 1],
        ...                   [0, 0, 1, 1, 1]]
        >>> row_with_max_ones_binary_search(matrix_exemplu)
        1
    """
    max_ones = 0
    max_row_index = -1

    for i, row in enumerate(matrix):
        index_of_first_one = row.index(1) if 1 in row else float('inf')
        ones_count = len(row) - index_of_first_one
        if ones_count > max_ones:
            max_ones = ones_count
            max_row_index = i

    return max_row_index

def test_problema_10():
    assert (problema_10([[1,1,1,1,1],[0,0,1,1,1],[0,0,1,1,1]])==1)
    assert (problema_10([[0,0,0],[0,0,1],[0,1,1]])==3)
    assert (problema_10([[0, 0], [0, 0], [0, 1],[0,0],[1,1]]) == 5)
    print("Tests have passed")

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_10()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
