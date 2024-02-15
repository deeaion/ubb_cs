;se cere sa se elimine elementele din n in n dintr-o lista l data
;elimina_aux(l:lista,i:integer,n:integer)
;l-> lista cu care lucram
;i-> pozitia curenta din sir
;n-> din cat in cat eliminam elemntele
(defun elimina_aux (l i n)
	(cond
		(( null l) nil);daca lista a ajuns vida returnez nil
		((not (eq 0 (mod i n))) (cons (car l) (elimina_aux (cdr l) (+ i 1) n)));daca nu sunt pe o pozitie multiplu de n pot adauga elemnul si trece mai depare in lista
		(T (elimina_aux (cdr l) (+ i 1) n)));altfel  nu il mai adaug
	)

;acesta este main ul pentru elimina.
;l-> lista data
;n-> din cat in cat se elimina elementele
;aici initializez si prima poz
(defun elimina (l n)
	
		(elimina_aux l 1 n)
	)

;niste functii de test
(print (elimina '(1 2 3 4 5) 2))
(print (elimina '(1 2 3 4 0 5 6 7 8 0) 5))