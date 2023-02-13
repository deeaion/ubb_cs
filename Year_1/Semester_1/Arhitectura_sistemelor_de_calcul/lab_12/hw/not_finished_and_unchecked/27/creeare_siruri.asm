bits 32
global _citire_numere
global _numere_pare
global _numere_impare
extern fopen,fscanf
segment data public data use 32
    nume_fisier db "numere.txt",0
    format_s db "%d",0
    descriptor_fisier dd 0
    mod_acces db "%r",0
    var dd 0
segment code public code use 32
    _citire_numere:
    ;fopen(nume_fisier,mod_acces)
    push ebp
    mov ebp,esp
    mov ebx,0
    ;citre_numere(sir) ret prin eax rez
    mov edi,[ebp+8]
    push dword mod_acces
    push dword nume_fisier
    call [fopen]
    add esp,4*2
    ;fscanf(descriptor_fisier,format,var)
    cmp eax,0
    je final
    mov [descriptor_fisier],eax
    mov ebx,0
    repeta:
        push dword [descriptor_fisier]
        push dword format_s
        push dword [var]
        add esp, 4*3
        mov eax,[var]
        lodsd
        cmp eax,0
        inc ebx
        je final
        jmp repeta
    final:
    mov eax,ebx
    pop ebp
    ret
    _numere_pare:
    ;nr_p=numere(pare(sir,n_el,n_p)
    push ebp
    mov ebp,esp
    mov esi,[ebp+8]
    mov ecx,[ebp+12]
    mov edi, [ebp+16]
    mov ebx,0
    jecxz final
    repeta2:
    lodsd
    ror eax,1
    jc impar
    movsd 
    inc ebx;numarul de numere pare
    impar:
    loop repeta2
    mov eax,ebx
    pop ebp
    ret
    _numere_impare:
    ;nr_p=numere(pare(sir,n_el,n_p)
    push ebp
    mov ebp,esp
    mov esi,[ebp+8]
    mov ecx,[ebp+12]
    mov edi, [ebp+16]
    mov ebx,0
    jecxz final
    repeta3:
    lodsd
    ror eax,1
    jnc par
    movsd 
    inc ebx;numarul de numere pare
    par:
    loop repeta3
    mov eax,ebx
    pop ebp
    ret
    