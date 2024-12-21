#include "../include/ball.h"
#include <stdbool.h>
#include <stdio.h>

static void reset_ball(Ball *ball) {
    ball->rectangle.x = BALL_SPAWN_X;
    ball->rectangle.y = BALL_SPAWN_Y;
    ball->vel_x *= -1;
}

bool paddle_hit(Ball *ball, Paddle *paddle) {
    return (ball->rectangle.y + ball->rectangle.h >= paddle->rectangle.y &&
            ball->rectangle.y - ball->rectangle.h <= paddle->rectangle.y + paddle->rectangle.h &&
            ball->rectangle.x + ball->rectangle.w >= paddle->rectangle.x &&
            ball->rectangle.x <= paddle->rectangle.x + paddle->rectangle.w);
}

void ball_logic(Ball *ball, Paddle *player, Paddle *cpu) {

    // Ball movement
    ball->rectangle.x += ball->vel_x;
    ball->rectangle.y += ball->vel_y;

    // CPU Scored (horizontal collisions)
    if (ball->rectangle.x <= 0) {
        reset_ball(ball);
    }
    // Player scored (horizontal collisions)
    if (ball->rectangle.x + ball->rectangle.w >= WINDOW_WIDTH) {
        reset_ball(ball);
    }

    // Vertical collisions
    if (ball->rectangle.y <= 0) {
        ball->rectangle.y = 0;
        ball->vel_y *= -1;
    }
    if (ball->rectangle.y + ball->rectangle.h >= WINDOW_HEIGHT) {
        ball->rectangle.y = WINDOW_HEIGHT - ball->rectangle.h;
        ball->vel_y *= -1;
    }

    // Collision with player's paddle
    if (paddle_hit(ball, player)) {

        ball->rectangle.x = player->rectangle.x + player->rectangle.w;
        ball->vel_x *= -1;

        // Vary angle based on point of impact
        float hit_offset_y = (player->rectangle.y + (player->rectangle.h / 2)) - (ball->rectangle.y + (ball->rectangle.h / 2));
        float normalized_hit_offset_y = hit_offset_y / (player->rectangle.h / 2);
        ball->vel_y = -BALL_SPEED * normalized_hit_offset_y;
    }

    // Collision with CPU's paddle
    if (paddle_hit(ball, cpu)) {

        ball->rectangle.x = cpu->rectangle.x - ball->rectangle.w;
        ball->vel_x *= -1;

        // Vary angle based on point of impact
        float hit_offset_y = (cpu->rectangle.y + (cpu->rectangle.h / 2)) - (ball->rectangle.y + (ball->rectangle.h / 2));
        float normalized_hit_offset_y = hit_offset_y / (cpu->rectangle.h / 2);
        ball->vel_y = -BALL_SPEED * normalized_hit_offset_y;
    }
}