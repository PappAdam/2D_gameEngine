#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameObj.h"
#include <stdbool.h>

void initEngine();
void closeEngine(SDL_Window* window, SDL_Renderer* renderer);

void handleClock(Uint32 frameStart, Uint16 FPS, float *deltaTime, float deltaTimeRatio);