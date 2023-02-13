#Conjectura lui Goldbach
#Cunoastem ca nr par= nr imp+nr imp si nr imp=nr par+nr impar. Singurul nr par prim este 2, asa ca daca n este impar testam daca n-2 este prim. Si asta nu e mereu.
#Deci n-2 este prim pentru ca suma sa fie posibila. Daca nu Conjectura Slaba a lui Goldbach spune ca e din trei nr.
#Goldbach zice ca regula este valabila pentru n>2. De fapt pe vremea sa 1 era nr prim si il includea si pe 2 dar acum nu mai este cons. adev.
#Functie
def prim(t):
    i=2
    if(t<=1):
        return False
    if(t==2):
     return True
    if(t%i==0):
        return False
    i=i+1
    while(i<=t/2):
        if(t%i==0):
            return False
        i=i+1
    return True
respecta=False
#user-input

n=int(input("Dati n="))

if(n<=2):
    print("Numarul nu poate fi construit din suma a doua numere prime conform ipotezei lui Goldbach")
if(n%2==0 and n>2):
    p1=3
    p2=n-p1
    while(p1<=n/2 and respecta==False):
        if(prim(p1) and prim(p2)):
            respecta=True
        else:
            p1+=2
            p2=n-p1
    if(n==4):
        respecta=True #singurul pentru care nu functioneaza caci este 2+2
        p1=2
        p2=2
    if(respecta==True):
        print("Numarul n, care este par ( unde ipoteza lui Goldbach pare a fi verificata de fiecare data), respecta si verifica ipoteza lui Goldbach putand fi compus din suma numerelor prime",p1,"si",p2)
    else:
        print("Nu verifica")
if(n%2==1 and n>2):
    p1=2
    p2=n-2
    if(prim(p2)==True):
        print("Desi regula lui Goldbach nu este specifica pentru numerele impare , aceasta este verificata pentru numarul n",n,"de numerele prime p1",p1,"si p2",p2)
    else:
        print("Nu verifica")

    
