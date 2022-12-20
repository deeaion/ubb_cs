def nrp(n):
    s=1
    i=2
    while(i<=n/2):
        if n%i==0:
            s=s+i
        i+=1
    if(s==n):
        return True
    else:
        return False
    
n=int(input("Dati n="))

p=n-1
while (nrp(p)==False and p>=2):
    p=p-1
if(p>=2):
    print(p)
else:
    print("Nu exista")
