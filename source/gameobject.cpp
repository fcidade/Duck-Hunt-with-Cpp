#include "gameobject.h"
// Constructors

GameObject::GameObject(std::string n, SDL_Texture* t){
	this->x(0);
	this->y(0);
	this->w(200);
	this->h(200);
	this->name(n);
	this->tex(t);
	this->active(true);
}

// Engine

void GameObject::draw(SDL_Renderer* renderer){
	SDL_RenderCopy(renderer, this->tex(), this->texPos(), this->pos());
}

// Getters

int GameObject::x(){
	return this->_pos.x;
}

int GameObject::y(){
	return this->_pos.y;
}

int GameObject::w(){
	return this->_pos.w;
}

int GameObject::h(){
	return this->_pos.h;
}

SDL_Rect* GameObject::pos(){
	return &(this->_pos);
}

SDL_Rect* GameObject::texPos(){
	return &(this->_texPos);
}

std::string GameObject::name(){
	return this->_name;
}

SDL_Texture* GameObject::tex(){
	return this->_texture;
}

bool GameObject::active(){
	return this->_active;
}

// Setters

GameObject* GameObject::x(int n){
	this->_pos.x = n;
	return this;
}

GameObject* GameObject::y(int n){
	this->_pos.y = n;
	return this;
}

GameObject* GameObject::w(int n){
	this->_pos.w = n;
	return this;
}

GameObject* GameObject::h(int n){
	this->_pos.h = n;
	return this;
}

GameObject* GameObject::pos(SDL_Rect r){
	this->_pos = r;
	return this;
}

GameObject* GameObject::texPos(SDL_Rect r){
	this->_texPos = r;
	return this;
}

GameObject* GameObject::name(std::string n){
	this->_name = n;
	return this;
}

GameObject* GameObject::tex(SDL_Texture* t){
	int tempW, tempH;
	SDL_QueryTexture(t, NULL, NULL, &tempW, &tempH);
	SDL_Rect rect = {0, 0, tempW, tempH};
	this->texPos(rect);
	this->_texture = t;
	return this;
}

GameObject* GameObject::active(bool a){
	this->_active = a;
	return this;
}
