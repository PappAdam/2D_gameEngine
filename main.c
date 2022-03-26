#include "src/runtime.h"
#include <stdio.h>

int main(int argc, const char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    window = SDL_CreateWindow( "Try", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    initEngine();
    SDL_Texture* texture = loadTexture("./szia.png", renderer);
    Uint32 frameStart;
    float deltaTime;

    bool run = true;
    SDL_Event event;

    preProcesses();

    while (run)
    {
        frameStart = SDL_GetTicks();
        SDL_RenderClear(renderer);

        mainLoop(deltaTime);

        SDL_RenderPresent(renderer);
        handleClock(frameStart, 2000, &deltaTime, 1000 / 500);
    }
    
    closeEngine(window, renderer);

    return 0;
}