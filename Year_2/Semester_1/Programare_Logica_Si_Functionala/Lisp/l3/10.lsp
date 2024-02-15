 
; 10. Definiti o functie care determina numarul nodurilor de pe nivelul k
; dintr-un arbore n-ar reprezentat sub forma (radacina lista_noduri_subarb1
; ... lista_noduri_subarbn) Ex: arborelele este (a (b (c)) (d) (e (f))) si
; k=1 => 3 noduri


(defun nr_noduri (l lvl k)
	(cond
		((and (equal k lvl) (atom l)) 1)
		((listp l) (apply #'+ (mapcar #'(lambda (lst) (nr_noduri lst (+ 1 lvl) k)) l)
			))
		(t 0)
	)
)
		