;caut minimul dintre atomii numerici din lista neliniara pe toate nivelele
;minim(l:lista m:minim)
;daca este atom numeric inseamna ca pot compara normal altfel trrebuie sa caut si pe atomuk respectiv
;model de flux: (i,i)


(defun minim(l m)
	(cond 
		((null l) m)
		((and(numberp (car l)) (>= (car l) m)) (minim (cdr l) m))
		((and( numberp (car l)) (< (car l) m)) (minim (cdr l) (car l)))
		;acum clauzele cand nu e atom numeric
		;car 
		((listp (car l)) (minim (cdr l) (minim (car l) m)))
		(T (minim (cdr l) m))
))		
;functie prinicpala
;main(l: List)
;model de flux(i,i)
(defun main(l)
	(minim l 12345))
	
	
(print (main '(1 2 3)))
(print (main '(a 2 3)))
(print (main '(a b (1 3) 2 3)))
(print (main '(23 -34 23)))
(print (main '(23 1 (-23 2) 2 3 4 (-2 (-100 2)))))