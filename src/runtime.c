#include "engine/engine.h"
#include <stdbool.h>

#define mapsizeX 300
#define mapsizeY 200

gameObj map[mapsizeX][mapsizeY];
SDL_Rect dstRect;
mouse mainMouse;
camera mainCamera = {.isMoveable = true, .speed = 1};

void handleEvents(SDL_Event event, bool* run) {
    while(SDL_PollEvent(&event)) {
        switch (event.type) 
        {
            case SDL_QUIT:
                *run = false;
                break;
            
            default:
                break;
            
            case SDL_MOUSEMOTION:
                mainMouse.x = event.motion.x;
                mainMouse.y = event.motion.y;
        }
    }
}


void mainLoop(float deltaTime, bool *run, SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
    handleEvents(event, run);

}


void preProcessor(SDL_Renderer* renderer) {

}


void closeEngine(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );


    SDL_Quit();
    IMG_Quit();  
}