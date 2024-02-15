 
; 9. Definiti o functie care substituie un element E prin elementele
; unei liste L1 la toate nivelurile unei liste date L.

(defun substituire (l e l1)
	(cond 
		((equal l e) l1)
		((listp l) (list (apply #'append
						(mapcar #'(lambda (lst) (substituire lst e l1)) l))))
		(t (list l))
	)
)
(defun rez (l e l1)
	(car (substituire l e l1)))