divizibil(N,D):-
    D*D<N,!,
    D1 is D+2,
    divizibil(N,D1).


divizibil(N,D):-
    D*D<N,
    N mod D =:=0,!.



prim_m(2):-!.
prim_m(N):-
    N>=2,
    N mod 2 =\=0,
    not(divizibil(N,3)).
dublic_prim([],[]):-!.
dublic_prim([H|T],[H,H|Rez]):-
    prim_m(H),!,
    dublic_prim(T,Rez).

dublic_prim([H|T],[H|Rez]):-
    dublic_prim(T,Rez).
