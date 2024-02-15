 
; 8. Sa se construiasca lista nodurilor unui arbore de tipul (2) parcurs in
; inordine.
(defun stanga (l)
	(cadr l)
)
(defun dreapta (l)
	(caddr l)
)
(defun radacina (l)
	(list (car l))
)
(defun parcurgere_inordine (lista)
	
		(cond
			((null lista) nil)
			(t (append (parcurgere_inordine ( stanga lista) ) (radacina lista) (parcurgere_inordine (dreapta lista)))) 
		)
	)