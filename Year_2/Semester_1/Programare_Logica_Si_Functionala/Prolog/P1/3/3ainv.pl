elimina_dub(_,[],[]):-!.
elimina_dub(E,[H|T],R):-
    E=:=H,!,
    elimina_dub(E,T,R).
elimina_dub(E,[H|T],[H|R]):-
    E=\=H,
    elimina_dub(E,T,R).




multime([],[]):-!.
multime([H|T],[H|R]):-
    elimina_dub(H,T,R1),
    multime(R1,R).
