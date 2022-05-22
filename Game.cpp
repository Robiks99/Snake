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
        //SDL_SetWindowBordered( window, SDL_FALSE );//Disable window top bar

        
    }
    else{
        
        return;
    }
}

Game::~Game(){

}

void Game::Event(GameState &gameState){
    SDL_Event event;
    while( SDL_PollEvent( &event ) != 0  ){
        if( event.type == SDL_QUIT )//User requests quit
        {
           gameState = EXIT;
        }
    }
}

void Game::Update(){

}

void Game::Render(){

}
