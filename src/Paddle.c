#include "../includes/Ball.h"
#include "../includes/Paddle.h"

void constrain_paddle_position(Paddle *paddle) {
    if (paddle->rectangle.y <= 0) {
        paddle->rectangle.y = 0;
    }
    if (paddle->rectangle.y + paddle->rectangle.h >= WINDOW_HEIGHT) {
        paddle->rectangle.y = WINDOW_HEIGHT - paddle->rectangle.h;
    }
}

void cpu_logic(Paddle *cpu, Ball *ball) {
    const int SCREEN_CENTER = WINDOW_HEIGHT / 2;

    if (ball->rectangle.x > CPU_ACTIVATION_ZONE) {
        if (ball->rectangle.y >= cpu->rectangle.y) {
            cpu->rectangle.y += CPU_SPEED;
        } else if (ball->rectangle.y <= cpu->rectangle.y + cpu->rectangle.h) {
            cpu->rectangle.y -= CPU_SPEED;
        }
    } else {
        float paddle_center = cpu->rectangle.y + (cpu->rectangle.h / 2);

        if (paddle_center > SCREEN_CENTER + CPU_REST_MARGIN) {
            cpu->rectangle.y -= CPU_SPEED;
        } else if (paddle_center < SCREEN_CENTER - CPU_REST_MARGIN) {
            cpu->rectangle.y += CPU_SPEED;
        }
    }

    constrain_paddle_position(cpu);
}

void player_logic(Paddle *player) {
    if (player->controls[0] && !player->controls[1]) {
        player->rectangle.y -= PLAYER_SPEED;
    }
    if (player->controls[1] && !player->controls[0]) {
        player->rectangle.y += PLAYER_SPEED;
    }

    constrain_paddle_position(player);
}