
candidat([H|_],H).
candidat([_|T],R):-
    candidat(T,R).

aranjamente(_,R,R,0).

aranjamente(L,R,Col,K):-
    K>0,
    candidat(L,E),
    not(candidat(Col,E)),
    K1 is K-1,
    aranjamente(L,R,[E|Col],K1).
all(L,R,K):-
    findall(RP,aranjamente(L,RP,[],K),R).

combinari(_,R,R,0).

combinari(L,R,[R1|Col],K):-
    K>0,
    candidat(L,E),
    not(candidat(Col,E)),
    K1 is K-1,
    E<R1,
    aranjamente(L,R,[E|[R1|Col]],K1).

init_comb(L,R,K):-
    candidat(L,E),
    K1 is K-1,
    combinari(L,R,[E],K1).
