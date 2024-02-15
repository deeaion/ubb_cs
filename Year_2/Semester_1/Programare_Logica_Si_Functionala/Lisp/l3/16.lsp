; Definiti o functie care inverseaza o lista impreuna cu toate sublistele
; sale de pe orice nivel

(defun _reverse (l)
	(cond
		((atom l) l)
		((listp l) (mapcar '_reverse (reverse l)))
	)
)

(print (_reverse '(1 (2 3) (4 ( 5 6)))))


(defun my_reverse_helper (l col)
	(cond
		((null l) col)
		(t (my_reverse_helper (cdr l) (cons (car l) col)))))
(defun my_reverse(l)
	(my_reverse_helper l ()))

(defun _reverse2  (l)
	(cond 
		((atom l) (list l))
		((listp l)
			(list (apply #'append 
			(mapcar #'(lambda (lst) (_reverse2 lst)) (my_reverse l))))
		))
	)
