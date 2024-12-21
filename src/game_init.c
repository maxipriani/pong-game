#include "../include/game_init.h"
#include <stdio.h>

void ball_init(Ball *ball) {

    ball->rectangle.x = BALL_SPAWN_X;
    ball->rectangle.y = BALL_SPAWN_Y;
    ball->rectangle.w = BALL_SIZE;
    ball->rectangle.h = BALL_SIZE;
    ball->vel_x = BALL_SPEED;
    ball->vel_y = 0;
}

void player_init(Paddle *player) {
    player->rectangle.x = 50;
    player->rectangle.y = (WINDOW_HEIGHT - 100 / 2);
    player->rectangle.w = 20;
    player->rectangle.h = 100;

    player->score = 0;

    player->controls[0] = 0;
    player->controls[1] = 0;
}

void cpu_init(Paddle *cpu) {
    cpu->rectangle.x = WINDOW_WIDTH - 70;
    cpu->rectangle.y = (WINDOW_HEIGHT - 100 / 2);
    cpu->rectangle.w = 20;
    cpu->rectangle.h = 100;

    cpu->score = 0;

    cpu->controls[0] = 0;
    cpu->controls[1] = 0;
}
