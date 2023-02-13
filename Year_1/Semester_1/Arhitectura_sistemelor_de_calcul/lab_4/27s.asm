bits 32 
global start        
extern exit               
import exit msvcrt.dll    
;Se da quadwordul A. Sa se obtina numarul intreg N reprezentat de bitii 35-37 ai lui A. Sa se obtina apoi in B dublucuvantul rezultat prin rotirea spre dreapta a dublucuvantului inferior al lui A cu N pozitii. Sa se obtina octetul C astfel:
;bitii 0-3 ai lui C sunt bitii 8-11 ai lui B
;bitii 4-7 ai lui C sunt bitii 16-19 ai lui B
segment data use32 class=data
   a dq 1010100000010001000000000110100010101000000100010000000001101000b
   c db 0
segment code use32 class=code
    start:
    ;signed
        mov eax,[a]
        mov edx,[a+4];edx:eax=a
        and edx,00000000000000000000000000111000b;        ne trebuiesc bitii 35-37 deci vom lucra doar pe edx si nr va retine doar ce se afla pe bitii 35 si 37
        mov cl,3
        sar edx,cl; obtinem N-ul.
        push edx
        pop bx
        pop cx
        mov cl,bl
        ror eax,cl;se roteste partea low a lui A de N ori si se obtine B
        ;C contine ultimii 8 biti din B adica din EAX. Vom obtine acesti biti printr-o masca
        and eax,00000000000000000000000011111111b
        push eax
        pop ax
        pop dx
        mov cl,al
        mov [c],cl
        ;Acum avem doar octetul C
        
        
        
        push    dword 0      
        call    [exit]       
