def descompunere(t):
    i=2
    con=0
    if(t==1):
        return 1
    if(t==2):
        return 1
    if(t%i==0):
        while(t%i==0):
            t/=i
        con+=1
    while(i<=t/2):
        if(t%i==0):
            con+=1
            while(t%i==0):
                t/=i
        i=i+2
    return con
def descompunere_pana_la(t,f):
    i=2
    con=1
    if(t==1 and con==f):
        return 1
    if(t==2 and 2==f):
        return 2
    con=2
    if(t%i==0):
        while(t%i==0):
            t/=i
        con+=1
    if(con==f):
        return i
    while(i<=t/2):
        if(t%i==0):
            con+=1
            if(con==f):
                return i
            while(t%i==0):
                t/=i
        i=i+2
    v=[]
    ad
n=int(input("Dati n="))
i=10
p=0
p=descompunere(6)
print(p)
while(p<=n):
        p+=descompunere(i)
        i+=1
        if(p==n):
            print(descompunere_pana_la(i,descompunere(i-1)))
        if(p>n):
            print(descompunere(i-2,p-n)) 
    
#deci trebuie sa descompunem fiecare nr in factori primi si sa retinem cati are fiecare fiind adunat la o suma. suma o tot comparam pana cand este mai maresau egala cu  n. Trebuie sa retinem
        #i.Daca s>n atunci i-- si il descompui cautand factorul s-n care este raspunsul
        #daca s=n cautam ultimul factor prim al nr

