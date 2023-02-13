n= int(input("n="))
p=1
d=0
for i in range(2,n-1):
    if n%i==0:
        p=p*i
        d=d+1
if d==0:
    print("Numarul nu are divizori proprii")
else:
 print (p)
