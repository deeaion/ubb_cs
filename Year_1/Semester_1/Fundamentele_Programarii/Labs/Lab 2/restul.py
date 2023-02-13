#FUNCTIONS
#CITIRE
def citire(l,n):
    print("Introduceti numerele de la tastatura")
    for i in range(0,n):
        t=int(input())
        l.append(t)

        
#1
def p_1(l,n):
    ok=0
    l_max=0 
    inf=0
    inft=0
    i=0
    l_maxn=0
    while(i+1<=n-1):
        if(l[i]<l[i+1]):
            if(l_maxn==0):
                l_maxn+=2
            else:
                l_maxn+=1
        else:
            if(l_max<l_maxn):
                l_max=l_maxn
                inf=inft
            l_maxn=0
            inft=i+1
        i+=1
    if(l_max<l_maxn):
                l_max=l_maxn
                inf=inft
    if(l_max<l_maxn):
                l_max=l_maxn
                inf=inft
    print(l[inf:inf+l_max])
    return l[inf:inf+l_max]
  
    
#3
        #CMMDC
def prime_intre(a,b):
    divizor=1
    if a==b:
        divizor=a
        return False
    else:
        while (b!=0):
            r=a%b
            a=b
            b=r
            divizor=a
    if(divizor==1 or divizor==-1):
        return True
    else:
        return False
def p_3(l,n):
    l_max=0 
    inf=0
    inft=0
    i=0
    l_maxn=1
    while(i+1<=n-1):
        if(prime_intre(l[i],l[i+1])==True):
            l_maxn+=1
        else:
            if(l_max<l_maxn):
                l_max=l_maxn
                inf=inft
            l_maxn=1
            inft=i+1
        i+=1
    if(l_max<l_maxn):
                l_max=l_maxn
                inf=inft
    print(l[inf:inf+l_max])

        
    
#MAIN-MENU
print("MENIU")
print("1.Citirea unei liste de numere intregi.")
print("2.p1")
print("3.p2")
print("4.p3")#GATA
print("18.Iesire din aplicatie.")

#OPERATIUNI
ok=0
n=0
while(n!=18):
    n=int(input("Introduceti numarul operatiunii dorite:"))
    if n<=0 or n>=19:
        print("Optiunea nu exista!")
    if(n==1):
        print("Creare lista:")
        l=[]
        s=int(input("Specificati lungimea listei:"))
        citire(l,s);
        print("Lista dvs:",l)
        ok=1
    if(n==2):
        if(ok==0):
            print("Nu ati introdus lista numerelor")
        else:
            t=p_1(l,s)
            print(t)
         
    if(n==3):
        if(ok==0):
            print("Nu ati introdus lista numerelor")
        else:
            p_2(l,s)
    if(n==4):
        if(ok==0):
            print("Nu ati introdus lista numerelor")
        else:
            p_3(l,s)
    if(n==18):
        print("END")
        
