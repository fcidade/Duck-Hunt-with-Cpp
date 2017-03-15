#include "background.h"
#include "graphs.h"

Background::Background(std::string n, SDL_Renderer* r) : GameObject(n, r){
	this->tex(Graphs::load(r, "sprites/background.gif"));
	this->name(n);
	this->active(true);
}

void Background::draw(SDL_Renderer* r){
	SDL_RenderCopy(r, this->tex(), NULL, this->pos());
}