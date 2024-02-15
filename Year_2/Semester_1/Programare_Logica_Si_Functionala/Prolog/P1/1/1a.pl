%cauta un element intr o lista
%gasit(E,Lista)
gasit(E,[H|_]):-
    H=:=E,!.
%acolo l am gasit
gasit(E,[_|T]):-
    gasit(E,T).
%det_diferenta(A,B,Rez).
%daca a este vid returnez lista vida
det_diferenta([],_,[]):-!.

%daca nu parcurg toate elementele lui A.
%cazul in care nu gasesc el A in B
det_diferenta([H|T],B,[H|Rez]):-
    \+ gasit(H,B),!,
    det_diferenta(T,B,Rez).

det_diferenta([_|T],B,Rez):-
    det_diferenta(T,B,Rez).
