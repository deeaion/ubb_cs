
%b. Sa se scrie un predicat care adauga dupa 1-ul, al 2-lea, al 4-lea, al

%8-lea ...element al unei liste o valoare v data.
%Solutie:
%   insertValue este o functie wrapper . Incep de la 0 si cunosc ca dupa poz 1 trebuie sa adaug el. Dar lista
%   incepe de la 0 deci voi adauga atunci cand pozitia si Vpoz (poz) valida sunt egale adaug V unde V este elementul


%   create(I:Integer,VPos:Integer,List:List,V:Integer,Result:List)
    %I-> pozitia in lista ( o memorez sa stiu unde sunt)
    %VPos-> urmatoarea pozitie unde trebuie sa adaug elementul
    %V-> elementul de adaugat in lista
    %Result-> lista rezultat
    %model de flux: (i,i,i,i,o),(i,i,i,o,i)
%Cazul I : Lista a ajuns sa fie vida dar positia unde ne aflam este una valida
        %Adaug ultimul element el fiind chiar V elementul de adaugat
create(VPos, VPos, [], V, [V]) :-!.
%Cazul II:Daca Lista a ajuns sa fie vida si pozitia nu corespunde cu o pozitie valida atunci returnez
%lista vida
create(_, _, [], _, []):-!.

%Cazul III: Sunt pe o pozitie valida si lista nu este vida
            %Atunci -> urmatoarea pozitie va fi PozV*2. Pentru ca noi punem pe poz ale lui 2
            %Apelez recursiv folosind acceasi lista ( nu am fol niciun element din ea) si cu noua pozitie
            %Adaug elementul la inceputul listei construite
create(I, VPos, List, V, [V|Result]) :-
    I =:= VPos,
    NewVPos is VPos * 2,
    create(I, NewVPos, List, V, Result).
%Cazul IV: Daca nu sunt pe o pozitie valida si lista nu este vida
        %Atunci trebuie sa pun in rezultat primul element din lista primita initial
        %Noua noastra pozitie va fi o incrementare a cea anterioara
        %Fol si apelez recursiv functia trimitand in loc de lista doar Tail-ul ei
        %Adaug l1 (H) la inceputul listei construite
create(I, VPos, [H|T], V, [H|Result]) :-
    I =\= VPos,
    NewI is I + 1,
    create(NewI, VPos, T, V, Result).
%daca lista este vida returnez o lista vida
insertValue([], _, []).
%   insertValue(List:List,V:Integer,Result:List)
    %List-> lista de Values
    %V-> Valoarea elementului de adaugat in lista
    %Result-> Noul Vector construit ca rezultat
    %model de flux: (i,i,i),(i,i,o),(i,o,i)
%daca lista nu este vida pot apela create
insertValue(List, V, Result) :-
    create(0, 1, List, V, Result).












