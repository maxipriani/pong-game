#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include "init.h"
#include "Ball.h"
#include "Paddle.h"
#include "game_init.h"
#include "game.h"

int main(int argc, char *argv[]) {
    SDLResources resources;
    init_game(&resources);

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