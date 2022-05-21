#include "main.h"

int main(int argc, const char* argv[]){
    gameState = GAME;
    game = new Game("snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,620,480);
    while(gameState != EXIT){
        while(gameState == GAME){
            game->Event();
            game->Update();
            game->Render();
        }
    }
    return 0;
}