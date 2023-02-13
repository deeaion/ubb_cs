bits 32 
global start        
extern exit               
import exit msvcrt.dll  
segment data use32 class=data
    e dw 264
    f dw 15
    g dw 85
    b db 23
    c db 21
    t db 3
    p db 5
segment code use32 class=code
    start:
    ;[(e+f-g)+(b+c)*3]/5
    mov AX,[e]
    add AX,[f]
    sub AX,[g]
    mov BX,AX;BX=e+f-g
    mov AL,[b]
    add AL,[c]
    mul byte [t];AX=b+c*3
    add BX,AX
    mov AX,BX
    div byte [p]
        push    dword 0      
        call    [exit]   
