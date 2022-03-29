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
} dynamicGobj;

typedef struct gameObj {
    hitbox hitbox;
    float x, y;
    int img_w, img_h;
    behaviour behaviour;
    dynamicGobj dynamic;
    SDL_Texture* texture;
} gameObj;

gameObj noneGameobj;

gameObj createStaticGameObj(int imgWidth, int imgHeight, float x, float y, int hitboxW, int hitboxH);
gameObj createDinamicGameObj(int imgWidth, int imgHeight, float x, float y, int hitboxW, int hitboxH, float speed);

void collisionDet(int msX, int msY, gameObj* obj, gameObj map[msX][msY], int mapPosX, int mapPosY);

void updateGameobjPos(gameObj obj, int msX, int msY, gameObj map[msX][msY], int prevPosX, int prevPosY);