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

	mov eax, [a]
	mov ebx, 2
	imul eax, ebx
	mov ebx, 6
	add eax, ebx
	mov [b], eax
	

	mov eax, [b]
	push dword eax
	push dword format
	call printf
	add esp, 8

	push dword 0
	call exit
