# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
#
# Pentru un șir cu n numere întregi care conține și duplicate,
# să se determine elementul majoritar (care apare de mai mult de n / 2 ori).
# De ex. 2 este elementul majoritar în șirul [2,8,7,2,2,5,2,3,1,2,2].
def test_problema_6():
    assert (problema_6([2,8,7,2,2,5,2,3,1,2,2])==2)
    try:
        problema_6([])
    except ValueError as e:
        assert str(e)=="Sirul dat este gol!"
    assert(problema_6([1,1,1,2,2])==1)
    print("Testele au trecut cu success")

def problema_6(nums):
    """
        Determina elementul majoritar (apare de mai mult de n/2 ori)
    :param nums: sirul din care dorim sa determinam elementul majoritar
    :time_complexity: Theta(n)
    :space_complexity: O(n)
    :return: elementul majoritar
    """
    frequency = {}
    if(len(nums)==0):
        raise ValueError("Sirul dat este gol!")
    for number in nums:
        if number not in frequency:
            frequency[number] = 1
        else:
            frequency[number] += 1
    n = len(nums)
    for number in frequency.keys():
        if (frequency[number] >= n/2):
            return number
def find_majority(nums):
    """
    Găsește elementul majoritar dintr-un șir de numere întregi.

    Args:
        nums (List[int]): Șirul de numere întregi.

    Returns:
        int: Elementul majoritar.

    Time Complexity:
        O(n) - Parcurgem șirul o singură dată.

    Space Complexity:
        O(1) - Nu folosim spațiu suplimentar.

    Example:
        >>> find_majority([2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2])
        2
    """
    candidate = None
    count = 0

    for num in nums:
        if count == 0:
            candidate = num
            count = 1
        elif num == candidate:
            count += 1
        else:
            count -= 1

    return candidate
# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_6()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
