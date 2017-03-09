#include "duck.h"

/*Duck::Duck(int s){
    /*SPEED = s;
    timer = 0;
    Spawn();
    dirx = VEL;
    diry = -VEL;
    if(rand() % 5 + 1 > 2){
        dirx *= -1;
    }
}*/

void Duck::Move(){
    /*timer++;
    if(timer > SPEED/5){

        if(rand() % 300 + 1 > 299){
            dirx *= -1;
        }

        if(x <= 0){
            dirx *= -1;
            x = 1;
        }else if(x >= SCREEN_W){
            dirx *= -1;
            x = SCREEN_W - 1;
        }
        if(y <= 0){
            diry *= -1;
            y = 1;
        }else if(y >= SCREEN_H - (SCREEN_H / 3)){
            diry *= -1;
            y = SCREEN_H - (SCREEN_H / 3) - 1;
        }

        x+=dirx;
        y+=diry;

        timer = 0;
    }
    */
}

void Duck::Spawn(){
    // x = 20;
    // y = SCREEN_H - (SCREEN_H/3);
    // w = ENEMY_W;
    // h = ENEMY_H;
}

bool Duck::Intersects(int cx, int cy){
    /*if((x < cx && x + w > cx) &&
       (y < cy && y + h > cy)){
        return true;
    }
    return false;*/
}

void Duck::Die(){
    /*isDead = true;
    for(int i=0; i<ducks.size(); i++){
        if(ducks[i].isDead){
            ducks.erase(ducks.begin() + i);
            Player::score += 500;
            char aux[20];
            sprintf(aux, "%d", Player::score);
            s_score = TTF_RenderText_Shaded(font, aux, {255,255,255}, {0,0,0});
            ducks_interface[Game::match-1] = DEAD;
        }
    }*/
}
