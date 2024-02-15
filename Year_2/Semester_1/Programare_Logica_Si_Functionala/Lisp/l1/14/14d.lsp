;maxim(l:list,m:integer)
;caut printre atomii numerici maximul dintre ei
;daca cumva e mai mare ca maximul prec atunci noul maxim va fi chiar el insusi
;atunci cand termin de parcurs lista returnez m
;model de flux(i,i)
(defun maxim(l m)
	(cond 
		((null l) m)
		((and(numberp (car l)) (<= (car l) m)) (maxim (cdr l) m))
		((and( numberp (car l)) (> (car l) m)) (maxim (cdr l) (car l)))
		;acum clauzele cand nu e atom numeric
		(T (maxim (cdr l) m))
))	
;elimina(l:lista,e:integer)
;caut elementul respectiv (in cazul nostru maximul) si il elimina
;model de flux:(i,I)
(defun elimina(l e)
	(cond
		((null l) nil)
		((and (numberp (car l)) (eq (car l) e)) (elimina (cdr l) e))
		(T (cons (car l) (elimina (cdr l) e)))
	
	))
;main(l:lista)
;aici fac apelul lui elimina unde initializez si elementul. Maximul va fi initializat cu un nr foarte mic
;model de flux:(i)
(defun main(l)
	( elimina l ( maxim l -12345))
	)


( print ( main '( 1 2 3 4 5 5 5 5 5 0)))
(print ( main '( -23 23 1 23 -23 -23)))
(print (main '(5 a b c 1 2 3 5 5 5 5 2)))