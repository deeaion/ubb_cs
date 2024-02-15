%det_nrImp(List,Rez,NrImp).
det_nrImp([],[],0):-!.
det_nrImp([H|T],[H|Rez],NrI):-
          H mod 2=:=1,!,
          det_nrImp(T,Rez,NrIV),
          NrI is NrIV+1.
det_nrImp([_|T],Rez,NrI):-
    det_nrImp(T,Rez,NrI).

det_nrPar([],[],0).
det_nrPar([H|T],[H|Rez],NrI):-
          H mod 2=:=0,!,
          det_nrPar(T,Rez,NrIV),
          NrI is NrIV+1.
det_nrPar([_|T],Rez,NrI):-
    det_nrPar(T,Rez,NrI).
adauga_Pare([],Rez,Rez).
adauga_Pare([H|T],Rez,[H|RezF]):-
          adauga_Pare(T,Rez,RezF).
det_nr(List,RezF,NrPare,NrImp):-
    det_nrImp(List,Rez,NrImp),
    det_nrPar(List,RezP,NrPare),
    adauga_Pare(RezP,Rez,RezF).

main(List,Rez,NrPare,NrImp):-
    det_nr(List,Rez,NrPare,NrImp).
