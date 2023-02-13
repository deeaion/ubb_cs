bits 32
segment code use32 public
global _litere_mici
global _litere_mari
_litere_mici:
    push ebp
    mov ebp,esp
    ;litere mici(sir,length_sir) -le punem in esi si in ecx . functia returneaza prin edx sirul rezultat
    mov esi,[ebp+8];primul e stringul
    mov ecx,[ebp+12];lenght stringul
    mov edi,[ebp+16];stringul rezultat
    mov ebx,0; in ebx retinem dimensiunea sirului pentru ca am dori sa returnam si dimensiunea sirului format
    jecxz final
    repeta:
        lodsb;incarcam in al caracterul
        cmp al,'a'
        jb term
            cmp al,'z'
            ja term
                ;daca nu se fac jmp-urile inseamna ca litera e din intervalul 'a' si 'z'
                inc ebx;incrementam dimensiunea sirului obt
                stosb
    term:
        loop repeta
    final:
        ;in final o sa avem in edi sirul rezultat si in ebx dimensiunea
        mov al,0
        stosb 
    mov esp,ebp
    pop ebp
    ret 
_litere_mari:
push ebp
    mov ebp,esp
    mov esi,[ebp+8];primul e stringul
    mov ecx,[ebp+12];lenght stringul
    mov edi,[ebp+16];stringul rezultat
    mov ebx,0; in ebx retinem dimensiunea sirului pentru ca am dori sa returnam si dimensiunea sirului format
    jecxz final_2
    repeta_2:
        lodsb;incarcam in al caracterul
        cmp al,'A'
        jb term_2
            cmp al,'Z'
            ja term_2
                ;daca nu se fac jmp-urile inseamna ca litera e din intervalul 'A' si 'Z'
                inc ebx;incrementam dimensiunea sirului obt
                stosb
    term_2:
        loop repeta_2
    final_2:
        ;in final o sa avem in edi sirul rezultat si in ebx dimensiunea
        mov al,0
        stosb
    mov esp,ebp
    pop ebp
    ret 
