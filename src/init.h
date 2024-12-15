#ifndef INIT_H_
#define INIT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stddef.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Pong"
#define FONT_PATH "assets/fonts/font.ttf"
#define FONT_SIZE 20

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    // TTF_Font *font;
} SDLResources;

int init_game(SDLResources *resources);
void SDL_cleanup(SDLResources *resources);

int game_init(SDLResources *resources);
int SDL_init(SDLResources *resources);
int window_init(SDLResources *resources);
int render_init(SDLResources *resources);
// int load_font(SDLResources *resources);

#endif