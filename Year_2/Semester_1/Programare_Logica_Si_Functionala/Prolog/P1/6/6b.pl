det_max([],Max,Max):-!.


det_max([H|T],Max,Rez):-
    H>Max,!,
    det_max(T,H,Rez).

det_max([_|T],Max,Rez):-
    det_max(T,Max,Rez).
det(List,Rez):-
    det_max(List,-12313,Rez).
