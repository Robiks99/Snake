#include"Game.h"

Game::Game(const char* title, int xpos, int ypos, int width, int height){
    //Initialize SDL
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0){//Initialize SDL
            printf("Subsystem initialized.\n");
        

        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);//Initialize Window
        if(window){
            printf("Window initialized.\n");
        }

        renderer = SDL_CreateRenderer(window,-1,0);//Initialize Renderer
        if(renderer){
            printf("Renderer initialized.\n");
        }
        SDL_SetWindowBordered( window, SDL_FALSE );//Disable window top bar

        
    }
    else{
        
        return;
    }
}

Game::~Game(){

}

void Game::Event(){

}

void Game::Update(){

}

void Game::Render(){

}
