sublist(N,N,[H|_],[H],_):-!.


sublist(M,N,[H|T],[H|Rez],PozH):-
   PozH=:=M,!,
   M1 is M+1,
   Poz is M+1,
   sublist(M1,N,T,Rez,Poz).

sublist(M,N,[_|T],Rez,Poz):-
    M =\= Poz,!,
    Poz1 is Poz+1,
    sublist(M,N,T,Rez,Poz1).

sub_m(M,N,List,Rez):-
    sublist(M,N,List,Rez,1).