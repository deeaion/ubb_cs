secventa([],[],[]):-!.
secventa([H],[H],[H]):-!.
secventa([L1,L2],[L1,L2],[]):-
    L1=<L2,!.
secventa([L1,L2|T],[L1],[L2|T]):-
    L1>=L2,!.

secventa([L1,L2,L3|T],[L1|R],Rest):-
    L1<L2,
    L2<L3,!,
    secventa([L2,L3|T],R,Rest).
secventa([L1,L2,L3|T],[L1,L2],[L3|T]):-
    L1<L2,
    L2>=L3,!.
determin([],[]):-!.
determin(List,[S|Rez]):-
    secventa(List,S,Rest),
    determin(Rest,Rez).
len([],0):-!.


len([H|T],Nr):-
    len(T,Nr1),
    Nr is Nr1+1.


max([],M,M,L,L):-!.

max([H|T],M,Rez,L,RL):-
    len(H,LH),
    LH>L,!,
    max(T,H,Rez,LH,RL).

max([_|T],M,Rez,L,RL):-
    max(T,M,Rez,L,RL).
det_max([H|T],Rez):-
    determin([H|T],Liste),
    max(Liste,[],Rez,0,_).


