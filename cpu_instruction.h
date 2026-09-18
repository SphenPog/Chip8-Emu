#pragma once
#include <stdint.h>

struct chip_cpu_instruction {
    const char *disassemply;
    void *execute;
};

const struct chip_cpu_instruction instructions[35];

struct chip_cpu_instruction getInstruction(uint16_t opcode);