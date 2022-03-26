#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gameObj.h"
#include "mouse.h"
#include "camera.h"
#include <stdbool.h>

void initEngine();

void handleClock(Uint32 frameStart, Uint16 FPS, float *deltaTime, float deltaTimeRatio);