#ifndef BALL_H_
#define BALL_H_

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define BALL_SIZE 15
#define BALL_SPEED 10
#define BALL_SPAWN_X ((WINDOW_WIDTH / 2) - (BALL_SIZE / 2))
#define BALL_SPAWN_Y ((WINDOW_HEIGHT / 2) - (BALL_SIZE / 2))

typedef struct {
    SDL_Rect rectangle;
    float vel_x;
    float vel_y;
} Ball;

#include "Paddle.h"

void ball_logic(Ball *ball, Paddle *player, Paddle *cpu);

#endif