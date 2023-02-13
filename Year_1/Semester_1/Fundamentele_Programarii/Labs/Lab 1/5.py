#FUNCTIONSSS

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

#user-input
n=int(input("Dati n="))
p=n+1
if(p%2==0):
    p+=1
q=p+2
while(prim(p)==False or prim(q)==False):
    p+=2
    q=p+2
print("Numerele prime gemene imediat superioare nr n=",n,"sunt:",p,"si",q)
