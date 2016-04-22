#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

//Classes declaration
class Duck;
class Player;

//GAME INFO
const int SCREEN_W = 650, SCREEN_H = 600;
const char GAME_NAME[255] = "Duck Hunt";
int ENEMY_W, ENEMY_H;

//SDL VARIABLES
SDL_Event event;
SDL_Surface *screen=NULL;

//SPRITES
SDL_Surface *background=NULL;
SDL_Surface *duck_skins[3]={NULL,NULL,NULL};
SDL_Rect clip[1];

//Game Characters
std::vector<Duck> ducks;

//Classes
class Player{
    public:
        static int kills, fails, ammo;
        Player();
};
int Player::kills=0, Player::fails=0, Player::ammo=10;

class Duck{
    public:
        int VEL=1, SPEED = 50;
        int x, y, w, h, dirx, diry, timer;
        bool isDead = false;
        SDL_Surface *sprite;
        Duck(int s);
        void Move();
        void Spawn();
        bool Intersects(int cx, int cy);
        void Die();
};

Duck::Duck(int s){
    SPEED = s;
    timer = 0;
    Spawn();
    std::cout << rand() % 5 + 1 << std::endl;
    dirx = VEL;
    diry = -VEL;
    if(rand() % 5 + 1 > 2){
        dirx *= -1;
    }
}

void Duck::Move(){
    timer++;
    if(timer > SPEED/3){

        if(rand() % 300 + 1 > 299){
            dirx *= -1;
        }

        if(x <= 0){
            dirx *= -1;
        }else if(x >= SCREEN_W){
            dirx *= -1;
        }
        if(y <= 0){
            diry *= -1;
        }else if(y >= SCREEN_H){
            diry *= -1;
        }

        x+=dirx;
        y+=diry;

        timer = 0;
    }
}

void Duck::Spawn(){
    x = 20;
    y = SCREEN_H - (SCREEN_H/3);
    w = ENEMY_W;
    h = ENEMY_H;
}

bool Duck::Intersects(int cx, int cy){
    if((x < cx && x + w > cx) &&
       (y < cy && y + h > cy)){
        return true;
    }
    return false;
}

void Duck::Die(){
    isDead = true;
    for(int i=0; i<ducks.size(); i++){
        if(ducks[i].isDead){
            ducks.erase(ducks.begin() + i);
        }
    }
}

//Engine Methods
void LoadGame();
void Logic();
void DrawScreen();
void Quit();

void LoadGame(){

    //Fundamentals

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);

    srand(static_cast<unsigned int>(time(0)));

    SDL_WM_SetCaption(GAME_NAME, NULL);
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_SWSURFACE);

    //Load Sprites
    std::string sprites[2] = {"sprites/background.gif", "sprites/duck.gif"};
    background = IMG_Load(sprites[0].c_str());
    duck_skins[0] = IMG_Load(sprites[1].c_str());
    clip[0] = {0, 0, 67, 77};

    //SET ENEMY SIZE
    ENEMY_W = clip[0].w;
    ENEMY_H = clip[0].h;

    //Spawn enemys
    Duck d1(rand() % 3 + 3);
    d1.sprite = duck_skins[0];
    Duck d2(rand() % 3 + 3);
    d2.sprite = duck_skins[0];
    Duck d3(rand() % 3 + 3);
    d3.sprite = duck_skins[0];
    Duck d4(rand() % 3 + 3);
    d4.sprite = duck_skins[0];
    ducks.push_back(d1);
    ducks.push_back(d2);
    ducks.push_back(d3);
    ducks.push_back(d4);

}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* c){
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(source, c, destination, &offset);
}

void Shoot(int cx, int cy){
    for(int i=0; i<ducks.size(); i++){
        if(ducks[i].Intersects(cx, cy)){
            std::cout << "TESTE" << std::endl;
            ducks[i].Die();
        }
    }
    Player::ammo--;
    std::cout << "Municao: " << Player::ammo << std::endl;
}

bool isLocked = false;
void Logic(){
    for(int i=0; i<ducks.size(); i++){
        ducks[i].Move();
    }

    if(event.type == SDL_MOUSEBUTTONDOWN && !isLocked){
        isLocked = true;
        int cx = event.motion.x;
        int cy = event.motion.y;
        if(Player::ammo > 0){
            Shoot(cx, cy);
        }else
            std::cout << "Out of ammo." << std::endl;
    }else if(event.type == SDL_MOUSEBUTTONUP){
        isLocked = false;
    }

}

void DrawScreen(){

    apply_surface(0, 0, background, screen, NULL);

    for(int i=0; i<ducks.size(); i++){
        apply_surface(ducks[i].x, ducks[i].y, ducks[i].sprite, screen, &clip[0]);
    }

    SDL_Flip(screen);

}

void Quit(){
    SDL_FreeSurface(screen);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

//-------------

int main ( int argc, char** argv ){

    LoadGame();

    bool running = true;

    while(running){

        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT){
            running = false;
        }

        Logic();
        DrawScreen();

    }

    Quit();

    return 0;
}
