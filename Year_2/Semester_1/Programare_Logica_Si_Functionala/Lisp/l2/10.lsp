; 10. Se da un arbore de tipul (2). Sa se precizeze nivelul pe care apare un nod
; x in arbore. Nivelul radacii se considera a fi 0. 

(defun stanga (l)
	(cadr l)
)
(defun dreapta (l)
	(caddr l)
)
(defun radacina (l)
	(car l)
)


(defun nivel_x (l x n)
	(cond
		((null l) nil)
		((equal (radacina l) x) n)
		
		(t (or 
			(nivel_x (stanga l) x (+ 1 n)) 
				(nivel_x (dreapta l) x (+ 1 n))
			)
		)
	)
)