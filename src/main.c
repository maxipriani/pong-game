#include "init.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    SDLResources resources;

    if (init_game(&resources) != 0) {
        SDL_Quit();
        return -1;
    }

    SDL_Delay(5000);

    SDL_cleanup(&resources);
    return 0;
}