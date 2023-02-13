bits 32 
global start        
extern exit               
import exit msvcrt.dll  
segment data use32 class=data
    a db 250
    b db 15
    c db 85
    d db 23
segment code use32 class=code
    start:
    ;(a+b-c)-(a+d)
       mov AL,[a];AL=a
       add AL,[b];AL=a+b
       sub AL,[c];AL=a+b-c
       mov AH,[a];AH=a
       add AH,[d];AH=a+d
       sub AL,AH
        push    dword 0      
        call    [exit]