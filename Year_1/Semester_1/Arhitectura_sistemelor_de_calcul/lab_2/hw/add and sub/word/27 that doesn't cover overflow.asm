;a+b-(c+d)+100h
;cel care nu functioneaza pe toate
bits 32 
global start        
extern exit               
import exit msvcrt.dll  
segment data use32 class=data
    a dw 2150
    b dw 1598
    c dw 852
    d dw 2387
segment code use32 class=code
    start:
    ;a+b-(c+d)+100h=
       mov AX,[a];AX=a
       mov BX,[b]
       add AX,BX;AX=a+b
       mov BX,[c]
       add BX,[d]
       sub AX,BX
       add AX,100h
        push    dword 0      
        call    [exit]  
