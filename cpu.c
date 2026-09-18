#include "cpu.h"
#include "memory.h"
#include "cpu_instruction.h"
#include <stdio.h>
#include <stdbool.h>
//temp
#include <stdlib.h>

uint8_t registers[16];
uint8_t memory[4096]; // 4kb ram memory
uint16_t indexReg;    // index register
uint16_t pc = 0x200;  // program counter
uint16_t stack[16];
uint8_t sp; // stack pointer
uint8_t delayTimer;
uint8_t soundTimer;
uint8_t keypad[16];
uint32_t video[64 * 32];
uint16_t opcode = 0; // instruction

void *cpu_current_instruction_execute = NULL;
uint32_t cpu_instruction_counter = 0;

uint8_t fonts[80] = {0xF0, 0x90, 0x90, 0x90, 0xF0, //0
                     0x20, 0x60, 0x20, 0x20, 0x70, //1
                     0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
                     0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
                     0x90, 0x90, 0xF0, 0x10, 0x10, //4
                     0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
                     0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
                     0xF0, 0x10, 0x20, 0x40, 0x40, //7
                     0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
                     0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
                     0xF0, 0x90, 0xF0, 0x90, 0x90, //A
                     0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
                     0xF0, 0x80, 0x80, 0x80, 0xF0, //C
                     0xE0, 0x90, 0x90, 0x90, 0xE0, //E
                     0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};

void load_into_memory(const uint8_t *buffer, size_t size)
{
    memcpy(memory + 0x200, buffer, size);
}

void print_memory()
{
    printf("Current working memory: \n");
    printf("---------------------------\n");
    for (size_t i = 0; i < 4096; i++)
    {   
        printf("%02X ", memory[i]);
    }
    printf("\n---------------------------\n");

    return;
}

void reset_cpu()
{
    //load fonts
    memcpy(memory + 0x50, fonts, 80);   
}

void fetch_instruction()
{
    printf("Accessing memory at %u.", pc);
    opcode = (memory[pc] << 8 | memory[pc + 1]);
    printf(" value is %2X.\n", opcode);
    pc += 2;
    chip_cpu_instruction instruction = getInstruction(opcode);
    cpu_current_instruction_execute = instruction.execute;
}

bool execute_instruction()
{
    if(!cpu_current_instruction_execute) {
        chip_cpu_instruction instruction = getInstruction(opcode);
        printf("opcode: %u\n", opcode);
        printf("Unknown instruction at: 0x%2X (%s), count %i\n", pc, instruction.disassemply, cpu_instruction_counter);
        return false;
    }
    ((cpu_execute_op)cpu_current_instruction_execute)();
    return true;
}

/* ------------------------------
    instruction implementations
   ------------------------------ */
void test() {
    printf("reached the test instruction execution.\nexiting...\n");
    exit(EXIT_FAILURE);
}

void clear_screen(){

}