BITS 32
start:
	mov al, 0x01
	mov cl, 0x02
	mov dl, 0x03
	mov bl, 0x04
	mov ah, 0x01
	mov ch, 0x02
	mov dh, 0x03
	mov bh, 0x04
	mov ax, 0x01
	mov cx, 0x02
	mov dx, 0x03
	mov bx, 0x04
	mov eax, 0x01234567
	mov ecx, 0x12345678
	mov edx, 0x23456789
	mov ebx, 0x3456789a
	mov esp, 0x456789ab
	mov ebp, 0x56789abc
	mov esi, 0x6789abcd
	mov edi, 0x789abcde
	mov eax,ecx
	mov eax,edx
	mov eax,ebx
	mov eax,esp
	mov eax,ebp
	mov eax,esi
	mov eax,edi
	jmp short start
