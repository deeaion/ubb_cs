bits 32 
global start        
import printf msvcrt.dll
import scanf msvcrt.dll
extern exit,printf,scanf           
import exit msvcrt.dll  
segment data use32 class=data
    s db '2','a','b','c','d','e','f','g','8','1','&','c','c','c'
    ls equ $-s
    c dw 0
    format db "%c",0
    formatt db "Nr este %c",0
    formatp db "Caracterul %c apare de %d ori in sirul dat",0
; our code starts here
segment code use32 class=code
;Se dă un sir de caractere (definit in segmentul de date). Să se citească de la tastatură un caracter, să se determine numărul de apariţii al acelui caracter în şirul dat şi să se afişeze acel caracter împreună cu numărul de apariţii al acestuia.
    start:
        push dword c
        push dword format
        call [scanf]
        add esp,4*2
        mov esi,s
        mov ecx,ls
        mov edx,0; numarul de aparitii
        jecxz final
        repeta:
            lodsb;pune in al caracterul !!!! si uh incrementeaza esi
            cmp al,[c]
            jne continua
            inc edx
            continua:
            loop repeta
           final:
        push dword edx
        push dword [c]
        push dword formatp
        call [printf]
        add esp,4*3
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
