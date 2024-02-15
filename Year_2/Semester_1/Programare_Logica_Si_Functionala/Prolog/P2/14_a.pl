%precedent(List:List,Rest:Int,List:List)
%List-> lista de prelucrat
%Rest-> avand scaderi avem situatii cand trebuie  sa retinem un rest pentru al scade din op
%Result-> lista rezultata . precedentul listei
%daca am ajuns la sf de lista ret lista vida
%model de flux: (i,o,o) , (i,i,i)
precedent([],_,[]):-!.
%daca sunt la sf listei si ultima cifra este 0
%aici setam restul la 1 si ultima cifra va fi 9
precedent([0],1,[9]):-!.
%altfel ultima cifra devine ultima cifra-1
precedent([H],0,[NewH]):-
    NewH is H-1,!.
%daca avem restul 1 si cifra curenta este 0 continuam cu
%restul 1 si la result adaug la inceput 9
precedent([0|T],1,[9|Result]):-
    precedent(T,1,Result),
    !.
%altfel noua cifra de adaugat e l1-Rest
precedent([H|T],0,[NewH|Result]):-
    precedent(T,NewR,Result),
    !,
    NewH is H-NewR.


%format_number(List:List,Result:List)
%daca am inceputul =0 -> returnez lista fara l1
%altfel returnez lista normal
%model de flux: (i,i),(i,o) (o,i)
format_number([0|Result],Result):-!.
format_number(Result,Result).

%precedent_main(List: List,ResultFinal:List)
%List-> lista de prelucrat
%ResultFinal: lista prelucrata
%functia apeleaza precedent pentru a primi Result ca lista rezultata
%prin intermediul functiei format_number am grija ca elementele din lista sa aiba sens ca numere
% de ex daca lista mea in e [1000] -> [0999] va dev -> [999]
% model de flux: (i,i),(i,o)-> fol de noi
precedent_main(List,ResultFinal):-
    precedent(List,0,Result),
    format_number(Result,ResultFinal).


%Lista principala care parcurge lista si returneaza rezultatul modificarii
%Toate sublistele vor indica acum la predecesorul lor -> [123] ->[122]
%numere nu se schimba
%main_lucruCuListe(List:Lista,Result:List)
%List-> lista primita ca parametru pentru prelucrare
%Resultatul-> lista rezultata dupa prelucrare
%model de flux(i,o)->folosit de noi ,(i,i),

%daca lista este vida returnez lista vida
main_lucruCuListe([],[]).
%daca elementul l1 este lista atunci prelucrez lista si determin precedentul
%prin intermediul functiei precedent_main care prin elementul RestPred returneaza noua lista
%adaug la inceputul rezultatului lista obtinuta
%continui prelucrarea listei initiale
main_lucruCuListe([H|T],[ResPred|Result]):-
    is_list(H),!,
    precedent_main(H,ResPred),
    main_lucruCuListe(T,Result).
%daca elementul l1 este numar doar il adaug la lista si continui prelucrare
%listei
main_lucruCuListe([H|T],[H|Result]):-
    number(H),
    main_lucruCuListe(T,Result).













