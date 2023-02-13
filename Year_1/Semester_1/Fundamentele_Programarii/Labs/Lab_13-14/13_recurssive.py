#Se dă o listă de numere întregi a1,...an. Generaţi toate permutările listei pentru care
#numerele au aspect de munte (cresc până la un punct de unde descresc). Ex. 10, 16, 27, 18,
#14, 7.
#Ni se da un vector de la tastatura:
#Se precizeaza lungimea acestuia care va deveni si lungimea permutarii listei
a=[]
def consistent(v):
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
def solutie(x):
    if(len(x)==len(a) and len(a)>=3):
        return True
def solutionFound(x):
    t=[]
    for i in range(len(a)):
        t.append(a[x[i]])
    print(t)
def back(x):
    x.append(0)
    for i in range (len(a)):
        x[-1]=i
        if(consistent(x)):
            if(solutie(x)):
                solutionFound(x)
            back(x)
    x.pop()
def citire():
    a.clear()
    n=int(input("Dati numarul de numere din vector: "))
    for i in range(n):
        a.append(int(input(f"Dati {i+1}-lea numar:")))
    if(len(a)!=len(set(a))):
        print("Nu se vor putea efectua permutari de tip munte daca exista dublicate! Introduceti un vector valid")
        a.clear()
        return citire()
    return n
def main():
    while True:
        n = citire()
        print(f"Sirul introdus de dumneavoastra este {a}")
        x = []
        back(x)

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

