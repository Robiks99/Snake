#define SDL_MAIN_HANDLED
#include "main.h"

int main(int argc, const char* argv[]){

    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    gameState = GAME;
    game = new Game("snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,620,480);
    while(gameState != EXIT){
        while(gameState == GAME){
            frameStart = SDL_GetTicks();
            
            game->Event(gameState);
            game->Update();
            game->Render();
            
            frameTime = SDL_GetTicks() - frameStart;
            if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}