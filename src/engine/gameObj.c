#include "gameObj.h"
#include <SDL2/SDL_image.h>

SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = NULL;

    loadedSurface = IMG_Load(filename);
    if (loadedSurface == NULL) {
        printf("Error loading texture, SDL error: %s\n", SDL_GetError());
        return -1;
    }

    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
        printf("Error loading texture, SDL error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_FreeSurface(loadedSurface);
    return newTexture;
}


gameObj createStaticGameObj(int imgWidth, int imgHeight, float x, float y, int hitboxW, int hitboxH) {
    hitbox newHitbox;
    gameObj newGameobj;

    newHitbox.height = hitboxH;
    newHitbox.width = hitboxW;
    newHitbox.x = x - (hitboxW - imgWidth)/2/imgWidth;
    newHitbox.y = y - (hitboxH - imgHeight)/2/imgHeight;
    newGameobj.hitbox = newHitbox;
    newGameobj.behaviour = sttc;
    newGameobj.x = x;
    newGameobj.y = y;
    newGameobj.img_h = imgHeight;
    newGameobj.img_w = imgWidth;

    return newGameobj;
}

gameObj createDinamicGameObj(int imgWidth, int imgHeight, float x, float y, int hitboxW, int hitboxH, float speed) {
    gameObj newGameobj = createStaticGameObj(imgWidth, imgHeight, x, y, hitboxW, hitboxH);
    newGameobj.behaviour = dnmc;
    newGameobj.dynamic.speed = speed;
    newGameobj.dynamic.ySpeed = 0.0f;
    newGameobj.dynamic.isJump = false;
    newGameobj.dynamic.isMove = false;

    return newGameobj;
}

void moveGameobj(gameObj* obj, float deltaTime, const float gravCon) {
    if (obj->hitbox.colDir.bottom == NULL) {
        obj->dynamic.ySpeed += gravCon;
        obj->dynamic.direction.y = down;
    }

    else {
        obj->dynamic.ySpeed = 0;
        obj->dynamic.direction.y = noneDirY;
    }

    float yspeed = obj->dynamic.ySpeed * deltaTime;
    obj->y += (yspeed < 1)? yspeed : 0.9999f;
    obj->hitbox.y += (yspeed < 1)? yspeed : 0.9999f;

}

void updateGameobjPos(gameObj obj, int msX, int msY, gameObj map[msX][msY], int prevPosX, int prevPosY) {
    map[prevPosX][prevPosY] = noneGameobj;
    int x = (int)obj.x;
    int y = (int)obj.y;

    map[x][y] = obj;
}
