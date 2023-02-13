bits 32
segment code use32 public code
global calculsuma ; eticheta
 
calculsuma:
mov eax, [esp + 4] ; accesam de pe stiva pe [b]
mov ebx, [esp + 8] ; accesam de pe stiva pe [a]
add ebx, eax ; calcul
ret 4*2 ; in acest caz 8 reprezinta numarul de octeti ce trebuie eliberati de pe stiva
;(parametrii pasati procedurii - adica cei 2 pusi pe stiva
