;copy(l:list)
;l-lista pe care o vrem copiata
;R-returneaza o copie a liste9
(defun copy (l)
    (cond
        ((null l) nil)
        (t (cons (car l) (copy(cdr l))))
    )
)
;model matematic:
;subsituire (l e l1)
	;(l), daca l este atom si nu este egal cu elementul
	;(copy L1) daca l este atom si este egal cu elementul , aici daca folosesc mapcan -> altfel fara copy
	;(Ui=1->n subsituire (L e L1)), daca l este lista (l1...Ln)
;subsituire (l e l1)
	;L:-lista in care se substituie
	;E:-elementul care se substituie
	;L1:-lista cu care elementul se subsituie
(defun substituire (l e l1)
    (cond
        ((listp l)
					(list (mapcan #'(lambda (lst) (substituire lst e l1)) l)))
        ((equal l e) (copy l1)) ; copy required to avoid losing l1 due to destructive behaviour of mapcan
		;sau cu copy-list!
        (T (list l))
    ))

;model matematic (l e l1)
;main (l,e,l1) =r1, unde (r1)=subsituire(l,e,l1)
;L:-lista in care se substituie
;E:-elementul care se substituie
;L1:-lista cu care elementul se subsituie
(defun main(l e l1)
	(car (substituire l e l1)))
(print 	(main '(1 2 3 (5 1 (1))) 1 '(2 3)))
;varianta cu APPLY #'APPEND (MAPCAR)
;model matematic:
;subsituire5 (l e l1)
	;(l), daca l este atom si nu este egal cu elementul
	;L1 daca l este atom si este egal cu elementul , aici daca folosesc mapcan -> altfel fara copy
	;(Ui=1->n subsituire (L e L1)), daca l este lista (l1...Ln)
(defun substituire5 (l e l1)
    (cond
        ((listp l)
					(list (APPLY #'APPEND (mapcar #'(lambda (lst) (substituire lst e l1)) l))))
        ((equal l e) l1) ; copy required to avoid losing l1 due to destructive behaviour of mapcan
		;sau cu copy-list!
        (T (list l))
    )
)
(print 	(substituire5 '(1 2 3 (5 1 (1))) 1 '(2 3)))
;main5 (l,e,l1) =r1, unde (r1)=subsituire(l,e,l1)
;L:-lista in care se substituie
;E:-elementul care se substituie
;L1:-lista cu care elementul se subsituie
(defun main5(l e l1)
	(car (substituire5 l e l1)))
(print 	(main5 '(1 2 3 (5 1 (1))) 1 '(2 3)))
;parca asta nu merge

(defun substituire2 (l e l1)
    (cond
        ((listp l) (mapcar #'(lambda (lst) (substituire lst e l1)) l))
        ((equal l e) l1) ; copy required to avoid losing l1 due to destructive behaviour of mapcan
		;sau cu copy-list!
        (T l)
    ))
(print (substituire2 '(1 2 3 (5 1 (1))) 1 '(2 3)))

;pune doar lista pur si simplu
(defun substituire3 (l e l1)
	(cond 
		((equal l e) l1)
		((listp l) (mapcar #' (lambda (lst) (substituire3 lst e l1)) l))
		(T l)
	)
	)
		
(print (substituire3 '(1 2 3 (5 1 (1))) 1 '(2 3)))
;o alta varianta corecta! CEA CU APPLY MAPCAR
(defun substituire4 (l e l1)
	(cond
	    ((equal l e) (list (copy l1))) ; copy required to avoid losing l1 due to destructive behaviour of mapcan
		((listp l)
					(mapcan #'(lambda (lst) (substituire lst e l1)) l)))
		;sau cu copy-list!
        (T (list l)))
		

	; (defun substituire3 (l e l1)
    ; (cond
        ; ((listp l)
					; (list (mapcan #'(lambda (lst) (substituire lst e l1)) l)))
        ; ((equal l e) (copy (list l1))) ; copy required to avoid losing l1 due to destructive behaviour of mapcan
		;sau cu copy-list!
        ; (T (list l))
    ; ))
;daca l e lista-> U i=1..n substitute(lista,e,a)
;daca l=e-> a
;daca l!=e->lista(e)

;problema ar fi ca mapcar face 

;Daca ar trebui sa tin lista ar cam trebui sa fac list copy l1

