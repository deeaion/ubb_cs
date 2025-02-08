bits 32
global main

section .data
	a times 4 db 0
	b times 4 db 0
	format db "%d", 0
	endl db 0Ah, 0
section .text
extern exit
extern scanf
extern printf
main:
	push dword a
	push dword format
	call scanf
	add esp, 8

	mov ebx, [a]
	mov eax, 2
	cmp ebx, eax
	jne L0
	mov eax, [a]
	imul eax, 2
	push eax
	mov eax, 5
	pop ebx
	add eax, ebx
	mov [b], eax
	jmp L1
	L0:
	

	mov eax, 5
	mov [b], eax
	

	L1:
	mov eax, [b]
	push dword eax
	push dword format
	call printf
	add esp, 8

	push dword 0
	call exit
