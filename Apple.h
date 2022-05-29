#ifndef APPLE_H
#define APPLE_H

#include"SDL2/SDL.h"
#include<stdio.h>

class Apple{
public:
    Apple();
    ~Apple();

    SDL_Rect GetRect(){return rect;}
    void Event();
    void Update();
    void Render();
    void Collision();
private:
    SDL_Rect rect;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif