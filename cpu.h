#include "memory.h"
#include <stdint.h>

#ifndef CPU_H
#define CPU_H

extern uint8_t registers[16];
extern uint8_t memory[4096]; // 4kb ram memory
extern uint16_t indexReg;    // index register
extern uint16_t pc;          // program counter
extern uint16_t stack[16];
extern uint8_t sp; // stack pointer
extern uint8_t delayTimer;
extern uint8_t soundTimer;
extern uint8_t keypad[16];
extern uint32_t video[64 * 32];
extern uint16_t opcode; // instruction

void load_into_memory(const uint8_t *buffer, size_t size);

void print_memory();

void reset_cpu(); // set default values (register addresses/fonts)

void fetch_instruction();

void execute_instruction();

typedef void (*cpu_execute_op)(void);

//instructions
void clear_screen();

#endif