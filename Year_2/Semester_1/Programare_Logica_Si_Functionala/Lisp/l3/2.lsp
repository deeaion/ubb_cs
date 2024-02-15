 
; 2. Definiti o functie care obtine dintr-o lista data lista tuturor atomilor
; care apar, pe orice nivel, dar in aceeasi ordine. De exemplu
; (((A B) C) (D E)) --> (A B C D E)

(defun show (l)
	(cond 
		((atom l) (list l))
		(t (mapcan #'show l)
	)
))