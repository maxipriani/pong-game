#ifndef GAME_H_
#define GAME_H_

#include "ball.h"
#include "paddle.h"
#include "init.h"

void redraw_screen(SDLResources *resources, Paddle *player, Paddle *cpu, Ball *ball);
void event_handler(SDL_Event event, Paddle *player, int *running);
void game_loop(SDLResources *resources, Paddle *player, Paddle *cpu, Ball *ball);

#endif
