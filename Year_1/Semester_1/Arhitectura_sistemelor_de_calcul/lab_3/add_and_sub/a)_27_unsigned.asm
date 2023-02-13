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
    a db 42
    b dw 231
    c dd 2123
    d dq 21
; our code starts here
segment code use32 class=code
    start:
    ;a - byte, b - word, c - double word, d - qword - Interpretare fara semn
;(a+c)-(d+b)
    mov ax,[b];AX=b
    mov dx,0;DX:AX=b
    push dx
    push ax
    pop eax;EAX=b
        mov edx,0;EDX:EAX=b
        add eax, dword [d]
        adc edx, dword [d+4];EDX:EAX=b+d
        mov bl,[a];BL=a
        mov bh,0;BX=a
        mov cx,0;CX:BX=a
        push cx
        push bx
        pop ebx;EBX=a
        add ebx,[c];EBX=a+c
        mov ecx,0;ECX:EBX=a+c
        sub ebx,eax
        sbb ecx,edx;ECX:EBX=(a+c)-(b+d)
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
