elimina_aparitii([],_,[],0):-!.

elimina_aparitii([El|T],El,Rez,Nr):-
    elimina_aparitii(T,El,Rez,Nr1),!,
    Nr is Nr1+1.

elimina_aparitii([H|T],El,[H|Rez],Nr):-
    elimina_aparitii(T,El,Rez,Nr).


%elimina_dub(List,Rez)
elimina_dub([],[]).

elimina_dub([H|T],[H|Rez]):-
    elimina_aparitii(T,H,_,Nr),
    Nr=:=0,!,
    elimina_dub(T,Rez).

elimina_dub([H|T],Rez):-
    elimina_aparitii(T,H,RezP,_),
    elimina_dub(RezP,Rez).
