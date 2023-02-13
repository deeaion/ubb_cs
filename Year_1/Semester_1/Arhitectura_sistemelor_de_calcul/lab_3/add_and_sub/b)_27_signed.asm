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
    d dq 45
; our code starts here
segment code use32 class=code
    start:
    ;a - byte,c - double word, d - qword - Interpretare cu semn
;(d+d-c)-(c+c-a)+(c+a)=d+d-c-c+c+a+a=d+d-c+a+a
    mov eax,dword[d]
    mov edx,dword[d+4];edx:eax=d
    add eax,dword[d]
    adc edx,dword[d+4];edx:eax=d+d
    mov ebx,eax
    mov ecx,edx;ecx:ebx=d+d
    mov eax,[c];eax=c
    CDQ;EDX:EAX=c
    sub ebx,eax
    sbb ecx,edx;ecx:ebx=d+d-c
    mov al,[a];AL=a
    CBW;AX=a
    CWDE;eax=a
    CDQ;edx:eax=a--
    add ebx,eax
    adc ecx,edx;ecx:ebx=d+d-c+a
    add ebx,eax
    adc ecx,edx;ecx:ebx=d+d-c+a+a
    
    
    
    
    
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
