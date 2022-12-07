bits 32 
global start        

extern exit              
import exit msvcrt.dll  
import fopen msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
extern fopen ,printf
import fscanf msvcrt.dll
extern fprintf ,fread,fclose,fscanf
segment data use32 class=data
    nume_fisier db "num.asm",0
    mod_acces db "r",0
    descriptor_fisier dd -1
    len equ 100
    nr times len dd 0
    numbers times len dd 0
    mod_accesr db "a",0
    min dd 0
    formats dd "%d",0
    format db " %d",0
    mod_accesa db "a", 0
; our code starts here
segment code use32 class=code
;Se da un fisier text. Fisierul contine numere (in baza 10) separate prin spatii. Sa se citeasca continutul acestui fisier, sa se determine minimul numerelor citite si sa se scrie rezultatul la sfarsitul fisierului.
    start:
  
        
        ;deschidere fisier
        ;eax=fopen(nume_fisier,mod acces)
        mov ebx,0; ebx va fi folosit pentru salvarea minimului
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp,4*2; refaci stiva
        mov [descriptor_fisier],eax;salvam valoarea returnata in eax care reprezinta descriptorul
        cmp eax,0; verifici daca s-a citit corect fisierului
        je final; daca nu iesi de tot
        ;citim primul numar pentru a initializa minimul
        ;fscanf(descriptor_fisier, format, variabila/e)=0 sau 1 in eax. 1 daca citeste din fisier corect formatul si 0 daca nu mai are ce citi
        push dword nr
        push dword formats
        push dword [descriptor_fisier]
        call [fscanf]
        add esp, 4*3; 
        mov ebx,[nr]    ;scanat primul numar
        cmp eax,0; vedem daca l-a citit corect
        je final
        ; daca nu mai e nimic de citit plec la final
        ;finalu e jos unde se printeaza ca daca e doar un element pai inseamna ca e singurul din fisier deci min
        repeta:;in bucla citim pe rand fiecare numar
            push dword nr
            push dword formats
            push dword [descriptor_fisier]
            call [fscanf]
            add esp, 4*3; citim fiecare numar din fisier si refacem stiva
            cmp ebx,[nr]; verifici daca numarul nu este mai mare ca nr . daca el este mai mare nu se face saltul se OF=0 daca nu ne-a dat un nr mai mic ca 0 si of=1 deci sari
            jng sari
               mov ebx,[nr]; se schimba minimul
                sari:
        cmp eax,1; se compara sa vedem daca mai avem de citit. daca sunt egale atunci da mai avem daca nu nu se mai se executa repeta
         je repeta
        final:
        push dword mod_accesa
        push dword nume_fisier
        call [fopen]
        add esp,4*2; deschidem fisierul pentru APPEND! pe care il facem cu fprintf
        push dword ebx
        push dword format
        push dword eax
        call [fprintf]
        add esp,4*2; s-a scris nr in fisier :)
        
        
            
        

        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
