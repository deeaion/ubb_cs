 
; 4.
; a) Definiti o functie care intoarce suma a doi vectori.
;too easy
; b) Definiti o functie care obtine dintr-o lista data lista 
;tuturor atomilor care apar, pe orice nivel, dar in aceeasi 
;ordine. De exemplu:
; (((A B) C) (D E)) --> (A B C D E)
(defun atomi(l) 
	(cond
		((null l) nil)
		((atom (car l)) (cons (car l) (atomi (cdr l))))
		((listp (car l)) (append (atomi (car l)) (atomi (cdr l))))
		(T (atom (cdr l)))))
		
; c) Sa se scrie o functie care plecand de la o lista data
; ca argument, inverseaza numai secventele continue de atomi. Exemplu:
; (a b c (d (e f) g h i)) ==> (c b a (d (f e) i h g))

(defun inv(l col)
	(cond
		((null l) col)
		((atom (car l))
			(inv (cdr l) (cons (car l) col)))
		((listp (car l))
			(append col (list (inv (car l) ())) (inv (cdr l) ())))
		))
; d) Sa se construiasca o functie care intoarce maximul 
;atomilor numerici dintr-o lista, de la nivelul superficial.

