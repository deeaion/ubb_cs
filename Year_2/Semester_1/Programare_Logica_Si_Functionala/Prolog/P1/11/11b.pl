suma([],Suma,_,Suma):-!.

suma([H|T],Suma,Poz,Rez):-
    Poz mod 2 =:= 0,!,
    Suma1 is Suma-H,
    Poz1 is Poz+1,
    suma(T,Suma1,Poz1,Rez).

suma([H|T],Suma,Poz,Rez):-
    Suma1 is Suma+H,
    Poz1 is Poz+1,
    suma(T,Suma1,Poz1,Rez).


suma_alt(List,Rez):-
    suma(List,0,1,Rez).
