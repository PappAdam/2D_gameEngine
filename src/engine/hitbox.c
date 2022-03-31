#include <stdbool.h>
#include <stdio.h>
#include "gameObj.h"

void collisionDet(int msX, int msY, gameObj* obj, gameObj map[msX][msY], int mapPosX, int mapPosY, int tileSize) {
    obj->hitbox.colDir.bottom = false;
    int dy = obj->hitbox.y - obj->y;
    int dx = obj->hitbox.x - obj->x;

    if (map[mapPosX][(int)obj->y + 1].behaviour != NULL && map[mapPosX][(int)obj->y + 1].hitbox.y * tileSize <= obj->hitbox.y * tileSize + obj->hitbox.height) {
        obj->hitbox.y = (map[mapPosX][(int)obj->y + 1].hitbox.y * tileSize - obj->hitbox.height)/tileSize;
        obj->y = obj->hitbox.y + dy;
        obj->hitbox.colDir.bottom = true;
    }
}