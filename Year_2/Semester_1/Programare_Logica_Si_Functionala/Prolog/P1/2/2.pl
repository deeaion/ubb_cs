%gcd(A,B,R).
gcd(A,0,A):-!.
gcd(A,B,R):-
    C is A mod B,
    gcd(B,C,R).
det_lcm([],1):-!.
det_lcm([H|T],Rez):-
    det_lcm(T,R),
    gcd(H,R,G),
    Rez is (H*R)//G.

