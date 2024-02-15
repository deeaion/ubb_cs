elimina_cresc([],[]):-!.
elimina_cresc([L1],[L1]):-!.

elimina_cresc([L1,L2],[]):-
    L1=:=L2-1,!.
elimina_cresc([L1,L2,L3|T],Rez):-
    L1=:=L2-1,
    L2=:=L3-1,!,
    elimina_cresc([L2,L3|T],Rez).

elimina_cresc([L1,L2,L3|T],Rez):-
    L1=:=L2-1,
    L2=\=L3-1,!,
    elimina_cresc([L3|T],Rez).

elimina_cresc([L1,L2|T],[L1|Rez]):-
    elimina_cresc([L2|T],Rez).

