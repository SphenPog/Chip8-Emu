#include <SDL2/SDL.h>
#include "ROM.h"

int main()
{

    load_rom("./Coin Flipping [Carmelo Cortez, 1978].ch8");
    // print_memory();
    // reset_cpu();

    /*
    SDL_Window *win;
    if (SDL_Init(SDL_INIT_VIDEO) != SDL_TRUE)
    {
        win = SDL_CreateWindow("Hello", 0, 0, 640, 480, 0);
        SDL_Delay(3000);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 0;
    }
        */
    return 1;
}