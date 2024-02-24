append([],El,[El]):-!.
append([H|T],El,[H|Rez]):-
    append(T,El,Rez).


gcd(A,0,A):-!.

gcd(A,B,R):-
    NewB is A mod B,
    gcd(B,NewB,R).

gcd_l([],R,R):-!.
gcd_l([H|T],R,Res):-
    gcd(R,H,G),
    gcd_l(T,G,Res).

gcdM([H|T],Res):-
    gcd_l([H|T],1,Res).
