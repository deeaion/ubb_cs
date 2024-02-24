
det([],[E],PC,PC,E):-!.
det([],[],_,_,_):-!.
%det(list,rez,Pc,PD,E) <- PD= 2*PC+1.
det(List,[E|Rez],PC,PC,E):-
    !,
    PDN is PC*2+1,
    det(List,Rez,PC,PDN,E).

det([H|T],[H|Rez],PC,PD,E):-
    PCN is PC+1,
    det(T,Rez,PCN,PD,E).

main(List,E,Rez):-
    det(List,Rez,0,1,E).
