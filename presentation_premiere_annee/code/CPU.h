#ifndef __CPU_H__
#define __CPU_H__

// Inclusions
////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// types
////////////////////////////

typedef uint8_t u8;
typedef uint16_t u16;

typedef struct cpu_s* cpu;

typedef enum{
    A = -10,    F = -9,
    B = -8,     C = -7,
    D = -6,     E = -5,
    H = -4,     L = -3,
    SP = -2,    PC = -1,
} mem_empl ;



// fonctions
////////////////////////////

// constructeur
cpu init_cpu();

// accesseur
u8 get_reg(cpu, mem_empl);

u16 get_SP(cpu);

u16 get_PC(cpu);

// accesseur
void set_reg(cpu, mem_empl, u8);

void set_SP(cpu, u16);

void set_PC(cpu, u16);


// destructeur
void free_cpu(cpu);

#endif