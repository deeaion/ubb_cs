candidat([H|_],H).
candidat([_|T],E):-
    candidat(T,E).

len([],0):-!.
len([_|T],N):-
    len(T,NNou),
    N is NNou+1.


generare([],_,0,_,[]).
generare(List,Col,S,N,Rez):-
    candidat(List,Cand),
    not(candidat(Col,Cand)),
    NewSum is S+Cand,
    generare(List,[Cand|Col],NewSum,N,Rez).

generare(List,Col,Suma,N,Col):-
    Suma mod N =:=0.


generare_main(List,Rez):-
    len(List,N),
    generare(List,[],0,N,Rez).
generare_M(List,Rez):-
    findall(AUX,generare_main(List,AUX),Rez),
    printare(Rez).

printare([H|T]):-
    write(H).