#ifndef Game_H
#define Game_H

#include<SDL2/SDL.h>
#include<stdio.h>
#include"GameState.h"
#include"Snake.h"

class Game{
public:
    Game(SDL_Window* Window, SDL_Renderer* Renderer);
    ~Game();

    void Event(GameState &gameState);
    void Update();
    void Render();
    void clear();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    Snake *snake;

};

#endif