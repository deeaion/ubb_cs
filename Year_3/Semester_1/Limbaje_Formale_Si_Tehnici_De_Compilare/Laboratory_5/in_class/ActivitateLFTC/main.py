accesibile = {}
neterminale_gasite_in_reguli = []
line_number = 0
# verificare ce simboluri sunt innacessibile in gramatica
with open("./gramatica.txt", "r") as f:
    for line in f:
        line_split = line.strip().split("->")
        # pun simbolul de start in dictionarul accesibil
        left_symbol = line_split[0].strip()
        regula = line_split[1].strip()
        if line_number == 0:
            accesibile[left_symbol] = 1
            line_number += 1
        if left_symbol not in accesibile:
            accesibile[left_symbol] = 0
        for symbol in regula:
            if symbol.isupper():
                accesibile[symbol] = 1

innaccesibile = [symbol for symbol in accesibile if accesibile[symbol] == 0]
if len(innaccesibile) == 0:
    print("Gramatica nu are simboluri innaccesibile")
else:
    print("Gramatica are urmatorele simboluri innaccesibile:")
    for symbol in innaccesibile:
        print(symbol)