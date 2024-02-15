gasit(_,[]):-
    false.
gasit(E,[H|_]):-
    H=E,!.
%acolo l am gasit
gasit(E,[_|T]):-
    gasit(E,T).
elimina_dublicate([],[]).
elimina_dublicate([H|T],[H|Rez]):-
    elimina_dublicate(T,Rez),
    \+gasit(H,Rez),!.

elimina_dublicate([_|T],Rez):-
    elimina_dublicate(T,Rez).
elimina_dublicate_main(List,Rez):-
    elimina_dublicate(List,Rez).
