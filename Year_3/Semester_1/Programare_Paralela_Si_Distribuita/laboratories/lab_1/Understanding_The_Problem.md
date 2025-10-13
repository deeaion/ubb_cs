# Matrice de convolutie - Pe threaduri

matrice F de dimensiune n x m
aplic o matrice de convolutie C de dimensiune 3x3 or 5x5 dar generalizam si este de kxk ( k=2n+1 unde n=1..)
rezultatul e o matrice de dimensiune n x m numita V
formula de calcul a elementului F[i][j] este:

Rezultatul se obtine prin calculul:
v[i,j] =  
f[i,j] _c[1,1]+
f[i-1,j]_ c[0,1]+
f[i,j-1]_ c[1,0]+
f[i-1,j-1]_ c[0,0]+
f[i+1,j]_ c[2,1]+
f[i,j+1]_ c[1,2]+
f[i+1,j+1]\* c[2,2]

Bordam matricea intiala cu elemente egale cu elementele de pe frontiera

## Enunt

Considerand ca se da o matrice F(n,m) si o matrice de convolutie C(k,k) se cere sa se calculeze
matricea V(n,m) rezultata in urma aplicarii convolutiei cu matricea de convolutie C pe matricea
F.
A) Program secvential
B) Program paralel: folositi p threaduri pentru calcul.

### Impartirea

- folosim descompunerea geometrica:
  - pe orizontala (mai multe linii alocate unui thread)
  - pe verticala (mai multe coloane alocate unui thread)

## In plus pentru puncte bonus:

    - impartire pe bloc : submatrici alocate unui thread (impartire si pe oriz si pe verticala)
    - bazata pe functie de distributie delta -> i se atribuie o submultime
    delta : NXM->P,   N={0,1,2,...n-1}, M=0,1,2...m-1}, P={0,1,2...p-1}

delta(i,j)= t, 0<=i<n, 0<=j<m
testarea se va face definind functia de distributie astfel incat sa obtinem: - distributie liniara (indici alaturati la acelasi thread) sau - distributie ciclica( cu pas/step egal cu p).
Citesc din fisier data.txt
iesire : output.txt
a) Java
b) C++ (>11)
