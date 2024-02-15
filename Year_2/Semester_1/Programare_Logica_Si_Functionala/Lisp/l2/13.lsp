; cale (node: atom, nodul cautat,l -> arborele in vare cautam)
;cale(node,l1 l2 l3) -> 
                    ;lista vida, daca n=0
                    ;[node], daca l1=node
                    ;l1Ucale(l2) daca cale l2 nu este vida( cale l2 este vida daca elementul nu a fost gasit)
                    ;cale(l2) 



; (defun cale (node l)

    ; (cond
        ; ((null (car l)) nil) ;inseamna ca lista e vida
        ; ((equal node (car l)) (list (car l)));daca am gasit il adaug ca lista de el pentru ca sa pot sa adaug cand il construiesc
        ; ((setq left (cale node (cadr l)));setez stanga rezultatul cautarii in subarborele stang
            ; (cond ;acum ma uit in el
                ; (( null left) nil) ; daca left este gol returnez nil
                ; (T (append (list (car l) left))) ;altfel inseamna ca in subarborele stang a fost gasit ceva ( acel ceva fiind elementul deci adaug nodul curent la lista rezultata)
            ; ))
; ; la subarborele drept l3 este la fel ca la cel stang
        ; (t 
            ; (setq right (cale node (caddr l)))
                ; (cond 
                    ; ((null right) nil)
                    ; (T (append (list (car l) right)))
                ; )
            
        ; )
    
    
    
    ; )
; )
;cale(node:atom, l -> arborele pe care il parcurgem)
(defun cale (node l)

    (cond
        ((null (car l)) nil) ;inseamna ca lista e vida ramasa
        ((equal node (car l)) (list (car l)));daca am gasit il adaug ca lista de el pentru ca sa pot sa adaug cand il construiesc
        ((not (equal nil (cale node (cadr l)))) (append (list (car l))  (cale node (cadr l)))) ; inseamna ca in subarborele stang a fost gasit ceva (exista nodul e)
								;( acel ceva fiind elementul deci adaug nodul curent la lista rezultata)
        ((not (equal nil (cale node (caddr l)))) (append (list (car l))  (cale node (caddr l)))) ;daca cale de lista dreapta inseamna ca am gasit ceva											;a		
        (t nil)
    )

)

;(setq arbore '(A (B) (C (D) (E))))

(setq arbore '(A (B (D (E (F (G) (H (J) (K)))))) (C (L (N (V (S) (T))) (Q (P) (R))) (M))))
(setq nod-cautat 'S)
(setq rezultat (cale nod-cautat arbore))

(if rezultat
    (format t "Calea catre nodul ~a: ~a~%" nod-cautat rezultat)
    (format t "Nodul ~a nu a fost gasit in arbore ~a.~%" nod-cautat arbore))