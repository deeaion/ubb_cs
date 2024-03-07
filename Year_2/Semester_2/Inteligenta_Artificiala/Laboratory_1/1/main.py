#Problema 1
# Să se determine ultimul (din punct de vedere alfabetic) cuvânt care poate apărea într-un text
    # care conține mai multe cuvinte separate prin ” ” (spațiu). De ex. ultimul (dpdv alfabetic)
    # cuvânt din ”Ana are mere rosii si galbene” este cuvântul "si".
"""

    :param text: the text we want to find the last word in the test sorted
    :time_complexity: Theta(n)
    :space_complexity: Theta(1)
    :return:the first word in descending order
    """
def last_word_in_alphabetical_order_by_me(text: str):
    if not len(text):
        raise AttributeError("Text is empty!\n")
    parsed_text = text.split(' ')
    last_word: str = parsed_text[0]
    parsed_text = parsed_text[1:]
    for word in parsed_text:
        if word > last_word:
            last_word = word
    return last_word
def last_word_in_alphabetical_order_by_copilot(text: str):
    """
       Găsește ultimul cuvânt (din punct de vedere alfabetic) dintr-un text.

       Args:
           text (str): Textul de analizat.

       Returns:
           str: Ultimul cuvânt alfabetic din text.

       Time Complexity:
           O(n*log(n)) - Sortarea cuvintelor.

       Space Complexity:
           O(n) - Spațiu suplimentar pentru lista de cuvinte.

       Example:
           >>> last_word_in_alphabetical_order_by_copilot("Ana are mere rosii si galbene")
           'si'
       """
    cuvinte = text.split()  # Descompunerea textului în cuvinte
    cuvinte.sort()  # Sortarea cuvintelor în ordine alfabetică
    return cuvinte[-1]  # Ultimul cuvânt din lista sortată
def last_word_in_alphabetical_order_by_gpt(text: str):
    '''
     Returns the last (alphabetically) word that can appear in the text.

     :param text: A string containing multiple words separated by spaces.
     :return: The last (alphabetically) word in the text.
     :time complexity: O(n*log(n)), where n is the number of words in the text.
     :space complexity: O(n), where n is the number of words in the text.
     '''

    words = text.split()  # Split the text into individual words
    words.sort()  # Sort the words alphabetically
    return words[-1]  # Return the last (alphabetically) word
def test_last_word():
    assert (last_word_in_alphabetical_order_by_me("Ana are mere rosii si galbene") == "si")
    assert (last_word_in_alphabetical_order_by_me("A B C D E Z H") == "Z")
    assert (last_word_in_alphabetical_order_by_me("A BC D ZJA ZT Z") == "ZT")
# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    test_last_word()
