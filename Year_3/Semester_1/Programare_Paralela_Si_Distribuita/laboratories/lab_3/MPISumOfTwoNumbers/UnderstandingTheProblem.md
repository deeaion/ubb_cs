# Understanding the Problem

Suma a doua numere mari .
Reprezentari numere: tablou de cifre (fara semn) , cifra cea mai nesimnifiicativa este 0
2 fisiere:
Numar1.txt (N_1 cifre)
Numar2.txt (N2 cifre)

# Varianta 0

- secventiala

# Varianta 1

```
1) id_proces_curent=1
2) procesul 0 repeta urmatoarele actiuni pana cand se citesc toate cifrele numerelor
a. citeste cate N/(p-1) cifre din cele 2 fisiere
b. le trimite procesului “id_proces_curent”
c. incrementeaza “id_proces_curent”
3) procesele fac suma cifrelor primite si calculeaza “report” (carry) corespunzator;
4) fiecare proces (cu exceptia ultimului) trimit “reportul” la procesul urmator care il foloseste pentru actualizarea rezultatului (procesul id=1 nu primeste carry - il considera egal 0)
5) rezultatul final se obtine in procesul 0. care scrie rezultatul in fisierul “Numar3.txt”
Posibilitati:
a) procesele primesc carry inainte de a primi cifrele pe care trebuie sa le adune
b) procesele primesc cifrele pe care trebuie sa le adune si apoi carry de la precedent
Alegeti pentru implementare varianta care este mai buna!
Optimizare -? Adunarea cifrelor inainte de a astepta carry. Este posibil?
```

# Varianta 2

```
1) procesul 0 citeste cele 2 numere si le stocheaza in 2 tablouri:
a. daca un numar are mai putine cifre se completeaza cu cifre nesemnificative
2) cifrele celor 2 numere se distribuire proceselor folosind MPI_Scatter (daca nu este valabila conditia p|N, unde N=max{N_1,N_2}, N_1 nr de cifre ale primului numar, N_2 nr de cifre ale celui de-al doilea, atunci se mareste N corespunzator si se completeaza cu 0-uri)
3) procesele fac suma cifrelor primite si calculeaza “report” (carry) corespunzator
4) fiecare process (cu exceptia ultimului) trimit “reportul” la procesul urmator care il foloseste pentru actualizarea rezultatului
5) rezultatul final se obtine in procesul 0 (se foloseste MPI_Gather)
6) procesul 0 scrie rezultatul in fisierul “Numar3.txt”
```

# Varianta 3

```
Se considera rezolvarea problemei prin executia urmatoarelor etape:
1) procesul 0
id_proces_curent=1
repeta urmatoarele actiuni pana cand se citesc toate cifrele numerelor
a. citeste cate N/p cifre din cele 2 fisiere
b. le trimite procesului “id_proces_curent”
c. incrementeaza “id_proces_curent”
2) un process cu id<>0 primeste setul de cifre de la procesul 0 si face adunarea intr-un vector rezultat si actualizeaza “reportul”(carry”) pe care il trimite la procesul urmator
(atentie un proces cu id (id<>1, id<>0) primeste informatie de la procesul 0 si de la procesul (id-1) dar ordinea intre cele 2 nu este sigura … se cere sa se foloseasca MPI_Irecv )
3) rezultatul final se obtine in procesul 0 prin agregarea rezultatelor tuturor celorlalte procese; agregarea se va face folosind transmitere asincrona!!!
4) procesul 0 scrie rezultatul in fisierul “Numar3.txt”
```

La varianta 3 functiile sunt asyncrone si tehnic nu stim ordinea in care se primesc datele.
Putem folosi tags care e ca un id si stie sigur unde sa se trimita data
Tag uriile sunt urmatorul fel:
0- largernumber chunk size
1 - smaller number chunk size
2- larger number
3 - smaller number digits
4 - carry

Imi trebuie MPI_Requests pentru a face MPI_Isend si MPI_Irecv
