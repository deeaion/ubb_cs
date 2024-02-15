adauga([],Rez,Rez):-!.
adauga([H|T],Rez,[H|R]):-
    adauga(T,Rez,R).
inlocuieste([],_,_,[]):-!.

inlocuieste([H|T],H,L,Rez):-
    adauga(L,Rez,RezAd),!,
    inlocuieste(T,H,L,RezAd).

inlocuieste([H|T],El,L,[H|Rez]):-
    inlocuieste(T,El,L,Rez).



