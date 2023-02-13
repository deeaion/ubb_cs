;functia dimensiune: ce face? returneza numarul de caractere din sir pentru parcurgerea sirului! E cu tot cu spatii!!!!!!
bits 32
segment code use32 public code
global _dimensiune; eticheta
_dimensiune:
    push ebp
    mov ebp,esp
    mov esi,[ebp+8];offsetul stringului !
    mov ecx,0; returnam rezultatul prin ecx
    repeta:
    lodsb;incarcam in al byteul de la adresa esi
    cmp al,0
    je final
    inc ecx
    jmp repeta
    final:
    mov esp,ebp
    pop ebp
    mov eax, ecx
    
    ret
