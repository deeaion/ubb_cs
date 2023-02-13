bits 32 
global  start 
extern  exit 
import  exit msvcrt.dll
segment  data use32 class=data ; segmentul de date in care se vor defini variabilele 
	a  db 10
	b  dw 40
segment  code use32 class=code ; segmentul de cod
start: 
	mov  AX, [b] ;AX = b
	div  BYTE [a] ;AL = AX / a = b / a și AH = AX % a = b % a
	
	mov  AH, 2 ;AH = 2
	mul  AH ;AX = AL * AH = b / a * 2	
	
	add  AX, 10 ;AX = AX + b = b / a * 2 + 10
	
	mul  word [b] ;DX:AX = AX * b = (b / a * 2 + 10) * b
	
	push  DX ;se pune pe stiva partea high din double word-ul DX:AX
	push  AX ;se pune pe stiva partea low din double word-ul DX:AX
	pop  EBX ;EBX = DX:AX = (b / a * 2 + 10) * b
	
	mov  AX, [b] ;AX = b
	mov  DX, 15 ;DX = 15
	mul  DX ;DX:AX = b * 15
	
	push  DX ;se pune pe stiva partea high din double word-ul DX:AX
	push  AX ;se pune pe stiva partea low din double word-ul DX:AX
	pop  EAX ;EAX = DX:AX = b * 15
	
	sub  EBX, EAX ;EBX = EBX - EAX = (b / a * 2 + 10) * b - b * 15
	
	push   dword 0 ;se pune pe stiva codul de retur al functiei exit
	call   [exit] ;apelul functiei sistem exit pentru terminarea executiei programului	