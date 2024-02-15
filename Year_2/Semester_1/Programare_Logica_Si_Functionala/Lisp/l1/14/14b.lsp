 ;functie care verifica daca lista l are minim 3 elemente
;daca nu e returnez nill
;altfel true
;model de flux:(i)
(defun are_minim_3_el (l)

	(if (or (null l) 
			(null (cdr l))
			(null (cddr l))
		)
	nil
	T))

;verific daca lista ramasa din vale este crescatoare
;l-> lista data
;returnez True doar daca mai am un element in lista si de alungul parcurgerii
;nu am gasit elemente de tipul l1>l2
;model de flux:(i)
(defun cresc(l)
	(cond 
		( (null (cdr l)) T)
		((null l) nil)
		((< (car l) (cadr l)) (cresc (cdr l)))
		(T nil)
	)
)

;functia in care verific partea descrescatoare a valii
;l-> lista data
;testeaza daca lista data e desc si daca gaseste un element de tipul
;l1<l2 -> apeleaza cresc si functia returneaza rezultatul apelului
;daca cumva am ajuns la ultimul element sau intalnesc elemente de tipul
;l1=l2 atunci nu ma aflu intr o variabila convenabila si returnez nil
;model de flux:(i)
(defun desc(l)
	(cond 
		((null (cdr l)) nil)
		((> (car l) (cadr l)) (desc (cdr l)))
		((< (car l) (cadr l)) (cresc l))
		(T nil)
	)
)

	
;functie principala vale
;testeaza daca o lista data are forma unei vale
;este vale daca are minim 3 elemente si se gaseste o lista care descreste si dupa creste la un moment dat
;model de flux:(i)
( defun vale (l) 
	(if ( and (are_minim_3_el l)
			  (> (car l) (cadr l))) ;doar atunci testez ca e desc si dupa cresc
	(desc (cdr l)) ; 
	nil)); altfel returnez nil
;testez	
(print (vale '(2 1)))
(print (vale '(3 2 1)))
(print (vale '(2 1 3)))
(print (vale '(9 7 6 0 1 2)))
(print (vale '(10 8 6 17 19 20)))