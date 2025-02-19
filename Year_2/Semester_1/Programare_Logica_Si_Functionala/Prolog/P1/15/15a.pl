pare([_,_]):-!.

pare([_,_|T]):-
    pare(T).



%minim(List,El,Rez).

minim([],El,El):-!.

minim([H|T],Min,Rez):-
    Min>H,!,
    minim(T,H,Rez).

minim([_|T],Min,Rez):-
    minim(T,Min,Rez).

elimina([],[],_,_):-!.
%elimina(Lista,Rez,El,Eliminat).

elimina([H|T],Rez,H,0):-
    G1 is 1,!,
    elimina([H|T],[H|Rez],H,G1).
elimina([H|T],[H|Rez],El,G):-
    H=\=El,!,
    elimina(T,Rez,El,G).
elimina([H|T],[H|Rez],H,1):-!,
    elimina(T,Rez,H,1).
elimina_m(List,Rez):-
    minim(List,12345,M),
    elimina(List,Rez,M,0).
