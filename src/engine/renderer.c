#include "renderer.h"

void renderScene(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);


    SDL_RenderPresent(renderer);
}
