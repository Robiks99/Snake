#define SDL_MAIN_HANDLED
#include "main.h"

int main(int argc, const char* argv[]){
    srand(time(0));
    gameState = GAME;
    game = new Game(window, renderer);
    while(gameState != EXIT){
        while(gameState == GAME){
            
            game->Event(gameState);
            game->Update();
            game->Render();
            
            WaitForFrame(60);
        }
    }
    game->clear();
    return 0;
}

static void WaitForFrame(int argFPS){
    Uint32 time_to_wait = 1000/argFPS;
    Uint32 time_passed = 0;
    Uint32 time_started = 0;
    while(time_to_wait > time_passed){
        time_passed = SDL_GetTicks();
    }
    time_started = SDL_GetTicks();
}