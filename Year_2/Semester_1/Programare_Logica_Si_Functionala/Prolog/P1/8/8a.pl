cauta([H|_],H):-!.

cauta([_|T],El):-
    cauta(T,El).

verifica([]):-!.
verifica([H|T]):-
    not(cauta(T,H)),
    verifica(T).

