#include <stdio.h>
#include "cpu_instruction.h"
#include "cpu.h"

const chip_cpu_instruction instructions[35] = {
    { "0NNN", NULL},  //0
    { "00E0", clear_screen},  //1
    { "00EE", },  //2
    { "1NNN", },  //3
    { "2NNN", },  //4
    { "3XNN", },  //5
    { "4XNN", },  //6
    { "5XY0", },  //7
    { "6XNN", },  //8
    { "7XNN", },  //9
    { "8XY0", },  //10
    { "8XY1", },  //11
    { "8XY2", },  //12
    { "8XY3", },  //13
    { "8XY4", },  //14
    { "8XY5", },  //15
    { "8XY6", },  //16
    { "8XY7", },  //17
    { "8XYE", },  //18
    { "9XY0", },  //19
    { "ANNN", },  //20
    { "BNNN", },  //21
    { "CXNN", },  //22
    { "DXYN", },  //23
    { "EX9E", },  //24
    { "EXA1", },  //25
    { "FX07", },  //26
    { "FX0A", },  //27
    { "FX15", },  //28
    { "FX18", },  //29
    { "FX1E", },  //30
    { "FX29", },  //31
    { "FX33", },  //32
    { "FX55", },  //33
    { "FX65", }   //34
};

 chip_cpu_instruction getInstruction(uint16_t opcode){
    uint16_t NN;
    switch (opcode & 0xF000)
    {
    case 0x0000:
        NN = opcode & 0x00FF;

        if (NN == 0x00E0) // clear screen (0x00E0)
        {return instructions[1];}
        else if (NN == 0x00EE) // return from subroutine (0x00EE) 
        {return instructions[2];}
        else //Execute machine language at NNN (0x0NNN) (no need to implement)
        {return instructions[0];} 
    case 0x1000:
        return instructions[3]; //jump to address NNN (0x1NNN)
    case 0x2000:
        return instructions[4]; //execute subroutine at NNN (0x2NNN)
    case 0x3000:
        return instructions[5]; //skip instruction if VX == NN (0x3XNN)
    case 0x4000:
        return instructions[6]; //skip intruction if VX != NN (0x4XNN)
    case 0x5000:
        return instructions[7]; //skip instruction if VX == VY (0x5XY0)
    case 0x6000:
        return instructions[8]; //store number NN in VX (0x6XNN)
    case 0x7000:
        return instructions[9]; //add NN to VX (0x7XNN)
    case 0x8000:
        uint16_t N = opcode & 0x000F;

        switch (N)
        {
        case 0x0000:
            return instructions[10]; //store VY in VX (0x8XY0)
        case 0x0001:
            return instructions[11]; //set VX to VX OR VY (0x8XY1)
        case 0x0002:
            return instructions[12]; //set VX to VX AND VY (0x8XY2)
        case 0x0003:
            return instructions[13]; //set VX to VX XOR VY (0x8XY3)
        case 0x0004:
            return instructions[14]; //VY + VX, set VF to 00 if borrow,
                                     //set VF to 01 if no borrow (0x8XY4)
        case 0x0005:
            return instructions[15]; //VX - VY, set VF to 00 if borrow, 
                                     //set VF to 01 if no borrow (0x8XY5)
        case 0x0006:
            return instructions[16]; //store VY >> 1 into VX, set VF to 00 if borrow, 
                                     //set VF to 01 if no borrow (0x8XY6)
        case 0x0007:
            return instructions[17]; //set VX = VY - VX, set VF to 00 if borrow occurs, 
                                     //set VF to 01 if no borrow (0x8XY7)
        case 0x000E:
            return instructions[18]; //store VY << 1 into VX, 
                                     //set VF to the most significant bit before shift, 
                                     //VY unchanged (0x8XYE)
        }
    case 0x9000:
        return instructions[19]; //skip instruction if VX != VY (0x9XY0)
    case 0xA000:
        return instructions[20]; //store NNN in register I (0xANNN)
    case 0xB000:
        return instructions[21]; //jump to address NNN + V0 (0xBNNN)
    case 0xC000:
        return instructions[22]; //set VX to random number with mask of NN (0xCXNN)
    case 0xD000:
        return instructions[23]; //draw sprite at position VX, VY with N bytes of sprite data,
                                 //starting at address stored in I
                                 //set VF to 01 if any pixels are changed to unset,
                                 //set VF to 00 otherwise (0xDXYN)
    case 0xE000:
            NN = opcode & 0x00FF;

        if (NN == 0x009E) {
            return instructions[24]; //skip instruction if key of hex value in VX is pressed (0xEX9E)
        } else if (NN == 0x00A1) {
            return instructions[25]; //skip instruction if key of hex value in VX is not pressed (0xEXA1)
        }
    case 0xF000:
            NN = opcode & 0x00FF;

        switch (NN)
        {
        case 0x0007:
            return instructions[26]; //store current delay timer value in VX (0xFX07)
        case 0x000A:
            return instructions[27]; //wait for a keypress and store result in VX (0xFX0A)
        case 0x0015:
            return instructions[28]; //set delay timer to value of VX (0xFX15)
        case 0x0018:
            return instructions[29]; //set sound timer to value of VX(0xFX18)
        case 0x001E:
            return instructions[30]; //add value in VX to I (0xFX1E)
        case 0x0029:
            return instructions[31]; //set I to memory address of sprite corresponding to hex value in VX (0xFX29)
        case 0x0033:
            return instructions[32]; //store binary-coded decimal of value VX at I, I+1, and I+2 (0xFX33)
        case 0x0055:
            return instructions[33]; //store V0 to VX (inclusive) in memory starting at address I,
                                     //I is set to I + X + 1 after operation (0xFX55)
        case 0x0065:
            return instructions[34]; //Fill registers V0 to VX (inclusive) with values in memory
                                     //starting at I, I is set to I + X + 1 after operation
        }
    }
};