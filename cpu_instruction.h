#pragma once
#include <stdint.h>

struct cpu_instruction
{
    const char *disassemply;
    uint_8_t operand_length;
    void *execute;
};

extern const cpu_instruction instructions[35];