suc([9],[0],1):-!.
suc([H],[Nr],0):-
    Nr is H+1,!.
suc([H|T],[C|Res],Rest):-
    suc(T,Res,R1),
    C is (H+R1) mod 10,
    Rest is (H+R1) // 10.

addR(0,Res,Res):-!.
addR(N,Res,[N|Res]).

main(L,Res):-
    suc(L,ResP,Rest),
    addR(Rest,ResP,Res).
