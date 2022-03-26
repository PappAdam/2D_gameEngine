#pragma once

typedef enum colDir {
    top,
    left,
    right,
    down
} collisionDir;

typedef struct hitbox
{
    collisionDir colDir;
    int width;
    int height;
} hitbox;
