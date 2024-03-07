# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
# Să se determine cuvintele unui text care apar exact o singură dată în acel text.
# De ex. cuvintele care apar o singură dată în
# ”ana are ana are mere rosii ana" sunt: 'mere' și 'rosii'.
def cuvinte_unice(text):
    """
    Găsește cuvintele care apar exact o singură dată într-un text.

    Args:
        text (str): Textul de analizat.

    Returns:
        set: Set-ul de cuvinte unice.

    Time Complexity:
        O(n) - Parcurgem textul și construim un dicționar cu frecvențele cuvintelor.

    Space Complexity:
        O(n) - Spațiu suplimentar pentru dicționarul de frecvențe.

    Example:
        >>> cuvinte_unice("ana are ana are mere rosii ana")
        {'mere', 'rosii'}
    """
    cuvinte = text.split()  # Descompunerea textului în cuvinte
    frecvente = {}  # Dicționar pentru frecvențele cuvintelor

    for cuvant in cuvinte:
        frecvente[cuvant] = frecvente.get(cuvant, 0) + 1

    cuvinte_unice = set()
    for cuvant, frecventa in frecvente.items():
        if frecventa == 1:
            cuvinte_unice.add(cuvant)

    return cuvinte_unice

def problema_4(text: str):
    """
    Cautam cuvintele care se repeta o singura data
    :param text: textul in care vom cauta cuvintele care apar o singura data in text
    :time_complexity: Theta(N)
    :space_complexity: Theta(M) , unde M este numarul de cuvinte ce nu se repeta
    :return: list: lista cuvintelor ce nu se repeta

    """
    words = text.split()
    word_frequency = {}
    # Theta(N)
    for word in words:
        if word in word_frequency:
            word_frequency[word] = word_frequency.get(word) + 1
        else:
            word_frequency[word] = 1
    non_repeating_word: list[str] = []
    for word in word_frequency.keys():
        if word_frequency[word] == 1:
            non_repeating_word.append(word)
    return non_repeating_word

def test_problema_4():
    assert (problema_4("ana are ana are mere rosii ana")==["mere","rosii"])
    assert (problema_4("clara clara")==[])
    assert (problema_4("clara are")==["clara","are"])
    print("Tests have passed!")


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_problema_4()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
