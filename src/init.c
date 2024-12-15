#include <stdio.h>
#include "init.h"

static void print_SDL_error(const char *message) {
    fprintf(stderr, "%s: %s\n", message, SDL_GetError());
}

int SDL_init(SDLResources *resources) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        print_SDL_error("Error initializing SDL");
        return -1;
    }

    // if (TTF_Init() == -1) {
    //     print_SDL_error("Error initializing SDL_ttf");
    //     return -1;
    // }

    return 0;
}

int window_init(SDLResources *resources) {

    resources->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (!resources->window) {
        print_SDL_error("Failed to create window");
        return -1;
    }

    return 0;
}

int render_init(SDLResources *resources) {

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    resources->renderer = SDL_CreateRenderer(resources->window, -1, render_flags);

    if (!resources->renderer) {
        print_SDL_error("Error initializing renderer");
        return -1;
    }

    SDL_SetRenderDrawColor(resources->renderer, 0, 0, 0, 255);
    SDL_RenderClear(resources->renderer);

    return 0;
}

// int load_font(SDLResources *resources) {

//     resources->font = TTF_OpenFont(FONT_PATH, FONT_SIZE);

//     if (!resources->font) {
//         print_SDL_error("Error loading font");
//         return -1;
//     }

//     return 0;
// }

void SDL_cleanup(SDLResources *resources) {
    // if (resources->font) {
    //     TTF_CloseFont(resources->font);
    //     resources->font = NULL;
    // }

    if (resources->renderer) {
        SDL_DestroyRenderer(resources->renderer);
        resources->renderer = NULL;
    }

    if (resources->window) {
        SDL_DestroyWindow(resources->window);
        resources->window = NULL;
    }

    // TTF_Quit();
    SDL_Quit();
}

int game_init(SDLResources *resources) {
    resources->window = NULL;
    resources->renderer = NULL;
    // resources->font = NULL;

    if (SDL_init(resources) != 0)
        return -1;

    if (window_init(resources) != 0) {
        SDL_cleanup(resources);
        return -1;
    }

    if (render_init(resources) != 0) {
        SDL_cleanup(resources);
        return -1;
    }

    // if (load_font(resources) != 0) {
    //     SDL_cleanup(resources);
    //     return -1;
    // }

    return 0;
}
