;a - byte, b - word, c - double word, d - qword - Interpretare fara semn
;(a+c)-(d+b)
bits 32
global start
extern exit              
import exit msvcrt.dll   
segment data use32 class=data
    a db 42
    b dw 231
    c dd 2123
    d qword 21

segment code use32 class=code
    start:
        mov eax,[c]
        mov edx,0
        add eax, dword [d]
        adc edx, dword [d+4]
        push    dword 0      
        call    [exit]      
