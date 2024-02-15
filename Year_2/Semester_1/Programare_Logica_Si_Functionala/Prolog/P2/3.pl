divide([],[],[]):-!.
divide([A],[],[A]):-!.

divide([A1|A],[B1|B],[A1,B1|T]):-
    divide(A,B,T).

merge
merge_sort([],[]):-!.
merge_sort([A],[A]):-!.
merge_sort(List,Rez):-
    divide(L1,L2,List),
    merge_sort(L1,S1),
    merge_sort(L2,S2),
    merge(S1,S2,Rez).
