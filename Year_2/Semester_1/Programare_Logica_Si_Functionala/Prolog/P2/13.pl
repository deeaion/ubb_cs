divizori(N,_,L,L):-
    N=<3,!.
divizori(N,D,L,L):-
    D*D>N,!.

divizori(N,D,L,[D|Rez]):-
    N mod D =:= 0,!,
    D1 is D+1,
    divizori(N,D1,L,Rez).

divizori(N,D,L,Rez):-
   D1 is D+1,
   divizori(N,D1,L,Rez).


adauga([],Rez,Rez):-!.

adauga([H|T],Rez,[H|R]):-
    adauga(T,Rez,R).

parcurge([],[]).

parcurge([H|T],[H|R]):-
    parcurge(T,RezD),
    divizori(H,2,RezD,R).

parc(List,Rez):-
    parcurge(List,Rez).
