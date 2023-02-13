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
    ;a+b?=w
    ;c+c?=w
    mov AL,[a]
    mov AH,0
    mov BL,[b]
    mov BH,0
    add AX,BX
    mov BL,[c]
    mov BH,0
    sub AX,BX;AX=a+b-c
    sub AX,BX;AX=a+b-2c=a+b-c+c
    mov BX,AX;BX=a+b-2c=a+b-c+c
    mov AX,[d]
    mov DX,0
    div BX;BX=d/[(a+b)-(c+c)]
        push    dword 0      
        call    [exit]       
