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
        i=i+2
    return True
n=int(input("Dati n="))
gasit=False
while(gasit==False):
    n=n+1
    if( prim(n)==True):
        gasit=True
print(n)
    
    
