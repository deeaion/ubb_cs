; 1.
; a) Sa se insereze intr-o lista liniara un 
	; atom a dat dupa al 2-lea, al 4-lea, al 6-lea,....element.
(defun inserare_aux (l poz pozC e)
	(cond 
		( (and (equal poz pozC) (null l)) (list e))
		( (null l) nil)
		( (equal poz pozC) (append (list e) (inserare_aux l poz (+ pozC 2) e) ) )
		(T (append (list (car l)) (inserare_aux (cdr l) (+ poz 1) pozC e)))
		)
)
(print (inserare_aux '(1 2 3 4) 0 2 0))
; b) Definiti o functie care obtine dintr-o lista data
	; lista tuturor atomilor care apar, pe orice nivel,
		; dar in ordine inversa. De exemplu: (((A B) C) (D E)) --> (E D C B A)

(defun lista_inv( l col)
	(cond
		((null l) col)
		((listp (car l))
			(lista_inv (cdr l) (lista_inv (car l) col)))
		(T (lista_inv (cdr l) (append (list (car l)) col)))))
;(trace lista_inv)
( print (lista_inv '(1 2 3 (4 5(6))) '())) 

; c) Definiti o functie care intoarce cel mai mare
	; divizor comun al numerelor dintr-o lista neliniara.
	
(defun gcd_ (a b)
	(cond
		((= b 0) a)
		((= a 0) b)
		(t (gcd_ b (mod a b)))))
(defun gcd_list (l aux)
	(cond
		((null l) aux)
		((numberp (car l)) (gcd_list (cdr l) (gcd_ (car l) aux)))
		((listp (car l)) (gcd_list (cdr l) (gcd_list (car l) aux)))
		(t (gcd_list (cdr l) aux))))
(print (gcd_list '(2 2 2 A (6 2 4 4) 10) 0))

; d) Sa se scrie o functie care determina 
	; numarul de aparitii ale unui atom dat intr-o lista neliniara.
(defun aparitii (l e)
	(cond 
		((null l) 0)
		((equal (car l) e) (+ 1 (aparitii (cdr l) e)))
		((listp (car l)) (+ (aparitii (cdr l) e) (aparitii (car l) e)))
		(t (aparitii (cdr l) e))))
(print (aparitii '(1 2 3 4 (1 (1))) 1))