submul([H|_],1,[H]).
submul([_|T],K,C):-
    submul(T,K,C).
submul([H|T],K,[H|C]):-
    K>1,
    K1 is K-1,
    submul(T,K1,C).

det_sub(List,Rez):-
    findall(C,submul(List,2,C),Rez).

find_pair(_,[],Rez,Rez):-!.
find_pair(El,[H|T],Rez,[[El,H]|R]):-
    find_pair(El,T,Rez,R).
find_pairs([H],[]):-!.

find_pairs([H|T],Rez):-
    find_pair(H,T,RezP,Rez),
    find_pairs(T,RezP).