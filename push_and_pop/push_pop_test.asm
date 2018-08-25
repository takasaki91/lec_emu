BITS 32
start:
	mov eax,0x1
	mov ecx,eax
	mov edx,eax
	mov ebx,eax
	push eax
	push ecx
	push edx
	push ebx
	pusha
	pushad
	push 0x12345
	push 0x12
	pop eax
	pop eax
	popad
	popa
	pop ebx
	pop edx
	pop ecx
	pop eax
	ret
	
	
