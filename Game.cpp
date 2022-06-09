#include"Game.h"

Game::Game(SDL_Window* Window, SDL_Renderer* Renderer){
    window = Window;
    renderer = Renderer;

    //Initialize SDL
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0){//Initialize SDL
            printf("Subsystem initialized.\n");
        

        window = SDL_CreateWindow("snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);//Initialize Window
        if(window){
            printf("Window initialized.\n");
        }

        renderer = SDL_CreateRenderer(window,-1,0);//Initialize Renderer
        if(renderer){
            printf("Renderer initialized.\n");
        }
        //SDL_SetWindowBordered( window, SDL_FALSE );//Disable window top bar

        //initialize Objects
        snake = new Snake(window, renderer);
        apple = new Apple(window, renderer);
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
        snake->Event(event);
    }
}

void Game::Update(){
    snake->Update();
    if(snake->Collision(apple->GetRect())){
        snake->IncreaseSnakeLength();
    }
}

void Game::Render(){
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);
    
    apple->Render();
    snake->Render();
    
    SDL_RenderPresent(renderer);
    
    

}

void Game::clear(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("Game cleared");
}
