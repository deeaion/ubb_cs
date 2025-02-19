%candidat(List:List,E:Integer)
%Determina un element din lista probabil candidat pentru a
%det o submultime noua
%List-> lista de unde preluam candidat
%E-> candidatul ales
%Model de flux (i,o) <- nedeterminist, (i,i)<- determinist (~cauta)
candidat([H|_],H).
candidat([_|T],E):-
    candidat(T,E).
%len(List:List,N:Integer)
%List-> lista pentru care dorim lungimea
%N->> lungimea listei List
%model de flux-> (i,o),(i,i)
%Calculeaza lungimea unei liste
%model de flux (i,o), (i,i)<- ambele deterministe
len([],0):-!.
len([_|T],N):-
    len(T,NNou),
    N is NNou+1.
%suma(Lista:List,R:Integer)
%Lista-> lista careia ii dorim suma elemntelor
%R-> suma listei date Lista
%Calculeaza suma unei liste
%modelul de flux: (i,o), (i,i) <- ambele deterministe
suma([],0).
suma([H|T],R):- suma(T,R1), R is R1+H.
%submultime(List:List,S:List)
%Determina toate submultimiile multiimi List.
%Nu cred ca as putea altfel pt ca imi trebuiesc toate toate
%List-> lista careia ii dorim submultimiile
%Sub-> O submultimie a listei ( se det nedeterminist)
%model de flux: (i,o) <- fol nedeterminist, (i,i)<- fol det
submul([],[]).
submul([H|L],[H|T]):-
    submul(L,T).

submul([_|L],S):-
    submul(L,S).

%generare_main(List:List,Rez:List)
%Ajuta in generarea unei submultimi cu Suma multiplu de N
%N este numarul de elemente din lista
%List-> lista pentru care dorim o submultime
%Rez-> o submultime a Listei determinata nedeterminist
%Model de Flux-> (i,o) <- nedeterminist, (i,i)<- det
generare_main(List,Rez):-
    submul(List,Rez),
    len(List,N),
    suma(Rez,S),
    S mod N =:=0.
%generare_main(List:List,Rez:List)
%Ajuta in gnerarea tuturor submultimiilor cu Suma multiplu de N
%unde n este lungimea listei
%List-> lista pentru care dorim toate submultimiile
%Rez-> toate submultiimiile a caror suma respecta restricita
%Model de Flux-> (i,o) ,(i,i)
generare_M(List,Rez):-
    findall(AUX,generare_main(List,AUX),Rez),
    printare(Rez).
%functie pe care o fol la printare
%model de flux: i
printare([]):-!.
printare([H|T]):-
    write(H),
    printare(T).





