#ifndef Main_H
#define Main_H

#include<SDL2/SDL.h>
#include "GameState.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>
GameState gameState;
Game* game;

SDL_Window* window;
SDL_Renderer* renderer;

static void WaitForFrame(int argFPS);


#endif