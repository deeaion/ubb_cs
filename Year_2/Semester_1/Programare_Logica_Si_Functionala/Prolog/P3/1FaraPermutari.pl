coliniare(X, _, X, _, X, _) :- !.
coliniare(_, Y, _, Y, _, Y) :- !.
coliniare(X1, Y1, X2, Y2, X3, Y3) :-
    X1 =\= X2, X2 =\= X3, X1 =\= X3,
    Y1 =\= Y2, Y2 =\= Y3, Y1 =\= Y3,
    P1 is (Y3 - Y1) / (Y2 - Y1),
    P2 is (X3 - X1) / (X2 - X1),
    P1 =:= P2.


submultimi([P1,P2,P3|_],[P1,P2,P3]).
submultimi([_|T],R):-
    submultimi(T,R).
submultimi([[X,Y]|T],[[X,Y]|[[X1,Y1],[X2,Y2]|R]]):-
    submultimi(T,[[X1,Y1],[X2,Y2]|R]),
    coliniare(X,Y,X1,Y1,X2,Y2).
