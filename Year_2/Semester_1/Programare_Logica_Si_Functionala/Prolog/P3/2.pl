%Fiind dat un numar n pozitiv, se cere sa se determine toate
%descompunerile sale ca suma de numere prime distincte.


is_prim(_,2):-!.
is_prim(D,N):-
    D*D>=N,!.
is_prim(D,N):-
    N>2,
    D*D<N,
    not(N mod D =:= 0),
    D1 is D+2,
    is_prim(D1,N).

lista_primi(I,N,[2]):-
    I>N,!.
lista_primi(I,N,[I|R]):-
    is_prim(2,I),!,
    I1 is I+2,
    lista_primi(I1,N,R).
candidat([H|_],H).
candidat([_|T],R):-candidat(T,R).
solutie_aux(_,N,Col,N,Col):-!.
solutie_aux(L,S,[H|Col],N,Rez):-
    candidat(L,E),
    E<H,
    S1 is S+E,
    S1=<N,
    solutie_aux(L,S1,[E|[H|Col]],N,Rez).
solutie(N,Rez):-
    lista_primi(3,N,L),
    candidat(L,E),
    E<N,
    solutie_aux(L,E,[E],N,Rez).
all(N,Rez):-
    findall(T,solutie(N,T),Rez).


