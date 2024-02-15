gasit([],_):-false.
gasit([H|_],E):-
    H=E,!.
gasit([_|T],El):-
    gasit(T,El).


elimina_dublicate([],_,[]):-!.
elimina_dublicate([H|T],H,R):-!,
    elimina_dublicate(T,H,R).
elimina_dublicate([H|T],El,[H|R]):-
    elimina_dublicate(T,El,R).
elimina([],[]):-!.
elimina([H|T],[H|R]):-
    elimina_dublicate(T,H,Rez),
    elimina(Rez,R).

elimina_inv([],[]).
elimina_inv([H|T],[H|R]):-
    elimina_inv(T,R),
    \+gasit(H,R),!.

elimina_inv([_|T],R):-
    elimina_inv(T,R).

elimina_main(List,Rez):-
    elimina_inv(List,Rez).


