#include <SDL2/SDL.h>
#include "emu_core.h"

int SDLCALL chip_run_emu(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    return chip_run_emu(argc, argv);
}

int SDLCALL chip_run_emu(int argc, char *argv[])
{
    SDL_Window *win;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {

        printf("SDL_Init failed");
        return 1;
    }

    win = SDL_CreateWindow("Hello", 0, 0, 640, 480, 0);
    
    if(core_init() == -1) {
        perror("core failed to initalize");
        return 1;
    }
    core_run();

    SDL_Delay(3000);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}