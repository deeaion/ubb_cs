produs([],[],_,0):-!.

produs([H|T],[C|Rez],Nr,Rest):-
    produs(T,Rez,Nr,R),
    C is (H*Nr+R) mod 10,
    Rest is (H*Nr+R) // 10.

adauga_R(Rez,R,[R|Rez]):-
    R=\=0,!.

adauga_R(Rez,_,Rez).

produs_main(List,Nr,Rez):-
    produs(List,RezP,Nr,Rest),
    adauga_R(RezP,Rest,Rez).
