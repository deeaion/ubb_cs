 %vale(l1..ln)

%Valea incepe desc \/ -> desc(l1..ln,Rez) unde rez e lista ramasa

desc([L1,L2|T]):-
    L1>L2,
    !,
    desc([L2|T]).

desc(List):-
    cresc(List).
cresc([_]):-!.
cresc([L1,L2|T]):-
    L1<L2,
    cresc([L2|T]).





vale([L1,L2,L3|T]):-
    L1>L2,
    desc([L2,L3|T]).
