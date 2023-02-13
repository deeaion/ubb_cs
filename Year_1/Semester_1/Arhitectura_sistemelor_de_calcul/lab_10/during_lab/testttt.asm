bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit  
import fopen msvcrt.dll
extern fopen,fread
import fread msvcrt.dll
extern printf 
import printf  msvcrt.dll          ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
des_f dd -1
nr times 2 dd 0
nume_fisier db "nr.asm",0
mod_acces db "r",0
len equ 100
numbers times len dd 0
  
; our code starts here
segment code use32 class=code
    start:

       push dword mod_acces
       push dword nume_fisier
       call [fopen]
       add esp,4*2
       mov [des_f],eax
       push dword [des_f]
       push dword 2
       push dword 8
       push dword nr
       call [fread]
       add esp,4*4
       mov ebx,[nr]
       
       
       
       
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
