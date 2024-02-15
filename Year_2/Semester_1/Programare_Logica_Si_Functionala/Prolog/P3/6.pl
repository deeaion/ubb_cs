
candidat([H|_],H).
candidat([_|T],R):-
    candidat(T,R).

opened('(').
closed(')').


%paranteze(L,NrI,NrD,R).
paranteze(_,N,N,R,R,N):-!.

paranteze(L,NrI,NrP,Col,R,N):-
    candidat(L,E),
    closed(E),
    NrINou is NrI+1,
    NrINou =\= N+1,
    paranteze(L,NrINou,NrP,[E|Col],R,N).
paranteze(L,NrI,NrP,Col,R,N):-
    candidat(L,E),
    opened(E),
    NrPNou is NrP+1,
    NrPNou=<NrI,
    NrPNou=\=N+1,
    paranteze(L,NrI,NrPNou,[E|Col],R,N).
rez(N,R):-
    Nr is N/2,
   paranteze(['(',')'],1,0,[')'],R,Nr).
