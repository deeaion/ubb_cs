len([],0):-!.
len([_|T],Nr):-
    len(T,Nr1),
    Nr is Nr1+1.


suma([],[],[],0):-!.
suma([H1|T1],[H2|T2],[C|Rez],R):-
    suma(T1,T2,Rez,R1),
    C is (H1+H2+R1) mod 10,
    R is (H1+H2+R1) // 10.


/*I MAKE SURE THAT BOTH NUMBERS ARE EQUAL IN SIZE*/
addZero(_,0,Rez,Rez):-!.
addZero(L,Nr,Rez,Col):-
    Nr1 is Nr-1,
    addZero(L,Nr1,Rez,[0|Col]).

suma_aux(L1,L2,N1,N2,Rez,R):-
    N1=:=N2,!,
    suma(L1,L2,Rez,R).
suma_aux(L1,L2,N1,N2,Rez,R):-
    N1>N2,!,
    Nr is N1-N2,
    addZero(L2,Nr,RL2,L2),
    suma(L1,RL2,Rez,R).

suma_aux(L1,L2,N1,N2,Rez,R):-
    Nr is N2-N1,
    addZero(L1,Nr,RL1,L2),
    suma(RL1,L2,Rez,R).
add_Incep(Rez,R,[R|Rez]):-!.
suma_aux2(L1,L2,N1,N2,RezF):-
    suma_aux(L1,L2,N1,N2,Rez,R),
    sumaFinal(Rez,R,RezF).
sumaFinal(Rez,R,RezF):-
   R =\=0,!,
   add_Incep(Rez,R,RezF).
sumaFinal(Rez,_,Rez):-!.
suma_main(L1,L2,Rez):-
    len(L1,N1),
    len(L2,N2),
    suma_aux2(L1,L2,N1,N2,Rez).
