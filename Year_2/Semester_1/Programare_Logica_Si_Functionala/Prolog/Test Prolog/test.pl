%elimina_aparitii(El:Integer,List:List,Rez:List)
%El-> elementul pe care doresc sa il elimin din Liist
%List-> lista pe care o primesc in scopul eliminarii elementului dat El
%Rez-> lista rezultata in urma eliminarii elementului El din List
%model de flux : (i,i,o), poate fi fol si ca (i,i,i).
%daca am ajuns la sf listei input List atunci returnez R
elimina_aparitii(_,[],[]):-!.
%daca am gasit elementul El in Lista nu il voi mai adauga la Rezultat
elimina_aparitii(H,[H|T],Rez):-
    !,
    elimina_aparitii(H,T,Rez).
%daca nu am gasit elementul El in Lista il adaug la rezultat
elimina_aparitii(El,[H|T],[H|Rez]):-
    elimina_aparitii(El,T,Rez).
%main(List:List,Rez:List)
% List-> lista pe care dorim sa o transformam in multime in ordinea
% primei aparitii
% Rez-> multimea determinata din Lista data prin pastrarea doar a primei
% aparitii a elementului
%model de flux: (i,o)-> pe acesta il folosesc (i,i)
% de a lungul apelului recursiv voi lua fiecare element din lista si
% Lista noua va fi lista rezultata prin eliminarea Elementului respectiv
% din restul listei (l2...ln) pe care il primesc prin apelarea
% elimina_aparitii(L1,L2..Ln,RezCuEliminare )
main([],[]):-!.
% adaug elementul respectiv la rezultat si sterg aparitiile lui din
% restul listei si rezultatul respectuv il folosesc ca noua lista
main([H|T],[H|Rez]):-
    elimina_aparitii(H,T,RezN),
    main(RezN,Rez).
