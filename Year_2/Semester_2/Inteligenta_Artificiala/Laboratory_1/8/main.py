# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
#Să se genereze toate numerele (în reprezentare binară) cuprinse între
# 1 și n. De ex. dacă n = 4, numerele sunt: 1, 10, 11, 100.
def problema_8_cu_conversie_directa(n):
    """
        Genereaza toate numere cuprinse intre 1 si n
    :param n: numarul pana la care se face conversia
    :return: sirul de numere
    :time_complexity:O(nlogn)
    :space_complexity:O(1)
    """
    return [bin(i)[2:] for i in range (1,n+1)]
def to_binary(n):
    binary=""
    while(n):
        if n%2==1:
            binary+="1"
        else:
            binary+="0"
        n/=2
    return n

def problema_8(n):
    binary_numbers = ["1"]
    for i in range(2, n + 1):
        binary_numbers.append(to_binary(i))
    return binary_numbers
def test_problema_8():
    print(problema_8_cu_conversie_directa(4))
    assert(problema_8_cu_conversie_directa(4)==["1","10","11","100"])
    assert(problema_8_cu_conversie_directa(3)==["1","10","11"])


from queue import Queue

def generate_binary_queue(n):
    """
    Generează și afișează toate numerele în reprezentare binară de la 1 la n.

    Args:
        n (int): Numărul maxim.

    Time Complexity:
        O(n) - Parcurgem de la 1 la n și folosim o coadă.

    Space Complexity:
        O(n) - Spațiu suplimentar pentru coadă.

    Example:
        >>> generate_binary_queue(4)
        1
        10
        11
        100
    """
    q = Queue()
    q.put("1")
    numere=[]
    while n > 0:
        curr = q.get()
        numere.append(curr)
        q.put(curr + "0")
        q.put(curr + "1")
        n -= 1
    return numere


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_8()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
