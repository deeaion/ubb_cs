def compare_real_numbers(a, b):
    if abs(a - b) < 0.000000001:
        return True
    return False

#Să se determine distanța Euclideană între două locații
# identificate prin perechi de numere. De ex. distanța între
# (1,5) și (4,1) este 5.0

def problema_2(first_location: tuple, second_location: tuple) -> float:
    """
    Calculeaza distanta Euclidiana dintre doua locatii
    :param first_location: prima pereche de coordonate
    :param second_location:a doua pereche de coordonate
    :time_complexity: O(1)
    :space_complexity:O(1)
    :return:distanta euclideana dintre doua locatii
    """
    # distanta euclediana
    distance = (
        (first_location[0]-second_location[0])**2+(first_location[1]-second_location[1])**2)**(1/2)
    return distance


def test_problema_2():
    assert (compare_real_numbers(problema_2((1, 5), (4, 1)), 5.0))
    assert (problema_2((1, 1), (1, 1)) == 0)
    assert (compare_real_numbers(problema_2((1, 2, 3), (1, 4, 6)), 13 ** (1 / 2)))

import math

def problema_2_gpt(loc1, loc2):
    '''
    Returns the Euclidean distance between two locations identified by pairs of numbers.

    :param loc1: A tuple representing the coordinates of the first location (x1, y1).
    :param loc2: A tuple representing the coordinates of the second location (x2, y2).
    :return: The Euclidean distance between the two locations.
    :time complexity: O(1).
    :space complexity: O(1).
    '''

    # Unpack the coordinates
    x1, y1 = loc1
    x2, y2 = loc2

    # Calculate the Euclidean distance
    distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
    return distance
import math

def problema_2_copilot(point1, point2):
    """
    Calculează distanța Euclidiană între două puncte.

    Args:
        point1 (tuple): Coordonatele primului punct (x1, y1).
        point2 (tuple): Coordonatele celui de-al doilea punct (x2, y2).

    Returns:
        float: Distanța Euclidiană între cele două puncte.

    Time Complexity:
        O(1) - Calculul distanței se face într-un singur pas.

    Space Complexity:
        O(1) - Nu se folosește spațiu suplimentar.

    Example:
        >>> euclidean_distance((1, 5), (4, 1))
        5.0
    """
    x1, y1 = point1
    x2, y2 = point2
    squared_distance = (x2 - x1) ** 2 + (y2 - y1) ** 2
    return math.sqrt(squared_distance)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_2()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
