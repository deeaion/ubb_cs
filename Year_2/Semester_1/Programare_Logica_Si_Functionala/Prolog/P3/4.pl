
candidat(N,N).
candidat(N,R):-
    N>1,
    N1 is N-1,
    candidat(N1,R).


solutii(N,M,R):-
    candidat(N,E),
    solutii_aux(N,M,[E],R).
solutii_aux(_,M,[X,Y|R],[X,Y|R]):-
    T is X-Y,
    abs(T)>=M.
solutii_aux(N,M,[H|Col],R):-
    candidat(N,E),
    E<H,
    T is E - H,
    abs(T)>=M,
    solutii_aux(N,M,[E,H|Col],R).
