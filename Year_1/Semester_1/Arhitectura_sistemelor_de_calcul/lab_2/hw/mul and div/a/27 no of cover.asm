bits 32 
global start        
extern exit               
import exit msvcrt.dll  
segment data use32 class=data
    a db 21
    b db 15
    c db 3
    d dw 60
segment code use32 class=code
    start:
    ;d/[(a+b)-(c+c)] (a,b,c-b,d-w)
    mov AL,[a]
    add AL,[b]
    sub AL,[c]
    sub AL,[c]
    mov BL,AL
    mov AX,[d]
    div BL
        push    dword 0      
        call    [exit]       
