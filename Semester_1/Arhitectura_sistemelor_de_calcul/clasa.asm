bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,scanf,printf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import scanf msvcrt.dll
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 0
 
    format db "%d",0
    b db 0
    formatb db "%d",0
    c dw 0
    formatc db "%d",0
    message db "Suma lui %d + %d + %d este  %d",0
; our code starts here
segment code use32 class=code
    start:
    push dword a
    push dword format
    call [scanf]
    add esp,4*2
    mov ebx,0
    add ebx,[a]
    push dword b
    push dword formatb
    call [scanf]
    add esp,4*2
    add ebx,[b]
    push dword c
    push dword formatc
    call [scanf]
    add esp,4*2
    add ebx,[c]
    push ebx
    push dword [c]
    push dword [b]
    push dword [a]
    push dword message
    call [printf]
    add ESP,5*4
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
