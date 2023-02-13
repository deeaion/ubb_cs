
n1=int(input("Dati n1="))
n2=int(input("Dati n2="))
n1="".join(sorted(list( dict.fromkeys(str(n1)))))#dict.fromkeys()removes the copies of numbers into a dictionary and list() transforms the dic into a list and then sort it
n2="".join(sorted(list( dict.fromkeys(str(n2)))))
n1=int(n1)
n2=int(n2)
if(n1==n2):
    print("Numerele au proprietatea p")
else:
    print("Numerele nu au proprietatea p")
            
