; 2.
; a) Definiti o functie care selecteaza al n-lea 
; element al unei liste, sau NIL, daca nu exista.
(defun selecteaza (l n poz)
	
	(cond 
		((null l) nil)
		((equal n poz) (car l))
		(t (selecteaza (cdr l) n (+ 1 poz)))))
(print (selecteaza '(1 2 3 4 ) 2 0))
(print (selecteaza '(1 2 3 4 ) 10 0))



; b) Sa se construiasca o functie care verifica 
; daca un atom e membru al unei liste nu neaparat liniara.
(defun membru ( l e)
	(cond	
		((null l) nil)
		((equal e (car l)) t)
		((listp (car l)) (or (membru (car l) e) (membru (cdr l) e)))
		(t (membru (cdr l) e))))
(print ( membru '(1 2 3 4 5) 4))
(print ( membru '(1 2 3 4 5) 6))
(print ( membru '(1 2 3 (4)) 4))



; c) Sa se construiasca lista tuturor sublistelor
 ; unei liste. Prin sublista se intelege fie lista insasi,
 ; fie un element de pe orice nivel, care este lista.
 ; Exemplu: (1 2 (3 (4 5) (6 7)) 8 (9 10)) =>
; ( (1 2 (3 (4 5) (6 7)) 8 (9 10)) (3 (4 5) (6 7)) (4 5) (6 7) (9 10) ). 

;(print (subliste '(1 2 (3 (4 5) (6 7)) 8 (9 10))))

(defun subliste (l col)
	(cond
		((null l) col)
		((listp (car l)) 
					(subliste (cdr l)
						(append (list (car l)) (subliste (car l) col)  )
					)
		)
		(t (subliste (cdr l) col )))
)	
	
(print (subliste '(1 2 (3 (4 5) (6 7)) 8 (9 10)) () ))
;d) Sa se scrie o functie care transforma o lista liniara intr-o multime.
(defun elimina (l e)
	(cond
		((null l) NIL)
		((equal e (car l)) (elimina (cdr l) e))
		(t (cons (car l) (elimina (cdr l) e)))
		))
(defun multime (l)
	(cond 
		((null l) nil)
		(t (cons (car l) 
			(multime (elimina (cdr l) (car l)))))))
			(print (elimina '(1 2 3) 1))
(print (multime '(1 2 3 4 5 1)))
(defun multime2 (l)
	(cond 
		((null l) nil)
		((membru (cdr l) (car l)) (multime2 (cdr l)))
		(t (cons (car l) 
			(multime2 (cdr l))))))
	(print (multime2 '(1 2 3 4 5 1)))
			(print (elimina '(1 2 3) 1))