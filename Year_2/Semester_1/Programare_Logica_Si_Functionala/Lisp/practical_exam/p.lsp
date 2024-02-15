


;inverseaza_secvente_aux (l:list, col:list)
;l-lista dorita pentru inversare
;col-tine lista curenta/secventa curenta in ordine inversa
;returneaza lista cu secventele inversate
(defun inverseaza_secvente_aux(l col)
	(cond
		((null l) col) ;daca nu mai am de parcurs returnez lista vida
		((atom (car l))
			(inverseaza_secvente_aux (cdr l) (cons (car l) col))) ; daca e atom eu trebuie sa parcurg in continuare si sa adaug atom ul curent la col
		((listp (car l))
			(append col 
					(list (inverseaza_secvente_aux (car l) nil)) ;pentru l1 care e lista
							(inverseaza_secvente_aux (cdr l) nil))) ;parcurg restu listei la nivel superficia;
									; daca e lista inseamna ca pot adauga elementele colectate pana acum la rezultat
																										;la inversarea listei urmatoare si inversarea in continuare a listei mele
																										;mergea si cu cons
														
		))
		
;inverseaza l-lista
;L:lista dorita pentru inversare
;returneaza lista cu secventele continue inversate
(defun inverseaza (l)
	(inverseaza_secvente_aux l nil)
)

(print (inverseaza '(A B C (D (E F) G H I))))
(print (inverseaza '(A B C D E F)))
(print (inverseaza '(A (B C) D E ( F (G)))))
(print (inverseaza '(A(B(C(D)E)F)G)))
(print (inverseaza '((A (B (C))))))
(print (inverseaza '((A (B (C D))))))
(print (inverseaza '((A (B (C D))E F))))

