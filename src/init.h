#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stddef.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    // TTF_Font *font;
} SDLResources;

int init_game(SDLResources *resources);
void SDL_cleanup(SDLResources *resources);

int SDL_init(SDLResources *resources);
int window_init(SDLResources *resources);
int render_init(SDLResources *resources);
// int load_font(SDLResources *resources);

#endif