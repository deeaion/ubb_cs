bits 32 
global start        
extern exit              
import exit msvcrt.dll    
segment data use32 class=data
    s1 db '+','4','2','a','8','4','X','5'
    nr_es1 equ $-s1
    s2 db 'a','4','5'
    nr_es2 equ $-s2
    l db nr_es1/3+nr_es2+1
    d times (nr_es1/3+nr_es2+1) db 0
    
; our code starts here
segment code use32 class=code
    start:
    ;Se dau doua siruri de caractere S1 si S2. Sa se construiasca sirul D prin concatenarea elementelor de pe pozitiile multiplu de 3 din sirul S1 cu elementele sirului S2 in ordine inversa.
    ;vom adauga intai pe pozitiile multiplu de 3 care pentru noi sunt unde k multiplu de 3 ex: esi+0 esi+3 esi+6 etc. Spunem ca esi deoarece vom folosi registrul esi pentru a retine siruriile. 
    ;edi va fi folosit ca si sirul destinatiei
        mov esi,s1;il adaugam pe primul sir in esi
        mov edx,nr_es1; salvam lungimea lui esi in edx
        mov edi,d; asa cum am mentionat mai devreme retinem sirul destinatie in edi
        mov ecx,[l];
        mov ebx,0; il folosim ca un index  pentru parcurgerea sirului 
        jecxz final ;daca len(s1)+len(s2)=0 nu se intra in loop
        cmp edx,0
        jz adauga_el_s2;daca sirul s1 vid sarim la adaugarea celorlalte elemente
        adauga_el_s1:
            mov al,[esi]; daca nu s-a intamplat nimic mai sus esi oricum incepe de la 0 deci daca nu se trece cu indexul de lungimea lui se efectueaza operatia in mod normal
            mov [edi],al; se muta in sirul destinatie
            add ebx,3; il adunam pe 3 sa vedem in comparare daca adunat cu 3 indexul este mai mare ca lungimea s1
            cmp ebx,edx
            jnle adauga_el_s2; daca diferenta este mai mica ca 0 se sare la adaugare restului de el
            add esi,3; ne mutam cu 3 pozitii ca stim deja ca ni se permite
            inc edi; parcurgem sirul edi
            loop adauga_el_s1
            adauga_el_s2:
                    inc edi;acum trecem la urmatoare pozitie din edi
                    mov esi,s2;vom muta in registrul esi al doilea sir pentru concatenare
                    repeta:
                    
                    mov ebx,nr_es2; pentru a retine valoare lungimii sirului o salvam in registrul ebx
                    mov al,[esi+ebx];aducem elementul de pe ultima pozitie din esi
                    mov [edi],al;il adaugam in sirul destinatie
                    dec esi;decrementam esi pentru o parcurgere corecta
                    inc edi;trecem la urmatoarea poz din sir
                    loop repeta
                   final:
         push dword 0      
         call  [exit]      
