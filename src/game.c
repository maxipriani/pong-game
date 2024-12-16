#include "../includes/game.h"
#include <stdio.h>

void redraw_screen(SDLResources *resources, Paddle *player, Paddle *cpu, Ball *ball) {
    SDL_SetRenderDrawColor(resources->renderer, 0, 0, 0, 255);
    SDL_RenderClear(resources->renderer);

    SDL_SetRenderDrawColor(resources->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(resources->renderer, &player->rectangle);
    SDL_RenderFillRect(resources->renderer, &cpu->rectangle);
    SDL_RenderFillRect(resources->renderer, &ball->rectangle);

    SDL_RenderDrawLine(resources->renderer, WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);

    SDL_RenderPresent(resources->renderer);

    SDL_Delay(1000 / 60);
}

void event_handler(SDL_Event event, Paddle *player, int *running) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *running = 0;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    *running = 0;
                    break;
                case SDLK_w:
                    player->controls[0] = 1;
                    break;
                case SDLK_s:
                    player->controls[1] = 1;
                    break;
            }
        }
        if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    player->controls[0] = 0;
                    break;
                case SDLK_s:
                    player->controls[1] = 0;
                    break;
            }
        }
    }
}

void game_loop(SDLResources *resources, Paddle *player, Paddle *cpu, Ball *ball) {
    SDL_Event event;
    int running = 1;

    while (running) {
        event_handler(event, player, &running);
        player_logic(player);
        cpu_logic(cpu, ball);
        ball_logic(ball, player, cpu);
        redraw_screen(resources, player, cpu, ball);
    }
}