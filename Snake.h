#ifndef SNAKE_H
#define SNAKE_H

#include<stdio.h>
#include<SDL2/SDL.h>

class Snake{
public:
    Snake(SDL_Window* Window, SDL_Renderer* Renderer);
    ~Snake();

    SDL_Rect* GetRect(){return rect;}
    void Event(SDL_Event &event);
    void Update();
    void Render();

private:
    void ChangeDirection(SDL_Event &event);
    void Move();
    void BorderCollision();
    void SpawnNewSnakeElement();
    void IncreaseSnakeLength();
    void ShowRect();

    int snakeLenght = 15;
    SDL_Rect *rect;
    SDL_Window* window;
    SDL_Renderer* renderer;
    int xPos, yPos;
    int moveDelay;
    Uint32 startTicks = 0;
    float dT;
    int windowHeight, windowWidth;
    enum MoveDirection{
        NORTH,
        EAST,
        WEST,
        SOUTH
    };
    MoveDirection moveDirection, lookDirection;
};

#endif