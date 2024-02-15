 
; 3.

; a) Definiti o functie care intoarce produsul a doi vectori.
(defun produs (a b)
	(cond 
		((or (null a) (null b)) 0)
		(t (+ (* (car a) (car b)) (produs (cdr a) (cdr b))))
		)
)


; b) Sa se construiasca o functie care intoarce adancimea unei liste.

(defun adancime (l)
	(cond 
		((null l) 0)
		((atom l) 0)
		((listp l) 
				(+ 1 (apply #'max  
					(mapcar #'adancime (cdr l))
			)))))
		
;divide
; ; ; ; ; ; ; ; ; (defun divide (l rez)
	; ; ; ; ; ; ; ; ; (cond
		; ; ; ; ; ; ; ; ; ((null l) rez)
		; ; ; ; ; ; ; ; ; ((null (cdr l)) (cons (append  (list (car l)) (car rez)) (cdr rez)))
		; ; ; ; ; ; ; ; ; (t (divide (cddr l) (append (list (append (list (car l)) (car rez))) (list (append (list (cadr l)) (cadr rez))))))))
		
; ; ; ; ; ; ; ; ; (defun my_merge (A B)
	; ; ; ; ; ; ; ; ; (cond 
		; ; ; ; ; ; ; ; ; ((null B) A)
		; ; ; ; ; ; ; ; ; ((null A) B)
		; ; ; ; ; ; ; ; ; ((<= (car A) (car B)) (append (list (car A)) (my_merge (cdr A) B)))
		; ; ; ; ; ; ; ; ; (t (append (list (car B)) (my_merge A (cdr B))))))
		
; ; ; ; ; ; ; ; ; (defun merge_sort (l)
	; ; ; ; ; ; ; ; ; (cond
		; ; ; ; ; ; ; ; ; ((null l) l)
		; ; ; ; ; ; ; ; ; ((null (cdr l)) l)
		; ; ; ; ; ; ; ; ; (t ((lambda (X)
			; ; ; ; ; ; ; ; ; ( my_merge (merge_sort (car X)) (merge_sort (cadr X)))
			; ; ; ; ; ; ; ; ; )
			; ; ; ; ; ; ; ; ; (divide l nil)
		; ; ; ; ; ; ; ; ; )
	; ; ; ; ; ; ; ; ; )))
			
			; (defun merge_sort (l)
	; (cond
		; ((null l) l)
		; ((null (cdr l)) l)
		; (t 
			; (my_merge (merge_sort (car (divide l nil))) (merge_sort (cadr (divide l nil))))
			; )
			
		; )
	; )

; c) Definiti o functie care sorteaza fara pastrarea dublurilor o lista liniara.
(defun merge_sort (l)
	(cond
		((null l) l)
		((null (cdr l)) l)
		(t ((lambda (X) 
				(mymerge (merge_sort (car X)) (merge_sort(cadr X))))
					(divide l nil)))))
	;merge sort 
		;l daca e null l 
		;l daca n=1
		;merge(merge_sort A B), unde [A,B]=divide(l,nil)
	;divide
		;rez daca l e null 
		;daca n=1 -> ((l1+r1) r2)
		;altfel -> divide (l3..ln,((l1+r1),(l2+r2))), unde (r1,r2)=rez ,rez lista formata din doua elemente
(defun divide(l rez)
	(cond 
		((null l) rez)
		((null (cdr l)) (list (append (list (car l)) (car rez)) (cadr rez)))
		(t (divide (cddr l) (list (append (list (car l)) (car rez)) (append (list (cadr l)) (cadr rez)))))))
	
	;my merge
		;a, b vid
		;b, daca a vid
		;a1+mymerge(a2..an,b1..bn)
		;b1+mymerge(a1...an,b2...bn)
		;mymerge (a2..an,b2..bn) altfel
(defun mymerge ( A B)
	(cond 
		((null B) A)
		((null A) B)
		((< (car A) (car B)) (append (list (car A)) (mymerge (cdr A) B)))
		((> (car A) (car B)) (append (list (car B)) (mymerge A (cdr B))))
		(t (append (list (car A)) (mymerge (cdr A) (cdr B))))
	)
)
; d) Sa se scrie o functie care intoarce intersectia a doua multimi.
(defun cauta (l e)
	(cond
	((null l) nil)
	((equal (car l) e) t)
	(t (cauta (cdr l) e))))
(defun intersectie (a b)
	(cond 
		((null a) nil)
		((cauta b (car a)) (cons (car a) (intersectie (cdr a) b)))
		(t (intersectie (cdr a) b))))

