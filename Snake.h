#ifndef SNAKE_H
#define SNAKE_H

#include<stdio.h>
#include<SDL2/SDL.h>

class Snake{
public:
    Snake(SDL_Window* Window, SDL_Renderer* Renderer);
    ~Snake();

    SDL_Rect* GetRect(){return rect;}
    int GetSnakeLength(){return snakeLenght;}
    void Event(SDL_Event &event);
    void Update();
    void Render();

    bool Collision(SDL_Rect argRect);
    void SelfCollision();
    void IncreaseSnakeLength();
private:
    void ChangeDirection(SDL_Event &event);
    void Move();
    void BorderCollision();
    void SpawnNewSnakeElement();
    void DecreaseSnakeLength(int argNewLenght);
    
    void ShowRect();
    void ShowSnakeLength();

    int snakeLenght = 15;
    SDL_Rect *rect;
    SDL_Window* window;
    SDL_Renderer* renderer;
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