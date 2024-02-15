%elimina_aparitii(List,El,Rez).


elimina_aparitii([],_,[]):-!.

elimina_aparitii([El|T],El,Rez):-
    elimina_aparitii(T,El,Rez),!.

elimina_aparitii([H|T],El,[H|Rez]):-
    elimina_aparitii(T,El,Rez).
