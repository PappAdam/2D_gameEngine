#pragma once
#include <stdbool.h>


typedef struct colDir {
    bool top;
    bool bottom;
    bool left;
    bool right;
} collisionDir;

typedef struct hitbox
{
    collisionDir colDir;
    int width;
    int height;
} hitbox;
