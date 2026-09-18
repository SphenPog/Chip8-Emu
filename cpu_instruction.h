#pragma once
#include <stdint.h>

#ifndef CPU_INSTRUCTION_H
#define CPU_INSTRUCTION_H

typedef struct 
{
    const char *disassemply;
    void *execute;
} chip_cpu_instruction;

extern const chip_cpu_instruction instructions[35];

chip_cpu_instruction getInstruction(uint16_t opcode);

#endif