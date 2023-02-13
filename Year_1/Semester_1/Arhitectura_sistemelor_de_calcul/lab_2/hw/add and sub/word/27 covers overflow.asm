;a+b-(c+d)+100h
;cel care functioneaza pe toate
bits 32 
global start        
extern exit               
import exit msvcrt.dll  
segment data use32 class=data
    a dw 21500
    b dw 56980
    c dw 852
    d dw 2387
segment code use32 class=code
    start:
    ;a+b-(c+d)+100h=
       mov AX,[a];AX=a
       mov DX,0
       push DX
       push AX
       pop EAX
       mov EBX,EAX
       mov AX,[b]
       mov DX,0
       push DX
       push AX
       pop EAX
       add EBX,EAX;EBX=a+b
       mov AX,[c]
       mov DX,0
       push DX
       push AX
       pop EAX;EAX=c
       sub EBX,EAX
       mov AX,[d]
       mov DX,0
       push DX
       push AX
       pop EAX;EAX=d
       mov EDX,EAX
       sub EBX,EDX
       add EBX,100h
        push    dword 0      
        call    [exit]               
