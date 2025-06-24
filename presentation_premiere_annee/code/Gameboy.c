#include "Gameboy.h"



// types
////////////////////////////

struct gameboy_s {
    cpu sm83;
    u8* rom;
};




// fonctions
////////////////////////////

gameboy init_gb(){
    gameboy gb = malloc(sizeof(struct gameboy_s));
    assert(gb != NULL);
    gb->sm83 = init_cpu();
    gb->rom = malloc(ROM_SIZE_MAX*(sizeof(u8)));
    assert(gb->rom != NULL);
    return gb;
}



u8* get_rom(gameboy gb){
    assert(gb != NULL);
    return gb->rom;
}

cpu get_sm83(gameboy gb){
    assert(gb != NULL);
    return gb->sm83;
}

void free_gb(gameboy gb){
    if(gb != NULL){
        free_cpu(gb->sm83);
        free(gb->rom);
        free(gb);
    }
}

void emulate_cycle(gameboy gb) {
    uint16_t pc = get_PC(gb->sm83);
    uint8_t opcode = gb->rom[pc];
    printf("Opcode 0x%02X a 0x%04X\n", opcode, pc);

    set_PC(gb->sm83, get_PC(gb->sm83) + 1);
}




void load_rom(gameboy gb, const char* filename) {
    assert(gb != NULL);
    
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Erreur ouverture ROM");
        exit(1);
    }

    u8* rom = get_rom(gb);

    size_t read = fread(rom, 1, ROM_SIZE_MAX, file);
    fclose(file);

    if (read == 0) {
        fprintf(stderr, "Erreur : ROM vide\n");
        exit(1);
    }

    printf("ROM chargee (%zu octets)\n", read);
}