#ifndef __GAMEBOY_H__
#define __GAMEBOY_H__

#define ROM_SIZE_MAX 0x8000 



// Inclusions
////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "../SoC/SoC.h"


// Types
////////////////////////////

typedef uint8_t u8;
typedef uint16_t u16;


typedef struct gameboy_s* gameboy;




// fonctions
////////////////////////////

gameboy init_gb();

u8* get_rom(gameboy);

cpu get_sm83(gameboy);

void free_gb(gameboy);

void load_rom(gameboy, const char*);

void emulate_cycle(gameboy);


#endif