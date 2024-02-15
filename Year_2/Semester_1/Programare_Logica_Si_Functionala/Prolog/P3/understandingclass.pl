sP([],[]).
sP([_|T],S):-sP(T,S).
sP([H|T],[H|S]):- H mod 2 =:=0,
!,
sP(T,S).
sP([H|T],[H|S]):-sI(T,S).
% sI(L:list of numbers, L: list of number)
% (i,o) – nondeterm
sI([H],[H]):-H mod 2 =\=0, !.
sI([_|T],S):-sI(T,S).
sI([H|T],[H|S]):-H mod 2 =:=0,
!,
sI(T,S).
sI([H|T],[H|S]):-sP(T,S).
% det(L:list of elements, E:element, LRez: list of numbers)
%(i, i, o) - determinist
det(L, E, LRez):-
    det_aux(L, E, LRez, 1).
% det_aux( L:list of elements, E:element, LRez: list of numbers, P:intreg)
% (i, i, o, i) - determinist
det_aux([], _, [], _).
det_aux([E|T], E, [P|LRez], P) :-
!,
P1 is P+1,
det_aux(T, E, LRez, P1).
det_aux([_|T], E, LRez, P) :-
P1 is P+1,
det_aux(T, E, LRez, P1).
% g(L:list, E: element, LRez: list)
% (i, i, o) – nedeterminist
g([H|_], E, [E,H]).
g([_|T], E, P):-
g(T, E, P).
% f(L:list, LRez: list)
% (i, o) – nedeterminist
f([H|T],P):-
g(T, H, P).
f([_|T], P):-
f(T, P).
