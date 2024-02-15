; 8. Sa se construiasca o functie care intoarce maximul atomilor numerici
; dintr-o lista, de la orice nivel. 

(defun maxim (l)
	(cond 
		((numberp l) l)
		((listp l) (apply #'max (mapcar #'maxim l)))
		(t 0)
	)
)
