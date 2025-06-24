#include "CPU.h"

// types
////////////////////////////

struct cpu_s{
    u8 A;   u8 F;
    u8 B;   u8 C;
    u8 D;   u8 E;
    u8 H;   u8 L;
    u16 SP; u16 PC;
};


// fonctions
////////////////////////////

cpu init_cpu(){
    cpu sm83 = malloc(sizeof(struct cpu_s));
    assert(sm83 != NULL);
    sm83->A = 0x01;     sm83->F = 0xB0;
    sm83->B = 0x00;     sm83->C = 0x13;
    sm83->D = 0x00;     sm83->E = 0xD8;
    sm83->H = 0x01;     sm83->L = 0x4D;
    sm83->SP = 0xFFFE;  sm83->PC = 0x0100;
    return sm83;
}


u8 get_reg(cpu c, mem_empl e){
    assert(c != NULL);
    switch (e) {
        case A:
            return c->A;
        case F:
            return c->F;
        case B:
            return c->B;
        case C:
            return c->C;
        case D:
            return c->D;
        case E:
            return c->E;
        case H:
            return c->H;
        case L:
            return c->L;
        default:
            assert(0);
    }
}









u16 get_SP(cpu c){
    assert(c != NULL);
    return c->SP;
}






u16 get_PC(cpu c){
    assert(c != NULL);
    return c->PC;
}












void set_reg(cpu c, mem_empl e, u8 val){
    assert(c != NULL);
    switch (e) {
        case A:
            c->A = val;
            break;
        case F:
            c->F = val;
            break;
        case B:
            c->B = val;
            break;
        case C:
            c->C = val;
            break;
        case D:
            c->D = val;
            break;
        case E:
            c->E = val;
            break;
        case H:
            c->H = val;
            break;
        case L:
            c->L = val;
            break;
        default:
            assert(0);}}

void set_SP(cpu c, u16 val){
    assert(c != NULL);
    c->SP = val;
}

void set_PC(cpu c, u16 val){
    assert(c != NULL);
    c->PC = val;
}

void free_cpu(cpu sm83){
    if(sm83 != NULL){
        free(sm83);
    }
}