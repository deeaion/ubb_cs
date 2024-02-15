 
; 9.
; a) Sa se scrie o functie care intoarce diferenta a doua multimi.
; b) Definiti o functie care inverseaza o lista impreuna 
; cu toate sublistele sale de pe orice nivel.
; ; ; ; ; ; ; c) Dandu-se o lista, sa se construiasca lista primelor 
; ; ; ; ; ; ; elemente ale tuturor elementelor lista ce au un numar 
; ; ; ; ; ; ; impar de elemente la nivel superficial. 
; ; ; ; ; ; ; Exemplu: (1 2 (3 (4 5) (6 7)) 8 (9 10 11)) => (1 3 9).
(defun liste (l)
		(cond
		((listp l) (mapcan  #'(lambda (lst) 
				; (print lst)
				(cond
					((and (listp lst) (oddp (length lst))) (list (car lst)))
					(t nil)
				)
			) l))
		(t nil)
		)
		)
(defun main_liste (l)
	((lambda (el)
		(cond 
			((oddp (length l)) (cons (car l) el))
			(t el)
		)
	)
		(liste l)))
(print (length '(1 2 (3 (4 5) (6 7)) 8 (9 10 11))))
(print (main_liste '(1 2 (3 (4 5) (6 7)) 8 (9 10 11))))
; d) Sa se construiasca o functie care intoarce suma atomilor 
; numerici dintr-o lista, de la nivelul superficial.
