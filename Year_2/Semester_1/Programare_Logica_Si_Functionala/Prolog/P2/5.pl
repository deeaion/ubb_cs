maxim([],R,R):-!.

maxim([H|T],Max,Rez):-
    H>Max,!,
    maxim(T,H,Rez).
maxim([_|T],Max,Rez):-
    maxim(T,Max,Rez).


%pozi(List,El,PozC,Rez).

pozi([],_,_,[]):-!.
pozi([H|T],H,PozC,[PozC|Rez]):-!,
    PozC1 is PozC+1,
    pozi(T,H,PozC1,Rez).
pozi([_|T],El,PozC,Rez):-
    PozC1 is PozC+1,
    pozi(T,El,PozC1,Rez).

poz_main(List,Rez):-
    maxim(List,-12345,Max),
    pozi(List,Max,1,Rez).

