BITS 32
start:
	mov eax,0x0
	mov ecx,0x2
	mov edx,0x4
	add al,cl
	add ax,cx
	add eax,ecx
	add cl,ah
	add eax,0x1
	add eax,ecx
	add eax,edx
	add cl,0x02
	add al,0x04
	add al,cl
	ret
