
combinari([H|_],[H],1).

combinari([H|T],[H|[R1|R]],K):-
    K>1,
    K1 is K-1,
    combinari(T,[R1|R],K1),
    H<R1.
combinari([_|T],R,K):-
    combinari(T,R,K).
submultimi(L,R):-
    combinari(L,R,2).
