#Functii
def fibonacci(n):
    if(n==0 or n==1):
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)

#user-input
n=int(input("Dati n="))
i=0
while fibonacci(i)<n:
    i=i+1
if fibonacci(i)>n:
    print("Numarul mai mare decat n= ",n," m=",fibonacci(i),"aflat pe pozitia k=",i)
if fibonacci(i)==n:
    i+=1
    print("Numarul mai mare decat n= ",n,"este m=",fibonacci(i),"aflat pe pozitia k=",i)
