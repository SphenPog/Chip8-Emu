/*
    loads selected ROM file into CPU memory
*/
#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "cpu.h"

#define MAX_MEMORY_SIZE 0x1000 // 4 KB

const unsigned int START_ADDRESS = 0x200;
extern uint8_t memory[MAX_MEMORY_SIZE];

bool load_rom(char const *filename) {
    FILE *rom_file;

    rom_file = fopen(filename, "r");

    if (rom_file == NULL) {
        perror("Error opening file.");
        return false;
    }

    fseek(rom_file, 0, SEEK_END);
    long size = ftell(rom_file);
    rewind(rom_file);

    if (size > MAX_MEMORY_SIZE)
    {
        perror("File larger then maximum Memory");
        fclose(rom_file);
        return false;
    }
    

    uint8_t *buffer = malloc(size);
    if (!buffer)
    {
        fclose(rom_file);
        perror("Error creating buffer.");
        return false;
    }
    
    size_t n = fread(buffer, 1, size, rom_file);

    if (n != size) {
        fprintf(stderr, "Short read: got %zu of %ld bytes\n", n, size);
        free(buffer);
        fclose(rom_file);
        return false;
    }
    
    load_into_memory(buffer, size);
    free(buffer);
    fclose(rom_file);

    return true;
}

#endif