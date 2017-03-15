#include "duck.h"
#include "graphs.h"
#include <random>
#include <iostream>

Duck::Duck(std::string n, SDL_Renderer* r) : GameObject(n, r){
	this->tex(Graphs::load(r, "sprites/duck.gif"));
	this->x(rand() % 4 * 100); //TODO: FIX FOR ALL SCREENS
	this->y(10); //TODO: FIX FOR ALL SCREENS
	this->w(77); //FIX
	this->h(77); //FIX
	this->name(n);
	SDL_Rect tmp = {0, 0, 77, 77}; //TODO: GetFrame on Graphs file
	this->texPos(tmp);
	this->active(true);
	this->_vel = 1;
	this->_dir = 1;
	this->_dirTimer.start();
}

void Duck::update(double delta){
	this->y(this->y() + (delta * this->_vel));
	this->x(this->x() + (delta * this->_dir));
	if(this->_dirTimer.getTicks() > 0.3f * 10000){ //Fix to all screen sizes
		_dirTimer.start();
		this->_dir *= -1;
	}
	
}
/*
void Duck::Move(){
	if(timer > SPEED/5){

		if(rand() % 300 + 1 > 299){
			dirx *= -1;
		}
	}	
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
	return false;
}

void Duck::Die(){
	/*isDead = true;
	for(obj : _objects){
		if(ducks[i].isDead){
			ducks.erase(ducks.begin() + i);
			Player::score += 500;
			char aux[20];
			sprintf(aux, "%d", Player::score);
			s_score = TTF_RenderText_Shaded(font, aux, {255,255,255}, {0,0,0});
			ducks_interface[Game::match-1] = DEAD;
		}
	}
}
*/