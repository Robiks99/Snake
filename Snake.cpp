#include"Snake.h"
#define GREED_SIZE 8;
Snake::Snake(SDL_Window* Window, SDL_Renderer* Renderer){
    printf("Snake created");
    window = Window;
    renderer = Renderer;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    rect = new SDL_Rect[snakeLenght];
    for(int i = 0; i < snakeLenght; i++){
    rect[i].x = (-8 * i)+64;
    rect[i].y = 0;
    rect[i].w = 8;
    rect[i].h = 8;
    }
    moveDirection = EAST;
    lookDirection = EAST;
    startTicks = SDL_GetTicks64();
    moveDelay = 100;
}

Snake::~Snake(){

}

void Snake::Event(SDL_Event &event){
    ChangeDirection(event);
    if(event.key.keysym.sym == SDLK_SPACE){
        IncreaseSnakeLength();
    }
    
}

void Snake::Update(){
    Move();
    BorderCollision();
    SelfCollision();
}

void Snake::Render(){
    
    for(int i = 0; i < snakeLenght-1; i++){
        SDL_SetRenderDrawColor(renderer, (rect[i].x/4)+128, (rect[i].y/4)+128 , (rect[i].x/4)+128, 255);
        SDL_RenderFillRect(renderer, &rect[i]);
    }
    
}

void Snake::ChangeDirection(SDL_Event &event){
    if( event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_w){
            if(lookDirection != SOUTH){
                moveDirection = NORTH;
                printf("\nset move direction to NORTH");
                return;
            }
        }
        if(event.key.keysym.sym == SDLK_s){
            if(lookDirection != NORTH){
                moveDirection = SOUTH;
                printf("\nset move direction to SOUTH");
                return;
            }
        }
        if(event.key.keysym.sym == SDLK_a){
            if(lookDirection != EAST){
                moveDirection = WEST;
                printf("\nset move direction to WEST");
                return;
            }
        }
        if(event.key.keysym.sym == SDLK_d){
            if(lookDirection != WEST){
                moveDirection = EAST;
                printf("\nset move direction to EAST");
                return;
            }
        }
    }
}

void Snake::Move(){
    if(moveDelay < SDL_GetTicks64() - startTicks){
        
        
        //Move tail
        for(int i = snakeLenght-1; i > 0; i--){
            rect[i].x = rect[i-1].x;
            rect[i].y = rect[i-1].y;
        }
        //Move head
        if(moveDirection == NORTH){
            rect[0].y -= GREED_SIZE;
            lookDirection = NORTH;
        }
        if(moveDirection == SOUTH){
            rect[0].y += GREED_SIZE;
            lookDirection = SOUTH;
        }
        if(moveDirection == WEST){
            rect[0].x -= GREED_SIZE;
            lookDirection = WEST;
        }
        if(moveDirection == EAST){
            rect[0].x += GREED_SIZE;
            lookDirection = EAST;
        }
        

        startTicks = SDL_GetTicks64();
    }
}

void Snake::BorderCollision(){
    if(rect[0].x > windowWidth){
        rect[0].x = 0;
        return;
    }
    if(rect[0].x < 0){
        rect[0].x = windowWidth - GREED_SIZE;
        return;
    }
    if(rect[0].y > windowHeight){
        rect[0].y = 0;
        return;
    }
    if(rect[0].y < 0){
        rect[0].y = windowHeight - GREED_SIZE;
        return;
    }
}

void Snake::SpawnNewSnakeElement(){
    //przypisz wartość do nowego elementu
    rect[snakeLenght-1].h = GREED_SIZE;
    rect[snakeLenght-1].w = GREED_SIZE;

    if(rect[snakeLenght-1].x < rect[snakeLenght-2].x){
        rect[snakeLenght-1].x = rect[snakeLenght-2].x - GREED_SIZE;
        rect[snakeLenght-1].y = rect[snakeLenght-2].y;
    }
    if(rect[snakeLenght-1].x > rect[snakeLenght-2].x){
        rect[snakeLenght-1].x = rect[snakeLenght-2].x + GREED_SIZE;
        rect[snakeLenght-1].y = rect[snakeLenght-2].y;
    }
    if(rect[snakeLenght-1].y < rect[snakeLenght-2].y){
        rect[snakeLenght-1].y = rect[snakeLenght-2].y - GREED_SIZE;
        rect[snakeLenght-1].x = rect[snakeLenght-2].x;
    }
    if(rect[snakeLenght-1].y > rect[snakeLenght-2].y){
        rect[snakeLenght-1].y = rect[snakeLenght-2].y + GREED_SIZE;
        rect[snakeLenght-1].x = rect[snakeLenght-2].x;
    }
}

void Snake::IncreaseSnakeLength(){
    //zwiększenie ilości elementów w tablicy
    //przepisz wartości do nowej tablicy
    SDL_Rect *tmp = new SDL_Rect[snakeLenght];
    for(int i = 0; i < snakeLenght; i++){
        tmp[i] = rect[i];
    }
    snakeLenght++;
    rect = new SDL_Rect[snakeLenght];
    for(int i = 0; i < snakeLenght - 1; i++){
        rect[i] = tmp[i];
    }
    rect[snakeLenght-1].w = GREED_SIZE;
    rect[snakeLenght-1].h = GREED_SIZE;
    //ShowRect();
    ShowSnakeLength();
}

void Snake::DecreaseSnakeLength(int argNewLenght){
    SDL_Rect *tmp = new SDL_Rect[argNewLenght];
    for(int i = 0; i < argNewLenght; i++){
        tmp[i] = rect[i];
    }
    snakeLenght = argNewLenght;
    rect = new SDL_Rect[argNewLenght];
    for(int i = 0; i < argNewLenght; i++){
        rect[i] = tmp[i];
    }
}

void Snake::ShowRect(){
    for(int i = 0; i < snakeLenght-1; i++)
    printf("iteracja %i: X:%i, Y:%i, W:%i, H:%i\n",i,rect[i].x,rect[i].y,rect[i].w,rect[i].h);
}

bool Snake::Collision(SDL_Rect argRect){
    if( (rect[0].y+rect[0].h) <= argRect.y )//check bottom ball side and top rect side
    {
        return false;
    }

    if( rect[0].y >= argRect.y+argRect.h )//check top ball side and bottom rect side
    {
        return false;
    }

    if( (rect[0].x+rect[0].w) <= argRect.x )//check right ball side and left rect side
    {
        return false;
    }

    if( rect[0].x >= (argRect.x+argRect.w) )//check left ball side and right rect side
    {
        return false;
    }
    return true;
}

void Snake::SelfCollision(){
    for(int i = 2; i < snakeLenght; i++){
        if(Collision(rect[i])){
            DecreaseSnakeLength(i);
        }
    }
}

void Snake::ShowSnakeLength(){
    printf("\nSnake length: %i",snakeLenght);
}