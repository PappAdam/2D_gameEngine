#include "camera.h"
#include "mouse.h"

void moveCam(camera *cam, mouse mouse_, int maxX, int maxY, float deltaTime) { //TODO add camera lock and zoom
    if (cam->isMoveable) {
        if (mouse_.x >= maxX-20) {
            cam->xoffset -= cam->speed*deltaTime;
        } else if (mouse_.x <= 20) {
            cam->xoffset += cam->speed*deltaTime;
        }

        if (mouse_.y >= maxY-20) {
            cam->yoffset -= cam->speed*deltaTime;

        } else if (mouse_.y <= 20) {
            cam->yoffset += cam->speed*deltaTime;
        }
    }
}