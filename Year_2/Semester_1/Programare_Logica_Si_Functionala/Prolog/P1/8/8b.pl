elimina([],_,[],_).

elimina([H|T],El,Rez,Nr):-
    H=:=El,
    Nr<3,!,
    Nr1 is Nr+1,
    elimina(T,H,Rez,Nr1).
elimina([H|T],El,[H|Rez],Nr):-
    H=:=El,
    Nr>3,!,
    Nr1 is Nr+1,
    elimina(T,H,Rez,Nr1).

elimina([H|T],El,[H|Rez],Nr):-
    elimina(T,El,Rez,Nr).


elimina_main(List,El,Rez):-
    elimina(List,El,Rez,0).