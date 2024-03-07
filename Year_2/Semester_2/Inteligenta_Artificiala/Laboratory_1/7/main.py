# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

# Să se determine al k-lea cel mai mare element al unui șir de
# numere cu n elemente (k < n). De ex. al 2-lea cel mai mare element
# din șirul [7,4,6,3,9,1] este 7.
def test_problema7():
    assert (problema_7([7,4,6,3,9,1],2)==7)
    try:
        problema_7([],5)
    except ValueError as e:
        assert (str(e)=="Lista are doar 0 elemente, astfel incat nu se poate descoperi al 5-lea cel mai mare element!")
    assert (problema_7([1,2,3,4],2)==3)
    print("Tests ran successfully!")
def problema_7(elements:list,k:int):
    """
    Determin al k lea cel mai mare element al sirului elements
    :param elements: sirul in care cautam cel de al k lea element
    :param k: al catelea element cel mai mare il dorim
    :time_complexity: O(nlogn)
    :space_complexity: O(1)
    :return: al k lea element cel mai mare din lista
    """
    #cel mai usor e sa fie sortat si sa ii dau pe cel mai mare al k lea
    if(len(elements)+1<k):
        raise ValueError(f"Lista are doar {len(elements)} elemente, astfel incat nu se poate descoperi al {k}-lea cel mai mare element!")
    return sorted(elements,reverse=True)[k-1]
def kth_largest(nums, k):
    """
    Găsește al k-lea cel mai mare element dintr-un șir de numere.

    Args:
        nums (List[int]): Șirul de numere întregi.
        k (int): Poziția dorită (k < len(nums)).

    Returns:
        int: Al k-lea cel mai mare element.

    Time Complexity:
        O(n) - Parcurgem șirul o singură dată.

    Space Complexity:
        O(1) - Nu folosim spațiu suplimentar.

    Example:
        >>> kth_largest([7, 4, 6, 3, 9, 1], 2)
        7
    """
    if k <= 0 or k > len(nums):
        raise ValueError("k trebuie să fie între 1 și lungimea șirului")

    def partition(left, right):
        pivot = nums[right]
        i = left
        for j in range(left, right):
            if nums[j] >= pivot:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        nums[i], nums[right] = nums[right], nums[i]
        return i

    left, right = 0, len(nums) - 1
    while True:
        pivot_index = partition(left, right)
        if pivot_index == k - 1:
            return nums[pivot_index]
        elif pivot_index < k - 1:
            left = pivot_index + 1
        else:
            right = pivot_index - 1

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema7()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
