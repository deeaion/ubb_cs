 
; 3. Sa se construiasca o functie care verifica daca un atom e membru al
; unei liste nu neaparat liniara.

(defun _member (l e)
	(cond
		((equal l e) 1)
		((listp l)
			(apply #'+ 
				(mapcar #' (lambda (lst) (_member lst e)) l)
			)
		)
		(T 0)
	)
)