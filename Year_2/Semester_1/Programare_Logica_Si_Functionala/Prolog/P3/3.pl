
subsir([X,Y|_],[X,Y]):-
    X=:=Y-1.
subsir([X|T],[X|[R1|R]]):-
    subsir(T,[R1|R]),
    X=:=R1-1.
subsir([_|T],R):-
    subsir(T,R).


