
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a db 78
    b db -23
    c dw 252
    e dd 675
    x dq -56578
; our code starts here
segment code use32 class=code
    start:
    ;(100+a+b*c)/(a-100)+e+x/a; a,b-byte; c-word; e-doubleword; x-qword
    ;cu semn
    ;x/a-> a dd... b*c->b dw.. b*c->dd(DX:AX)...(100+a+b*c)->dq
    mov al,[a]
    CBW
    CWDE;eax=a
    mov ebx,eax;ebx=a (dd)
    mov eax,[x]
    mov edx,[x+4]
    idiv ebx; eax=x/a; edx=x%a
    mov ecx,eax;ecx=x/a
    add ecx,[e];ecx=x/a+e
    mov al,[b]
    CBW
    imul dword [c];dx:ax=b*c
    push dx
    push ax
    pop eax;eax=b*c
    add eax,ebx
    add eax,100;eax=(100+a+b*c)
    CDQ
    sub ebx,100;a-100
    idiv ebx;(100+a+b*c)/(a-100)
    add eax,ecx
    
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
