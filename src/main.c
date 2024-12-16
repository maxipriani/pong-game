#include "../includes/Ball.h"
#include "../includes/Paddle.h"
#include "../includes/game.h"
#include "../includes/game_init.h"
#include "../includes/init.h"
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