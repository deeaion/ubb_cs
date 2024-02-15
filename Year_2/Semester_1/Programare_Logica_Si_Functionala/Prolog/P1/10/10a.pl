insertF([],E,[E]):-!.

insertF([H|T],E,[H|Rez]):-
    insertF(T,E,Rez).

