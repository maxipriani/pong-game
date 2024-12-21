#include "../include/ball.h"
#include "../include/paddle.h"
#include "../include/game.h"
#include "../include/game_init.h"
#include "../include/init.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    SDLResources resources;
    game_init(&resources);

    Ball ball;
    ball_init(&ball);

    Paddle player;
    player_init(&player);

    Paddle cpu;
    cpu_init(&cpu);

    game_loop(&resources, &player, &cpu, &ball);

    SDL_cleanup(&resources);

    return 0;
}