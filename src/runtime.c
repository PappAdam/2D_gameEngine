#include "engine/engine.h"

void handleEvents(SDL_Event event, bool* run) {
    while(SDL_PollEvent(&event)) {
        switch (event.type) 
        {
            case SDL_QUIT:
                *run = false;
                break;
            
            default:
                break;
        }
    }
}

void mainLoop(float deltaTime) {

}

void preProcesses() {

}