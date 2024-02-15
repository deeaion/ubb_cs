
cauta([H|_],H):-!.
cauta([_|T],El):-
    cauta(T,El).

reuniune([],[],[]).

reuniune([],L2,L2).

reuniune([H|T],L2,[H|Rez]):-
    not(cauta(L2,H)),
    !,
    reuniune(T,L2,Rez).



