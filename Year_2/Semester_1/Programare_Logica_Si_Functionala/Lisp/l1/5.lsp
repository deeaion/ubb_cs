 
; 5.
; a) Definiti o functie care interclaseaza cu 
;pastrarea dublurilor doua liste liniare sortate.


; b) Definiti o functie care substituie un element
; E prin elementele unei liste L1 la toate 
;nivelurile unei liste date L.
(defun copy (l)
	(cond
		((null l) nil)
	(t (cons (car l) (copy (cdr l))))))
	
(defun substituie (l e a)
	(cond	
	((equal l e) (copy a))
	((listp l) 
		(list (mapcan #' (lambda (lst) (substituie lst e a)) l)))
	((atom l) (list l)))
	)
; c) Definiti o functie care determina suma a doua
; numere in reprezentare de lista si calculeaza
; numarul zecimal corespunzator sumei.
(defun invers (a col)
	(cond 
		((null a) col)
		(t (invers (cdr a) (cons (car a) col)))))
		

(defun sum_aux (a b r)
	(cond 
	 
	((and (null a) (not (equal r 0))) (list 0 ))
	((
	(t (cons (mod (+ (car a) (car b)) 10) (sum_aux (cdr a) (cdr b) (floor (/ (car a) (car b)))))))	)
(defun adauga_zero (a nr)
	(cond
		((= nr 0) a)
		(t (cons 0 a))))
(defun suma (a b)
	(cond
		((< (length a) (length b)) 
			(sum_aux (adauga_zero a (- (length b) (length a))) b 0))
		((= (lenght a) (lenght b)) (sum_aux a b))
		(t (sum_aux a (adauga_zero b (- (lenght a) (lenght b))))))
	)
	

(defun suma (a b)
	(cond
		
	
		;v 2

; d) Definiti o functie care intoarce cel mai mare
; divizor comun al numerelor dintr-o lista liniara.
