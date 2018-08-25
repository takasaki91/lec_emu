BITS 32
start:
	mov eax,0x1
	call _add_one
	add eax,0x1
_add_one:
	add eax,0x3
	ret
	
