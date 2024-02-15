; 11. Se da un arbore de tipul (2). Sa se afiseze nivelul (si lista corespunza-
; toare a nodurilor) avand numar maxim de noduri. Nivelul rad. se considera 0. 

(defun stanga (l)
	(cadr l)
)
(defun dreapta (l)
	(caddr l)
)
(defun radacina (l)
	(car l)
)
(defun get_nivel (l nivel)
	(cond 
		((null l) nil)
		((= nivel 0) (list (radacina l)))
		(T (append (get_nivel (stanga l) (- nivel 1))
					(get_nivel (dreapta l) (- nivel 1))
			)
		)
	)
	)

(defun get_maxim (l maxim lvl)
	(cond
		((null (get_nivel l lvl)) maxim)
		((< maxim (length (get_nivel l lvl)))
			(get_maxim l (length (get_nivel l lvl)) (+ 1 lvl)))
		(t (get_maxim l maxim ( + 1 lvl)))))


(defun get_levels (l maxim lvl)
	(cond 
		((null (get_nivel l lvl)) nil)
		((= maxim 
				(length (get_nivel l lvl)))
					(cons (get_nivel l lvl) (get_levels l maxim  (+ 1 lvl)))
		)
		(t 
			(get_levels l maxim ( + 1 lvl)))
		)
	)


(defun maxime (l)

	(get_levels l (get_maxim l 1 0) 0)
) 
