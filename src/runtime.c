#include "engine/engine.h"
#include <stdbool.h>

// #define mapsizeX 30
// #define mapsizeY 30

// Uint8 tileSize = 64; 

// static const float gravCon = 0.0064;

// gameObj map[mapsizeX][mapsizeY];
// SDL_Rect dstRect;
// mouse mainMouse;
// camera mainCamera = {.isMoveable = true, .speed = 3};
// SDL_Rect dstRect;

// SDL_Texture* tileTexture;
// SDL_Texture* charTexture;


void handleEvents(SDL_Event event, bool* run) {
    while(SDL_PollEvent(&event)) {
        switch (event.type) 
        {
            case SDL_QUIT:
                *run = false;
                break;
            
            // case SDL_MOUSEMOTION:
            //     mainMouse.x = event.motion.x;
            //     mainMouse.y = event.motion.y;
            //     break;
            
            // case SDL_KEYDOWN:
            //     switch (event.key.keysym.sym)
            //     {
            //         case SDLK_ESCAPE:
            //             *run = false;
            //             break;

            //         case SDLK_s:
            //             break;
                    
            //         default:
            //             break;
            //     }

            default:
                break;
        }
    }
}


void mainLoop(float deltaTime, bool *run, SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
    handleEvents(event, run);
    // moveCam(&mainCamera, mainMouse, 1920, 1080, deltaTime);
    // for (int x = 0; x < mapsizeX; x++) {
    //     for (int y = 0; y < mapsizeY; y++) {
    //         if (map[x][y].behaviour == sttc) {
    //             dstRect.x = map[x][y].x*map[x][y].img_w + mainCamera.xoffset;
    //             dstRect.y = map[x][y].y*map[x][y].img_h + mainCamera.yoffset;
    //             dstRect.w = map[x][y].img_w;
    //             dstRect.h = map[x][y].img_h;

    //             SDL_RenderCopy(renderer, tileTexture, NULL, &dstRect);
    //         }
    //         if (map[x][y].behaviour == dnmc) {
    //             moveGameobj(&map[x][y], deltaTime, gravCon);
    //             collisionDet(mapsizeX, mapsizeY, &map[x][y], map, x, y, tileSize);
                
    //             dstRect.x = map[x][y].x*tileSize + mainCamera.xoffset;
    //             dstRect.y = map[x][y].y*tileSize + mainCamera.yoffset;
    //             dstRect.w = map[x][y].img_w;
    //             dstRect.h = map[x][y].img_h;
    //             SDL_RenderCopy(renderer, charTexture, NULL, &dstRect);


    //             updateGameobjPos(map[x][y], mapsizeX, mapsizeY, map, x, y);
    //         }
    //     }
    // }
}


void preProcessor(SDL_Renderer* renderer) {
    // mainCamera.yoffset = 5*64;
    // tileTexture = loadTexture("tile.png", renderer);
    // charTexture = loadTexture("char.png", renderer);
    // int img_w, img_h;
    // img_w = 64;
    // img_h = 64;
    // for (int x = 0; x < mapsizeX; x++) {
    //     for (int y = 10; y < mapsizeY; y++) {
    //         map[x][y] = createStaticGameObj(img_w, img_h, x, y, img_w, img_h+32);
    //     }
    // }
    // map[6][1] = createDinamicGameObj(img_w, img_h, 6, 1, img_w, img_h, 0);
}


void closeEngine(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    // SDL_DestroyTexture(tileTexture);
    // SDL_DestroyTexture(charTexture);

    SDL_Quit();
    IMG_Quit();  
}