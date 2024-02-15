 
; 4. Sa se construiasca o functie care intoarce suma atomilor numerici
; dintr-o lista, de la orice nivel.

(defun suma (l)
	(cond
		((numberp l) l)
		((listp l) (apply #'+ (mapcar #'suma l)))
		(t 0)
	)
)