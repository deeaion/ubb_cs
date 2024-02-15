 
; 6.
; a) Sa se scrie de doua ori elementul de pe pozitia a 
; n-a a unei liste liniare. De exemplu, pentru (10 20 30 40 50)
 ; si n=3 se va produce (10 20 30 30 40 50).
 (defun dublica (l n poz)
	(cond
		((null l) nil)
		((= n poz) 
				(append (list (car l) (car l)) (cdr l)))
		(t (append (list (car l)) (dublica (cdr l) n (+ 1 poz))
		)
		)
))
; b) Sa se scrie o functie care realizeaza o lista de asociere 
; ; cu cele doua liste pe care le primeste. 
; De ex: (A B C) (X Y Z) --> ((A.X) (B.Y) (C.Z)).
(defun asociere(a b)
	(cond
		((or (null a) (null b)) nil)
		(t (cons  (cons (car a) (car b) ) (asociere (cdr a) (cdr b))))))
; c) Sa se determine numarul tuturor sublistelor unei liste
 ; date, pe orice nivel. Prin sublista se intelege fie lista
 ; insasi, fie un element de pe orice nivel, care este lista.
 ; Exemplu: 
 ; (1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 (lista insasi, (3 ...), (4 5), (6 7), (9 10)).
 (defun nrSubliste(l)
	(cond
		((listp l) (+ 1 (apply #'+( mapcar #'nrSubliste  (cdr l)))))
		((atom l) 0)
	)
)
 
 
; d) Sa se construiasca o functie care intoarce numarul atomilor
 ; dintr-o lista, de la nivel superficial.