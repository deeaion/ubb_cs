; 11.
; a) Sa se determine cel mai mic multiplu comun al
 ; valorilor numerice dintr-o lista neliniara.
; ; ; ; ; ; ; b) Sa se scrie o functie care sa testeze daca o 
; ; ; ; ; ; ; lista liniara formata din numere intregi are aspect 
; ; ; ; ; ; ; de "munte"(o secvență se spune ca are aspect de "munte" 
; ; ; ; ; ; ; daca elementele cresc pana la un moment dat, apoi 
; ; ; ; ; ; ; descresc. De ex. 10 18 29 17 11 10).
; c) Sa se elimine toate aparitiile elementului 
; numeric maxim dintr-o lista neliniara.
(defun desc (l)
	(cond
		((null (cdr l)) t)
		((<= (car l) (cadr l)) nil)
		(t (desc (cdr l)))))
(defun cresc (l)
	(cond
		((null (cdr l)) nil)
		((< (car l) (cadr l)) (cresc (cdr l)))
		((> (car l) (cadr l)) (desc (cdr l)))
		(t nil))
)
(defun munte (l)
	(cond 
		((and (>= (length l) 2) (< (car l) (cadr l)))  (cresc (cdr l)))
		(t nil)
	)
	
)
; d) Sa se construiasca o functie care intoarce
 ; produsul atomilor numerici pari dintr-o lista, de la orice nivel. 
