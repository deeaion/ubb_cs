

%merge_sort(List,Rez).

%trivial
merge_sort([],[]):-!.
merge_sort([H],[H]):-!.

merge_sort(List,S):-
    divide(List,L1,L2),
    merge_sort(L1,S1),
    merge_sort(L2,S2),
    merge(S1,S2,S).


%divide
%trivial

divide([],[],[]):-!.
divide([E],[E],[]):-!.

divide([A,B|Rest],[A|L1],[B|L2]):-
    divide(Rest,L1,L2).


%merge
%trivial

merge(A,[],A):-!.
merge([],B,B):-!.

%interclasare propriu zisa
merge([A1|AT],[B1|BT],[A1|Rez]):-
    A1=<B1,!,
    merge(AT,[B1|BT],Rez).
merge(A,[B1|BT],[B1|Rez]):-
    merge(A,BT,Rez).
