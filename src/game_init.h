#ifndef GAME_INIT_H_
#define GAME_INIT_H_

#include "Ball.h"
#include "Paddle.h"

void ball_init(Ball *ball);
void player_init(Paddle *paddle);
void cpu_init(Paddle *paddle);

#endif