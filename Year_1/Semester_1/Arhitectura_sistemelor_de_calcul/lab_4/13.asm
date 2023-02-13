bits 32 
global start        
extern exit               
import exit msvcrt.dll    
;Dandu-se 4 octeti, sa se obtina in AX suma numerelor intregi reprezentate de bitii 4-6 ai celor 4 octeti.
segment data use32 class=data
    a db 10001111b
    b db 01110101b
    c db 10000001b
    d db 01010000b    
segment code use32 class=code
    start:
        ;Vom retine in cl cat ne trebuie pt masca . Pentru cei 4-6 octeti avem : 01110000b. Doua cate doua voi adauga in
        ;bx si dx variabilele . nu vom folosi ax pentru a face adaugarea acolo. ar putea fi folosit si el.
        ;cx nu il folosim pentru ca acolo avem masca
        mov cl,01110000b
        mov bl,[a];bl=a
        and bl,cl;am retinut doar bitii 4-6 restul sunt zero
        ror bl,4; rotim bitii spre dreapta a lui bl ca sa putem extrage valoarea dintre bitii 4-6
        mov bh,0; ii mutam in bx pentru adunare
        ;;;;;;;;;;;;;;;;
        mov dl,[b];dl=b
        and dl,cl;am retinut doar bitii 4-6 restul sunt zero
        ror dl,4; rotim bitii spre dreapta a lui dl ca sa putem extrage valoarea dintre bitii 4-6
        mov dh,0; ii mutam in dx pentru adunare
        mov AX,0;pentru a ma asigura ca e gol nu cred ca este necesar
        add ax,bx;ax=(4-6)a
        add ax,dx;ax=(4-6)a+)+(4-6)b
        ;;;;;;;;;;;;;;;;;;
        mov bl,[c];bl=c
        and bl,cl;am retinut doar bitii 4-6 restul sunt zero
        ror bl,4; rotim bitii spre dreapta a lui bl ca sa putem extrage valoarea dintre bitii 4-6
        mov bh,0; ii mutam in bx pentru adunare
        ;;;;;;;;;;;;;;;;
        mov dl,[d];dl=d
        and dl,cl;am retinut doar bitii 4-6 restul sunt zero
        ror dl,4; rotim bitii spre dreapta a lui dl ca sa putem extrage valoarea dintre bitii 4-6
        mov dh,0; ii mutam in dx pentru adunare
        add ax,bx;ax=(4-6)a+)+(4-6)b+(4-6)c
        add ax,dx;ax=(4-6)a+)+(4-6)b+(4-6)c+(4-6)d
        
        push    dword 0      
        call    [exit]       
