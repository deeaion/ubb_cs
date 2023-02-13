bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit  ,scanf,fscanf,fopen,fclose,printf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll 
import scanf msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll; 
import printf msvcrt.dll;exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    fisier times 20 db 0
    descriptor dd 0
    mod_acces db "r",0
    n dd 0
    c dd 0
    dif dd 0
    format_d db "%d",0
    format_s db "%s",0
    format_c db "%c",0
    mesaj_eroare db "Fisierul nu a fost gasit",0

; our code starts here
segment code use32 class=code
    start:
    ;Se citeste de la tastatura un nume de fisier si un numar N (0<= N < 8). Programul va lua cel de-al N-ule bit din fiecare caracter(byte) din fisier si va face diferenta acestor biti. Programul va afisa diferenta la consola.
    push dword fisier
    push dword format_s
    call [scanf]
    add esp,4*2
    push dword n
    push dword format_d
    call [scanf]
    add esp,4*2
    ;fopen(nume,mod_acces)
    push dword mod_acces
    push dword fisier
    call [fopen]
    add esp,4*2
    cmp eax,0
    je eroare
    mov [descriptor],eax
    ;scanam primul numar
    ;fscanf(desc,format,var)
    push dword c
    push dword format_c
    push dword [descriptor]
    call [fscanf]
    add esp,4*3
    mov ecx,[n]
    mov al, byte [c]
    repeta_primul:
        cmp ecx,0
        je bitul_prim
        shr al,1
        loop repeta_primul
    bitul_prim:
        shr al,1
        jc unu_prim
        mov dword [dif],0
        jmp terminat_primul
    unu_prim:
        mov dword [dif],1
    terminat_primul:
    cmp eax,-1
        je gata
    repeta:
        
        push dword c
        push dword format_c
        push dword [descriptor]
        call [fscanf]
        add esp,4*3
        cmp eax,-1
        je gata
        push eax
        mov al, byte [c]
        mov ecx,[n]
        repeta_caracter:
        cmp ecx,0
        je bitul
        shr al,1
        loop repeta_caracter
    bitul:
        shr al,1
        jc unu
        sub dword [dif],0
        pop eax
        jmp repeta
    unu:
        sub dword [dif],1
        pop eax
        jmp repeta  
    push dword [descriptor]
    call [fclose]
    add esp,4
    
    gata:
    push dword [dif]
    push dword format_d
    call [printf]
    add esp,4*2
    jmp final
    eroare:
        push dword mesaj_eroare
        call [printf]
        add esp,4
   final:
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
