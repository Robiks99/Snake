#ifndef APPLE_H
#define APPLE_H

#include"SDL2/SDL.h"
#include<stdio.h>
#include <cstdlib>
#include <ctime>

class Apple{
public:
    Apple(SDL_Window* argWindow, SDL_Renderer* argRenderer);
    ~Apple();

    SDL_Rect GetRect(){return rect;}
    void Event();
    void Update();
    void Render();
    void Collision(SDL_Rect* argRect, int argSnakeLength);
private:
    SDL_Rect rect;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif