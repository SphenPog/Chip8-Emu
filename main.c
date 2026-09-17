#include <SDL2/SDL.h>
#include "ROM.h"
#include "cpu.h"

int SDLCALL chip_run_emu(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    return chip_run_emu(argc, argv);
}

int SDLCALL chip_run_emu(int argc, char *argv[])
{

    load_rom("./Coin Flipping [Carmelo Cortez, 1978].ch8");
    // print_memory();
    // reset_cpu();

    SDL_Window *win;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {

        printf("SDL_Init failed");
        return 1;
    }

    win = SDL_CreateWindow("Hello", 0, 0, 640, 480, 0);

    reset_cpu();
    fetch_instruction();
    execute_instruction();

    SDL_Delay(3000);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}