 
; 7.
; a) Sa se scrie o functie care testeaza daca o
 ; lista este liniara.
; b) Definiti o functie care substituie prima 
; aparitie a unui element intr-o lista data.
; c) Sa se inlocuiasca fiecare sublista a unei liste 
; cu ultimul ei element. Prin sublista se intelege element
 ; de pe primul nivel, care este lista. 
 ; ; ; ; ; ; ; ; Exemplu: (a (b c) (d (e (f)))) ==> (a c (e (f))) ==> (a c (f)) ==> (a c f)
; ; ; ; ; ; ; ; (a (b c) (d ((e) f))) ==> (a c ((e) f)) ==> (a d c f)



; (defun ult_el (l)
	; (cond
		; ((null (cdr l)) (list (car l)))
		
		; ((listp (car l)) (cons (ult_el (cdr l) ult ) (ult_el (car l) nil) )))
		; (t ult_el(c
	; )))
(defun last_ (l)
	(cond
		((and (null (cdr l)) (listp (car l))) (last_ (car l)))
		((and (null (cdr l)) (atom (cdr l))) (car l))
		
		
		(t (last_ (cdr l))))) 
(defun inlocuieste-cu-ultimul (l)
		(cond 
			((null l) nil)
			((atom (car l)) (cons (car l) (inlocuieste-cu-ultimul (cdr l))))
			(t (cons (last_ (car l)) (inlocuieste-cu-ultimul (cdr l))))))

;; Exemplu de utilizare:
(let ((lista1 '(a (b c) (d (e (f)) t))))
  (format t "Rezultat: ~a~%" (inlocuieste-cu-ultimul lista1)))

(let ((lista2 '(a (b c) (d ((e) f)))))
  (format t "Rezultat: ~a~%" (inlocuieste-cu-ultimul lista2)))
; d) Definiti o functie care interclaseaza 
; fara pastrarea dublurilor doua liste liniare sortate.