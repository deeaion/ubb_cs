bits 32
global main

section .data
	a times 4 db 0
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

	mov eax, 2
	imul eax, [a]
	push eax
	mov eax, [a]
	imul eax, [a]
	pop ebx
	add eax, ebx
	push eax
	mov eax, 10
	pop ebx
	add eax, ebx
	push dword eax
	push dword format
	call printf
	add esp, 8

	mov eax, [a]
	push eax
	mov eax, 2
	imul eax, [a]
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	imul eax, [a]
	imul eax, 2
	pop ebx
	add eax, ebx
	push dword eax
	push dword format
	call printf
	add esp, 8

	push dword 0
	call exit
