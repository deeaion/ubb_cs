%Sa se scrie un predicat care determina cel mai mic multiplu comun al
%elementelor unei liste formate din numere intregi.
%DESCRIPTION OF PROBLEM:
%Solutie:
    %Functia wrapper va chema find_lcm(List,Result)<- preferinta
    %Pentru fiecare element calculez lcm cu rezultatul precedent ( pentru lista vida Rezultatul este 1)
    %La randul ei functia lcm se calculeaza cu ajutorul functii gcd

%gcd(A:Integer,B:Integer,R:Result)
    %A-> primul numar de testat gcd
    %B -> al doilea  numar de testat gcd
    %R -> rezultatul gcd. R=A
    %modelul de flux: (i,i,o),(i,i,i),(merge somehow si (i.o.i) but result makes no sense)
%daca B=0 -> returnez A si acel e rezultatul
gcd(A,0,A):-!.
%daca B!=0 atunci -> A=B, B=A mod B si R.
gcd(A,B,R):-
    NewB is A mod B,
    gcd(B,NewB,R).
%lcm(A:Integer,B:Integer,R:Result)
    %A-> primul numar de testat lcm
    %B -> al doilea  numar de testat lcm
    %R -> rezultatul lcm. R=A
    %modelul de flux: (i,i,o),(i,i,i)
%lcm(A,B,R) - daca B!=0 -> R=(A*B)/gcd(A,B)
lcm(A,B,R):-
    gcd(A,B,GCD),
    R is (A*B)/GCD.
lcm(0,_,1).
%find_lcm(List:List,Result: Integer)
    %List- lista pentru care determina cmmmc

create(_, _, [], _, []):-!.
    %Result- Resultatul la cmmmc pe lista
    %modelul de flux: (i,i), (i,o)
%List=[] . Daca lista este vida rezultatul e 1.
find_lcm([],1):-!.
%Branch: Result1= lcm(l1*Result); unde Result este lcm precedent , daca lista nu e vida
find_lcm([H|T],Result):-
    find_lcm(T,Result1),
    lcm(H,Result1,Result).
%wrapper(List:List,Result: Integer) - wrapper pentru functie ca asa vreau
%   List-> lista cu elemente
%   Result-> rezultatul cmmmc
wrapper(List,Result):-
    find_lcm(List,Result).
