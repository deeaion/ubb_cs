%elimina_el(List,El,PozC).
elimina_el([],[]):-!.
elimina_el([_],[]):-!.
elimina_el([H|T],[H|Result]):-
    elimina_el(T,Result).

main(List,Rez):-
    elimina_el(List,Rez).

