 
; 11. Sa se scrie o functie care sterge toate aparitiile unui atom de la
; toate nivelurile unei liste.

(defun sterge (l e)
	(cond
		((equal l e) nil)
		((listp l) (list (mapcan #'(lambda (lst) (sterge lst e)) l)))
		(t (list l))))