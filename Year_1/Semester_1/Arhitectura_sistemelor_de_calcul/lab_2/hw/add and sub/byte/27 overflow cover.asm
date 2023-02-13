;(a+b-c)-(a+d)
bits 32 
global start        
extern exit               
import exit msvcrt.dll  
segment data use32 class=data
    a db 264
    b db 15
    c db 85
    d db 23
segment code use32 class=code
    start:
    ;(a+b-c)-(a+d)
       mov AL,[a];AL=a
       mov AH,0;AX= transform in word pentru a avea rez corect
       mov BL,[b]
       mov BH,0
       add AX,BX;AX=a+b
        mov BL,[c]
       mov BH,0
       sub AX,BX;AL=a+b-c
       mov BL,[a];BH=a
       mov BH,0;BX=a 
       add BX,[d];BH=a+d
       sub AX,BX
        push    dword 0      
        call    [exit]
