 
; 7. Sa se scrie o functie care calculeaza suma numerelor pare minus suma
; numerelor impare la toate nivelurile unei liste.

(defun diferenta (l)
	(cond
		((numberp l)
			(cond
				((evenp l) l)
				(t (- 0 l))
			)
		)
		((listp l)
			(apply #'+ (mapcar #'diferenta l)))
		(t 0)
)
)
