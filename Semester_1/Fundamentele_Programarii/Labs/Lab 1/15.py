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
def gasit(p):
    p=p-1
    while(p>=2):
        if(prim(p)==True):
            return p
        p-=1
    return 0
    
n=int(input("Dati n="))
p=gasit(n)
if(p>=2):
    print(p)
else:
    print ("Nu exista")
