adauga_par([],[]):-!.
adauga_par([H|T],[H,1|Rez]):-
    H mod 2 =:=0,!,
    adauga_par(T,Rez).


adauga_par([H|T],[H|Rez]):-
   adauga_par(T,Rez).
