#include <stdbool.h>
#include "gameObj.h"

void collisionDet(int msX, int msY, gameObj* obj, gameObj map[msX][msY], int mapPosX, int mapPosY) {
    obj->hitbox.colDir.bottom = false;
    int Ychord = (int)obj->y + 1;
    if (map[mapPosX][Ychord].behaviour != NULL) {
        obj->hitbox.colDir.bottom = true;
        obj->y = map[mapPosX][Ychord].y - 1;
    }
}