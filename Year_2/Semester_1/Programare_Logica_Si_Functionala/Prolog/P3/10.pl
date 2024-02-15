
candidat([H|_],H).
candidat([_|T],R):-candidat(T,R).

lungime([],0):-!.
lungime([_|T],Nr):-
    lungime(T,Nr1),
    Nr is Nr1+1.

subsiruri(_,S,N,R,R,_):-
    S mod N =:=0,
    \+ R ==[].
subsiruri(L,S,N,R,[R1|Col],Lu):-
    candidat(L,E),
    not(candidat([R1|Col],E)),
    SNou is S+E,
    E<R1,
    L1 is Lu+1,
    L1<N,
    subsiruri(L,SNou,N,R,[E,R1|Col],L1).
sub_aux(L,R,N):-
    candidat(L,E),
    subsiruri(L,E,N,R,[E],1).
all(L,R):-
    lungime(L,Lung),
    findall(RP,sub_aux(L,RP,Lung),R).
