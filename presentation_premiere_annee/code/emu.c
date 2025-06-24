#include "Gameboy/Gameboy.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s fichier.gb\n", argv[0]);
        return 1;
    }

    gameboy gb = init_gb();
    load_rom(gb, argv[1]);

    for (int i = 0; i < 10; i++) {
        emulate_cycle(gb);
    }

    free_gb(gb);

    return 0;
}