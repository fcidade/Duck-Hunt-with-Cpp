#include "gameobject.h"
#include "player.h"
#include "game.h"
#include "duck.h"
#include "engine.h"

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

//Interface ducks types
enum duck_apparence{
    ALIVE=0,
    DEAD=1,
    ACTUAL=2
};

//GAME INFO
const int SCREEN_W = 650, SCREEN_H = 600;
const char GAME_NAME[255] = "Duck Hunt";
int ENEMY_W, ENEMY_H;
int ducks_interface[] = {ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE, ALIVE};
SDL_Surface *s_ducks_interface;
SDL_Rect r_duck_interface[3];

//Fonts
SDL_Rect r_ammo;
SDL_Rect r_score;
SDL_Rect r_hit;
SDL_Rect r_round;
SDL_Surface *s_ammo=NULL;
SDL_Surface *s_score=NULL;
SDL_Surface *s_round;
SDL_Surface *s_static_text[4];

//SDL VARIABLES
SDL_Surface *screen=NULL;

//SPRITES
SDL_Surface *background=NULL;
SDL_Surface *duck_skins[3]={NULL,NULL,NULL};
SDL_Rect clip[10];

//Game Characters
std::vector<Duck> ducks;





void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* c){
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //SDL_BlitSurface(source, c, destination, &offset);
}

void Shoot(int cx, int cy){
    /*for(int i=0; i<ducks.size(); i++){
        if(ducks[i].Intersects(cx, cy)){
            ducks[i].Die();
        }
    }
    Player::ammo--;
    char aux1[10];
    sprintf(aux1, "%d", Player::ammo);
    s_ammo = TTF_RenderText_Shaded(font, aux1, {255,255,255}, {0,0,0});*/
}

bool isLocked = false;


int frame_timer=0;
int anim_frame = 0;
void AnimateDucks(std::vector<Duck>& gb, SDL_Surface* destination, SDL_Rect* tiles, int sprites){
    /*for(int i=0; i<gb.size(); i++){
        if(frame_timer>50){
            anim_frame = rand()%sprites;
            frame_timer=0;
        }
        apply_surface(gb[i].x, gb[i].y, gb[i].sprite, screen, &tiles[anim_frame]);
    }
    frame_timer++;
    std::cout << frame_timer << std::endl;*/
}

//-------------

int main ( int argc, char** argv ){

	Engine engine;
    engine.init();

    return 0;
}
