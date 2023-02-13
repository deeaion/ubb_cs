bits 32
global start
import printf msvcrt.dll
import exit msvcrt.dll
import scanf msvcrt.dll
extern printf, exit, scanf
extern calculsuma ; declarare eticheta de calcul din modulul secundar
 
segment data use32
format_afisare db "suma=%d", 10, 13, 0
mesaja db "introduceti a=",10, 13, 0
mesajb db "introduceti b=",10, 13, 0
format db "%d",0
a resd 1
b resd 1
 segment code use32 public code
start:
;in main vom citi numerele a, b
;printare mesaj de citire pe ecran
push dword mesaja
call [printf]
add esp,4
;citire a
push dword a
push dword format
call [scanf]
add esp,4*2
;printare mesaj de citire pe ecran
push dword mesajb
call [printf]
add esp,4
;citirea lui b de la tastatura
push dword b
push dword format
call [scanf]
add esp,4*2
 
push dword [a] ;salvam pe stiva numerele citite pentru a fi accesate din modulul secundar
push dword [b]
call calculsuma ; apelare functie de calcul suma din modulul secundar 
;afisare
push ebx; s-a salvat pe stiva!
push format_afisare
call [printf]
add esp, 2*4
; popa
push dword 0
call [exit]
