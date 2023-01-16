a=[]
def consistent(v):
    """
    Functia este folosita pentru a observa evolutia permutarii. Aceatsa verifica forma de munte.
    :param v: permutarea curenta
    :return: False: -daca exista dublicate
                    -daca pe prima pozitie este un element mai mare ca urmat
                    -daca sirul este crescator si permutarea e finalizata
                    -daca in momentul in care a gasit un element maximal care nu este pe prima pozitie elementele dupa el nu sunt descrescatoare
            True: sirul respecta pana acum forma de munte
    """
    if(len(v)==1):
        return True
    #verificam daca exista dublicate
    if len(v)!=len (set(v)):
        return False
    #daca el de pe prima poz e vf al secventei
    if(a[v[0]]>a[v[1]]):
        return False


    okc = True
    i = 0
    #cautam primul varf sau daca sirul este crescator
    while(okc and i<len(v)-1):
        if a[v[i]]>=a[v[i+1]]:
            okc=False
        else:
            i+=1
    #daca sirul este crescator si len permutare/sol candidat
    if(okc==True and len(v)==len(a)):
        return False
    #in i ramane elementul gasit cu pozitia cea mai mare
    #daca gasim un varf mai mare atunci e invalid!
    while(i<len(v)-1):
        if a[v[i]]<=a[v[i+1]]:
            return False
        else:
            i+=1
    #altfel e valid si e o solutie candidat
    return True
def solutionFound(x):
    """
    Daca solutia a fost gasita vom printa lista
    :param x: lista de indexes
    :return: valoriile de la indexes respectivi
    """
    t=[]
    for i in range(len(a)):
        t.append(a[x[i]])
    print(t)
def solutie(x):
    '''
    Verificam daca lungimea permutarii este cat a lui a. De asemenea a trebuie sa aiba len minimum 3.
    :param x: permutarea
    :return: True daca len (x)= len(a)
             False daca nu
    '''
    if(len(x)==len(a) and len(a)>=3):
        return True
def citire():
    """
    Citirea de la tastatura a vectorului.
    Utilizatorul nu poate un sir care are copi.
    :return: numarul de numere daca s-a citit
            altfel se apeleaza recursiv pana este introdus ceva corect
    """
    a.clear()
    n=int(input("Dati numarul de numere din vector: "))
    for i in range(n):
        a.append(int(input(f"Dati {i+1}-lea numar:")))
    if(len(a)!=len(set(a))):
        print("Nu se vor putea efectua permutari de tip munte daca exista dublicate! Introduceti un vector valid")
        a.clear()
        return citire()
    return n
def back(dim):
    x = [-1]  # candidate solution
    while len(x) > 0:
        choosed = False
        while not choosed and x[-1] < dim - 1:  # if we can increase the last component
            x[-1] = x[-1] + 1  # increase the last component
            choosed = consistent(x)
        if choosed:
            if solutie(x):
                solutionFound(x)
            x.append(-1)  # expand candidate solution
        else:
            x = x[:-1]  # go back one component


def main():
    while True:
        n = citire()
        print(f"Sirul introdus de dumneavoastra este {a}")
        x = []
        back(n)
        try:
            opt = int(
                input("Mai doriti sa faceti permutari munte pentru un alt vector? Daca da introduceti 1, altfel 0!"))
            if(opt==1):
                main()
            if(opt==0):
                return
        except ValueError as ve:
            print("Optiunea nu este valida/ valabila. Astfel programul se va incheia!")
        return

if __name__=='__main__':
    main()

