#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include "engine.h"

void initEngine() {
    SDL_Init( SDL_INIT_VIDEO );
    IMG_Init(IMG_INIT_PNG);
}

static Uint32 limitFrameRate(Uint32 frameStart, Uint16 FPS, Uint32 *frameTime) {
    *frameTime = SDL_GetTicks() - frameStart;

    if (*frameTime < 1000/FPS) {
        SDL_Delay((1000/FPS) - *frameTime);
        *frameTime = FPS;
    }
}
