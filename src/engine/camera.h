#pragma once
#include <stdbool.h>
#include "mouse.h"
#include <SDL2/SDL.h>

typedef struct camera
{
    float zoom;
    float xoffset, yoffset;
    int speed;
    bool isMoveable;
} camera;

void moveCam(camera *cam, mouse mouse_, int mW, int mH, float deltaTime);
