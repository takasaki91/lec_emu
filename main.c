#include<stdio.h>
#include<stdint.h>
#define MEMORY_SIZE 1024
uint32_t get_code8(Emulator* emu,int index);
int32_t get_sign_code8(Emulator*emu, int index);
uint32_t get_code32(Emulator* emu, int index);
void mov_r32_imm32(Emulator* emu);
void short_jump(Emulator* emu);
typedef void instructions_fuct_t(Emulator*);
instructions_fuct_t* instructions[256];
void init_instructions()
{
    memset(instructions,0,sizeof(instructions));
    for(int i = 0;i < 8;i++)
    {
        instructions[0xB8 + i] = mov_r32_imm32;
    }
    instructions[0xEB] = short_jump;
}
enum {
    EAX,
    EBX,
    ECX,
    EDX,
    ESP,
    EBP,
    REGISTERS_COUNT,
};
typedef struct {
    uint32_t registers[REGISTERS_COUNT];
    uint32_t eflags;
    uint8_t* memory;
    uint32_t eip;
} Emulator;

Emulator* create_emu(size_t size, uint32_t eip,uint32_t esp){
    Emulator* emu = malloc(sizeof(Emulator));
    emu->memory = malloc(size);
    memset(emu->registers, 0,sizeof(emu->registers));
    emu->eip = eip;
    emu->registers[ESP] = esp;
    return emu;
}
void destroy_emu(Emulator* emu)
{
    free(emu->memory);
    free(emu);
}
int main(int argc, char*argv[])
{
    FILE* binary;
    Emulator* emu;
    if(argc != 2)
    {
        printf("Usage: myemu filename\n");
        return 1;
    }
    emu = create_emu(MEMORY_SIZE,0x0000,0x7c00);
    binary = fopen(argv[1],"rb");
    if(binary == NULL)
    {
        printf("%sファイルは開けませんでした\n",argv[1]);
        return 1;
    }
    freed(emu->memory,1, 0x200,binary);
    fclose(binary);
    destroy_emu(emu);
    return 0;
}
uint32_t get_code8(Emulator* emu,int index)
{
    return emu->memory[emu->eip + index];
}
int32_t get_sign_code8(Emulator*emu, int index)
{
    return (int8_t)emu->memory[emu->eip + index];
}
uint32_t get_code32(Emulator* emu, int index)
{
    int i;
    uint32_t ret = 0;
    for(i = 0; i < 4; i++)
    {
        ret |= get_code8(emu,index+i) <<(i**8);
    }
    return ret;
}
void mov_r32_imm32(Emulator* emu)
{
    uint8_t reg = get_code8(emu,0) - 0xB8;
    uint32_t value = get_code32(emu,01);
    emu->registers[reg] = value;
    emu->eip += 5;
}
void short_jump(Emulator* emu){
    int8_t diff = get_code8(emu,1);
    emu->eip += (diff+2);
}
