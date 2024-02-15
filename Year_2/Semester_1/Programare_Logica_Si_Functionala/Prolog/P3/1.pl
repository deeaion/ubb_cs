
%coliniare(X1,Y1,Z1,X2,Y2,Z2).
%coliniare(X,_,X,_,X,_):-!.
%coliniare(_,Y,_,Y,_,Y):-!.
%coliniare(X1,Y1,X2,Y2,X3,Y3):-
 %   X1 =\= X2, X2 =\= X3,X1 =\= X3,
 %   Y1 =\= Y2, Y2 =\= Y3, Y1 =\= Y3,
  %  P1 is (Y3-Y1)/(Y2-Y1),
   % P2 is (X3 -X1)/(X2-X1),
   % P1 =:= P2.
%submultimi([],[]).

%submultimi([[X,Y],[X1,X2],[X3,Y3]|T],[[X,Y],[X1,X2],[X3,Y3]|R]):-
 %   coliniare(X,Y,X1,X2,X3,Y3),
  %  submultimi([[X1,X2],[X3,Y3]|T],R).
%submultimi([_|T],R):-
 %   submultimi(T,R).

coliniare(X, _, X, _, X, _) :- !.
coliniare(_, Y, _, Y, _, Y) :- !.
coliniare(X1, Y1, X2, Y2, X3, Y3) :-
    X1 =\= X2, X2 =\= X3, X1 =\= X3,
    Y1 =\= Y2, Y2 =\= Y3, Y1 =\= Y3,
    P1 is (Y3 - Y1) / (Y2 - Y1),
    P2 is (X3 - X1) / (X2 - X1),
    P1 =:= P2.



candidat([H|_],H).
candidat([_|T],R):-candidat(T,R).
submultimi(_,Col,Col,1).

submultimi(L,Rez,[[X1,Y1],[X2,Y2]|T],_) :-
    candidat(L,[X,Y]),
    not(candidat([[X1,Y1],[X2,Y2]|T],[X,Y])),
    X<X1,
    Y<Y1,
    coliniare(X, Y, X1, Y1, X2, Y2),
    submultimi(L,Rez,[[X,Y],[X1,Y1],[X2,Y2]|T],1).
printa([]):-!.
printa([H|T]):-
    write(H),
    nl,
    printa(T).


submultimi_aux(L,R):-
    candidat(L,[X1,Y1]),
    candidat(L,[X2,Y2]),
    \+ [X1,Y1]==[X2,Y2],
    Y2>Y1,
    X2>X1,
    submultimi(L,R,[[X1,Y1],[X2,Y2]],0).%0 il fol ca un indicator ca am minim 3



sub(L):-
    findall(R,submultimi_aux(L,R),T),
    printa(T).













