%elimina_aparitii(list,el,rez,nrAparitii)
elimina_aparitii([],_,[],0):-!.

elimina_aparitii([El|T],El,Rez,Nr):-
    elimina_aparitii(T,El,Rez,Nr1),!,
    Nr is Nr1+1.

elimina_aparitii([H|T],El,[H|Rez],Nr):-
    elimina_aparitii(T,El,Rez,Nr).


%det_perechi(List,Rez)
det_perechi([],[]).

det_perechi([H|T],[RezA|RezF]):-
    elimina_aparitii([H|T],H,RezP,NrAparitii),
    RezA =[H,NrAparitii],
    det_perechi(RezP,RezF).



main(List,Rez):-
    det_perechi(List,Rez).
