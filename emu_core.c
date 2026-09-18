#include <stdint.h>
#include <stdbool.h>
#include "emu_core.h"
#include "ROM.h"
#include "cpu.h"

uint32_t core_clock_counter = 0;
bool core_quit_requested = false;

int core_init(){
    if (!load_rom("./Coin Flipping [Carmelo Cortez, 1978].ch8"))
    {
        return -1;
    }
    return 0;
};

void core_run(){
    reset_cpu();
    //temp
    //print_memory();
    while (!core_quit_requested)
    {
        fetch_instruction();
        if(!execute_instruction()){
            core_quit_requested = true;
            printf("core quit reached.\n");
        }
    }
};

void core_stop(){

};

void core_advance_cpu_clocks(uint8_t clocks){
    core_clock_counter += clocks;
};