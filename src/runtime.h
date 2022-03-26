#pragma once

void mainLoop(float deltaTime, bool *run, SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

void preProcessor(SDL_Renderer* renderer);
void closeEngine(SDL_Window* window, SDL_Renderer* renderer);