#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include "src/runtime.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, const char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow( "Try", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_FULLSCREEN );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    initEngine();
    Uint32 frameStart;
    Uint32 frameTime;
    Uint32 frameEnd;
    float deltaTime;

    bool run = true;
    SDL_Event event;

    preProcessor(renderer);

    while (run)
    {
        frameStart = SDL_GetTicks();
        SDL_RenderClear(renderer);

        mainLoop(deltaTime, &run, event, renderer, window);

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        frameTime = frameEnd - frameStart;
        deltaTime = (float)(frameTime / 2);
    }
    
    closeEngine(window, renderer);

    return 0;
}