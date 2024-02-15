 
; 12. Sa se construiasca lista nodurilor unui arbore de tipul (2) parcurs in
; preordine.

;RSD


(defun stanga (l)
	(cadr l)
)
(defun dreapta (l)
	(caddr l)
)
(defun radacina (l)
	(list (car l))
)
