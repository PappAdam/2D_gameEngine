#pragma once
#include <stdbool.h>

typedef struct camera
{
    float zoom;
    float xoffset, yoffset;
    int speed;
    bool isMoveable;
} camera;
