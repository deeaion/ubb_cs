gasit(E,[H|_]):-
    H=E,!.
%acolo l am gasit
gasit(E,[_|T]):-
    gasit(E,T).
elimina_aparitii([],[]):-!.
elimina_aparitii([H|T],[H|Rez]):-
    elimina_aparitii(T,Rez),
    not(gasit(H,Rez)),!.
elimina_aparitii([_|T],Rez):-
    elimina_aparitii(T,Rez).

multime([],[]):-!.
multime(List,RezP):-
     elimina_aparitii(List,RezP).


