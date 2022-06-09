#include"Apple.h"

Apple::Apple(SDL_Window* argWindow, SDL_Renderer* argRenderer){
    window = argWindow;
    renderer = argRenderer;
    rect.x = 8 * 6;
    rect.y = 8 * 6;
    rect.h = 8;
    rect.w = 8;
}

Apple::~Apple(){

}

void Apple::Event(){

}

void Apple::Update(){

}

void Apple::Render(){
    SDL_SetRenderDrawColor(renderer, 200, 30, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Apple::Collision(){
    
}