generare(N,N,[N]):-!.

generare(M,N,[M|Rez]):-
    M1 is M+1,
    generare(M1,N,Rez).



generare_lista(M,N,Rez):-
    generare(M,N,Rez).
