#include<stdio.h>
#include<stdint.h>
#define MEMORY_SIZE 1024
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
