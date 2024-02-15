; 5. Definiti o functie care testeaza apartenenta unui nod intr-un arbore n-ar
; reprezentat sub forma (radacina lista_noduri_subarb1... lista_noduri_
; _subarbn)
; Ex: arborelele este (a (b (c)) (d) (e (f))) si nodul este 'b => adevarat 



(defun cauta (l e)
	(cond 
		((equal l e) 1)
		((listp l) (apply #'+ (mapcar #'(lambda (lst) (cauta lst e)) l)))
		(t 0))
		)