#pragma once
#include <SDL2/SDL.h>
#include "hitbox.h"
#include <stdbool.h>

SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);

typedef enum type {
    sttc = 1,
    dnmc
} behaviour;

typedef struct dGameObj
{
    float speed;
    float ySpeed;
    bool isJump;
    bool isMove;
} dinamicGobj;

typedef struct gameObj {
    hitbox hitbox;
    float x, y;
    behaviour behaviour;
    dinamicGobj dinamic;
    SDL_Texture* texture;
} gameObj;

gameObj noneGameobj;

gameObj createStaticGameObj(int width, int height, float x, float y);