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
    p dw 5
segment code use32 class=code
    start:
    ;[(e+f-g)+(b+c)*3]/5
    mov AX,[e]
    mov DX,0
    push DX
    push AX
    pop EAX;EAX=e
    mov EBX,EAX;EBX=e
    mov AX,[f]
    mov DX,0
    push DX
    push AX
    pop EAX;EAX=f
    add EBX,EAX
    mov AX,[g]
    mov DX,0
    push DX
    push AX
    pop EAX;EAX=g
    sub EBX,EAX;EBX=e+f-g
    mov AL,[b]
    add AL,[c]
    mul byte [t];AX=b+c*3
    mov DX,0
    push DX
    push AX
    pop EAX;EAX=b+c*3
    add EAX,EBX;EAX=(e+f-g)+(b+c)*3
    push EAX
    pop AX
    pop DX
    div word [p]
   
    
   
    
        push    dword 0      
        call    [exit]       