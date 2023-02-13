;header
bits 32
;declaram start-ul global
global start
;import/extern exit and other functions u need from c etc
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
extern exit,printf,scanf
;preluare prin extern functiile din fisierul de care avem nevoie
 extern litere_mici
extern litere_mari
extern dimensiune
;data segment
segment data use32
;pentru siruri ! declaram len and pointerse
    len_main dd 0
    len_l_mici dd 0
    len_l_mari dd 0
    s_main times 100 db 0
    s_l_mici times 100 db 0
    s_l_mari times 100 db 0
    scan_opt dd 0
;pentru mesaje! 
    first_mes db "If you want to enter a string without any blankspaces enter 1!",10,0
    first_mes_2 db "If you want to enter a string with blankspaces enter 2! ",10,0
    opt db "Your option is:",0
    second_mes_2 db "You have entered option 2. Please enter the string. Finish the string with \n!",10,0
    second_mes db "You have entered option 1. Please enter the string.",10,0
    print_l_mici db "Sirul dumneavoastra cu litere mici este %s",10,0
    print_l_mari db "Sirul dumneavoastra cu litere mari este %s",10,0
;scanari! Avem doua tipuri de scanari. Cea pentru type 1 si type 2
    scan_1 db "%s",0
    scan_o db "%d",0
    scan_2 db "%[^\n]s",0
;code segment
segment code use32 public code
;start hehe
start:
;print first message
    push dword first_mes
    call [printf]
    add esp,4*1
    ;print second message
    push dword first_mes_2
    call [printf]
    add esp,4*1
    ;optiune
    push dword opt
    call [printf]
    add esp,4*1
    ;det opt
    push dword scan_opt
    push dword scan_o
    call [scanf]
    add esp,4*2
    ;daca opt e 1
    cmp dword [scan_opt],1
    je option_1
    ;aici e optiunea 2
    ;message 2
    push dword second_mes_2
    call[printf]
    add esp,4
    ;scan 2
    push dword s_main
    push dword scan_2
    call [scanf]
    add esp,4*2
    jmp finished_scan
    option_1:
    push dword second_mes
    call[printf]
    add esp,4
    push dword  s_main
    push dword scan_1
    call [scanf]
    add esp,4*2
    finished_scan:
    ;am verificat daca citeste bine
                                ; push dword s_main
                                ; push dword print_l_mari
                                ; call[printf]
                                ; add esp,4*2
   ;am finalizat scanarea!
   push dword s_main
   call dimensiune; programul preia procedura dimensiune din dimensiune.asm
   mov [len_main],ecx
   ;am obtinut dimensiunea sirului main! ea ne trebuie pentru parcurgerea acestuia
   ;literemici(sir,length,sir_destinatie)
   push dword s_l_mici
   push dword [len_main]
   push dword s_main
   call litere_mici
   push dword s_l_mari
   push dword [len_main]
   push dword s_main
   call litere_mari
   ;mov s_l_mici,edi
   ;mov len_l_mici,ebx
   push dword s_l_mici
   push dword print_l_mici
   call[printf]
   add esp,4*2
   push dword s_l_mari
   push dword print_l_mari
   call[printf]
   add esp,4*2
    push 0
    call [exit]
