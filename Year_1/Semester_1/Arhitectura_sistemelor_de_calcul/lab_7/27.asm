bits 32 
global start        
extern exit              
import exit msvcrt.dll    
segment data use32 class=data
    S1 db 1,3,6,2,3,2
    nr_e equ $-S1; se determina lungimea s1 pe care o au si s2 si sirul destinatie d
    S2 db 6,3,8,1,2,5
    d times nr_e db 0; se creeaza un sir cu nr_e elemente pe care le initializam cu 0
    ;rez: d : -5 0 -2 1 1 -3

; our code starts here
segment code use32 class=code
    start:
        ;Se dau 2 siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel incat fiecare element din D sa reprezinte diferenta dintre elementele de pe pozitiile corespunzatoare din S1 si S2.
        mov esi,S1;        vom adauga in esi pe s1 pentru a aduna intai fiecare element din s1 in sirul destinatie
        mov ebx,S2; adaugam si pe s2 in esi pentru a face scaderea dintre cele doua
        mov ecx,nr_e; initializam ecx cu nr_e pentru a utiliza instructiunea loop
        mov edi,d; adaugam in edi sirul destinatie
        jecxz final ; daca sirurile date sunt de lungimea 0 atunci nu avem nimic de schimbat in sirul destinatie care este de astfel vid. Vom face jump la final.
        creeare_d:
             mov al,[esi];il adaugam la al pe octetul de la adresa esi
             sub al,[ebx];scadem octetul de la adresa cu acelasi index a sirului s2
             mov [edi],al; adaugam valoarea obtinuta la sirul edi
             inc esi
             inc ebx
             inc edi; se incrementeaza toate pentru a merge pe acelasi index
        loop creeare_d
        
                    final:
         push    dword 0      
         call    [exit]      
