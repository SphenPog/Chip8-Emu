#pragma once
#include <stdint.h>

struct chip_cpu_instruction {
    const char *disassemply;
    uint8_t operand_length;
    void *execute;
};

const struct chip_cpu_instruction instructions[35];