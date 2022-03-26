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


gameObj createStaticGameObj(int width, int height, float x, float y) {
    hitbox newHitbox;
    gameObj newGameobj;

    newHitbox.height = height;
    newHitbox.width = width;
    newGameobj.hitbox = newHitbox;
    newGameobj.behaviour = sttc;
    newGameobj.x = x;
    newGameobj.y = y;

    return newGameobj;
}

gameObj createDinamicGameObj(int width, int height, float x, float y, float speed) {
    gameObj newGameobj = createStaticGameObj(width, height, x, y);
    newGameobj.behaviour = dnmc;
    newGameobj.dinamic.speed = speed;
    newGameobj.dinamic.ySpeed = 0.0f;
    newGameobj.dinamic.isJump = false;
    newGameobj.dinamic.isMove = false;

    return newGameobj;
}
