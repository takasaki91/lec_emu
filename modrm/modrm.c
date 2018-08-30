typedef struct {
	uint8_t mod;
	union {
		uint8_t opcode;
		uint8_t reg_index;
	};
	uint8_t rm;
	uint8_t sib;
	union {
		int8_t disp8;
		uint32_t disp32;
	}
} ModRM;
static char* registers_name[] = {EAX,ECX,EDX,EBX,ESP,EBP,EDI,ESI,EIP,REGISTER_COUNT}

void parce_modrm(Emulater* emu, ModRM* modrm)
{
	uint8_t code;
	code = get_code8(emu);
	modrm.mod = (code & 0xc0) >> 6;
	modrm.opcode = (code & 0x38) >> 3;
	modrm.rm = code & 0x07;
	emu->eip += 1;
	if(modrm.mod == 1){
	}
	if(modrm.mod == 0){
	}
}	
