#include <stdio.h>
#include "cpu_instruction.h"
#include "cpu.h"

const struct chip_cpu_instruction instructions[35] = {
    { "0NNN", 0, clear_screen},  //0x00
    { "00E0", 0, },  //0x00
    { "00EE", 0, },  //0x00
    { "1NNN", 0, },  //0x01
    { "2NNN", 0, },  //0x02
    { "3XNN", 0, },  //0x03
    { "4XNN", 0, },  //0x04
    { "5XY0", 0, },  //0x05
    { "6XNN", 0, },  //0x06
    { "7XNN", 0, },  //
    { "8XY0", 0, },  //
    { "8XY1", 0, },  //
    { "8XY2", 0, },  //
    { "8XY3", 0, },  //
    { "8XY4", 0, },  //
    { "8XY5", 0, },  //
    { "8XY6", 0, },  //
    { "8XY7", 0, },  //
    { "8XYE", 0, },  //
    { "9XY0", 0, },  //
    { "ANNN", 0, },  //
    { "BNNN", 0, },  //
    { "CXNN", 0, },  //
    { "DXYN", 0, },  //  
    { "EX9E", 0, },  //
    { "EXA1", 0, },  //
    { "FX07", 0, },   //
    { "FX0A", 0, },   //
    { "FX15", 0, },   //
    { "FX18", 0, },   //
    { "FX1E", 0, },   //
    { "FX29", 0, },   //
    { "FX33", 0, },   //
    { "FX55", 0, },   //
    { "FX65", 0, }   //
};