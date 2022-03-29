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

void updateGameobjPos(gameObj obj, int msX, int msY, gameObj map[msX][msY], int prevPosX, int prevPosY) {
    map[prevPosX][prevPosY] = noneGameobj;
    map[(int)obj.x][(int)obj.y] = obj;
}
