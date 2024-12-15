#ifndef PADDLE_H_
#define PADDLE_H_

#include <SDL2/SDL.h>
#include "Ball.h"

#define PLAYER_SPEED 15
#define CPU_SPEED 10
#define CPU_ACTIVATION_ZONE (WINDOW_WIDTH - WINDOW_WIDTH / 2)
#define CPU_REST_MARGIN 10

typedef struct {
    SDL_Rect rectangle;
    int score;
    int controls[2];
} Paddle;

void cpu_logic(Paddle *cpu, Ball *ball);
void player_logic(Paddle *player);

void constrain_paddle_position(Paddle *paddle);

#endif