#FUNCTIONS
#CITIRE
def citire(l,n):
    print("Introduceti numerele de la tastatura")
    for i in range(0,n):
        t=int(input())
        l.append(t)

        
#8
def interval_0_10(l,n):
    l_max=0 
    inf=0
    inft=0
    i=0
    l_maxn=0
    while(i<=n-1):
        if(l[i]>=0 and l[i]<=10):
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
    if(l_max!=0):
        return l[inf:inf+l_max]
    else:
        print("Nu exista astfel de secventa")
    
###12
    
def doua_el_cons_semn_cont(l,n):
    l_max=0 
    inf=0
    inft=0
    i=0
    l_maxn=0
    while(i+1<=n-1):
        if(l[i]>=0 and l[i+1]<0) or (l[i]<0 and l[i+1]>0):
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
    if(l_max!=0):
        return l[inf:inf+l_max]
    else:
        print("Nu exista astfel de secventa")
#5
def p_5(l,n):
    l_max=0 
    inf=0
    inft=0
    i=0
    l_maxn=1
    while(i+1<=n-1):
        if(l[i]==l[i+1]):
                l_maxn+=1
        else:
            if(l_max<l_maxn):
                l_max=l_maxn
                inf=inft
            l_maxn=1
            inft=i+1
        i+=1
    if(l_max!=1):
        return l[inf:inf+l_max]
    else:
        print("Nu exista astfel de secventa")

        
#TEST FUNCTION
def test_interval_0_10():
    input_array=[3,-5,6,-123,4,3,10,4,9]
    result=interval_0_10(input_array,9)
    assert result==[4,3,10,4,9]
    
    

            
#MAIN-MENU
print("MENIU")
print("1.Citirea unei liste de numere intregi.")
print("2.Verifica care e secventa(prima) de lungime maxima in care toate elementele sunt cuprinse in intervalul [0,10] dat.")#12
print("3.Verifica care e secventa(prima) de lungime maxima in care oricare doua elemente consecutive sunt de semne contrare.")#8
print("4.Iesire din aplicatie.")
print("5.Verificare care e secventa (prima) de lungime maxima in care oricare doua elemente consecutive sunt egale") #5
print("6.Test 2")


#OPERATIUNI
ok=0
n=0
while(n!=4):
    n=int(input("Introduceti numarul operatiunii dorite:"))
    if n<=0 or n>=7:
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
            t=interval_0_10(l,s)
            if(t!=None):
                print(t)
         
    if(n==3):
        if(ok==0):
            print("Nu ati introdus lista numerelor")
        else:
            t=doua_el_cons_semn_cont(l,s)
            if(t!=None):
                print(t)
    if(n==4):
        print("END")
    if(n==5):
        if(ok==0):
            print("Nu ati introdus lista numerelor")
        else:
            t=p_5(l,s)
            if(t!=None):
                print(t)
    if(n==6):
        if(ok==0):
            print("Nu ati introdus lista numerelor")
        else:
            test_interval_0_10()
