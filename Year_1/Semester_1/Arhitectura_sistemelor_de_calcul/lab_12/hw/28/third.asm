bits 32
global _citire
extern _scanf,_printf
segment data use32 public code
second_mes_2 db "You have entered option 2. Please enter the string. Finish the string with \n!",10,0
scan_2 db "%[^\n]s",0
segment code use32 public code
_citire:
push ebp
mov ebp,esp
mov edi,[ebp+8]
push dword second_mes_2
    call _printf
    add esp,4
    ;scan 2
    push dword edi
    push dword scan_2
    call _scanf
    add esp,4*2
    mov esp,ebp
    pop ebp
    ret 