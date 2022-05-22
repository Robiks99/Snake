#ifndef Game_H
#define Game_H

#include<SDL2/SDL.h>
#include<stdio.h>
#include"GameState.h"

class Game{
public:
    Game();
    Game(const char* title, int xpos, int ypos, int width, int height);
    ~Game();

    void Event(GameState &gameState);
    void Update();
    void Render();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;


};

#endif