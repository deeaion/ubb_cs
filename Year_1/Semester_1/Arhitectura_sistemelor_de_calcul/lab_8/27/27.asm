bits 32 
global start        
extern exit              
import exit msvcrt.dll    
segment data use32 class=data
    s dw 3,4,1,5,6,7,5,6,1,5,2
    nr_e equ ($-s)/2
    i_max dd 0
    max dd 0
    d times nr_e dw 0; facem un sir de lungime maxima
; our code starts here
segment code use32 class=code
    start:
     ;Un sir de cuvinte dword sa se calc cel mai lung subsird de cuvinte ordonate crescator din acest sir
     mov esi,s;mutam sirul de cuvinte pentru prelucrare
     mov ecx,nr_e; nr de el
     jecxz final
     mov ebx,0;el va fi indicele din sir
     mov edx,1;maximul fiecarui subsir testat
     cld
     lodsw;incarcam in ax primul word
     inc ebx
     repeta:
        cmp ax,[esi];comparam pe ax unde ne aflam in sir cu urmatorul
        jng nu_schimba; daca nu e mai mare vom parcurge normal sirul 
                cmp [max],edx; daca maximul este mai mare vom sari peste modificarea lui si doar vom face un max nou mai mic; daca nu muta max n in max si i max in i max
                jg nu_e_nevoie
                mov [max],edx
                mov [i_max],ebx;retine urmatorul dupa cuvantul dat; pentru indicele dorit facem i_max-max
                nu_e_nevoie: 
                 mov edx,0;schimbam maximul din nou 
                 
        nu_schimba:
        inc ebx;deoarece eu voi creste dupa pana ajung la poz dorita retin doar 1 cu 1
        inc edx;incrementam maximul
        
                
        lodsw
                
         loop repeta            
     mov edx,[max]; nr de elemente din 
     mov ebx,[i_max]
     sub ebx,[max]; cat trebuie sa ne mutam in sir ca sa ajungem la pozitia de unde luam sirul
     ;am aflat cele doua acum putem sa ne mutam la poz de unde luam elementele din sir
     mov esi,s;mutam din nou sirul in esi
     ;nu ne trebuie nr elemente din el dar vom face ca ecx ul sa fie nr de elemente de cat tre sa ne mutam
     mov ecx,ebx
     ;parcurgem sirul pana la pozitia dorita
     muta:
        add esi,2
     loop muta
     cld
     mov ecx,edx; de data asta o vom face de max ori deci pentru loop si pentru lungimea sirului efectiva o declaram aici
     mov edi,d
     adauga_in_sir:
            lodsw
            stosw
     loop adauga_in_sir
     
            
     final:
         push    dword 0      
         call    [exit]      
