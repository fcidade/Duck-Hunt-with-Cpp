#include "game.h"

unsigned int Game::round=1, Game::counter=0, Game::match=0;
bool Game::hasStart=false;

void Game::Start(){
    /*if(match < 10){
        ducks.clear();
        sleep(2);
        Game::SpawnEnemy();
        hasStart = true;
        Player::ammo = 3;
        counter = 0;
        match++;
        char aux1[10];
        sprintf(aux1, "%d", Player::ammo);
        std::cout << aux1 << std::endl;
        s_ammo = TTF_RenderText_Shaded(font, aux1, {255,255,255}, {0,0,0});
        for(int i=0; i<10; i++){
            if(ducks_interface[i] == ACTUAL){
                ducks_interface[i] = ALIVE;
            }
        }
        ducks_interface[match-1] = ACTUAL;
    }else{
        NextMatch();
    }*/
}

void Game::SpawnEnemy(){
    /*Duck d(rand() % 3 + 3);
    d.sprite = duck_skins[0];
    ducks.push_back(d);
    ducks.push_back(d);*/
}

void Game::IncreaseCounter(){
    /*counter++;
    if(counter > 2000){
        Loose();
    }else if(ducks.size() <= 0){
        Win();
    }*/
}

void Game::Loose(){
    /*std::cout << "You loose!" << std::endl;
    hasStart = false;
    Start();*/
}

void Game::Win(){
    /*std::cout << "You win!" << std::endl;
    hasStart = false;
    Start();*/
}

void Game::NextMatch(){
    /*match = 0;
    round++;
    for(int i=0; i<10; i++){
        ducks_interface[i] = ALIVE;
    }
    char aux[20];
    sprintf(aux, "%d", Game::round);
    s_round = TTF_RenderText_Solid(font, aux, {255,255,255});
    Start();*/
}