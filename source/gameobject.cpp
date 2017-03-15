#include "gameobject.h"
// Constructors

GameObject::GameObject(std::string n, SDL_Renderer* r){
	this->x(0);
	this->y(0);
	this->w(200);
	this->h(200);
	this->name(n);
	this->active(true);
}

GameObject::GameObject(std::string n, SDL_Renderer* r, SDL_Texture* t=NULL){
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

void GameObject::update(double delta){}

// Getters

double GameObject::x(){
	return this->_x;
}

double GameObject::y(){
	return this->_y;
}

double GameObject::w(){
	return this->_w;
}

double GameObject::h(){
	return this->_h;
}

SDL_Rect* GameObject::pos(){
	this->_pos.x = this->x();
	this->_pos.y = this->y();
	this->_pos.w = this->w();
	this->_pos.h = this->h();
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

GameObject* GameObject::x(double n){
	this->_x = n;
	this->_pos.x = n;
	return this;
}

GameObject* GameObject::y(double n){
	this->_y = n;
	this->_pos.y = n;
	return this;
}

GameObject* GameObject::w(double n){
	this->_w = n;
	this->_pos.w = n;
	return this;
}

GameObject* GameObject::h(double n){
	this->_h = n;
	this->_pos.h = n;
	return this;
}

GameObject* GameObject::pos(SDL_Rect r){
	this->_pos = r;
	return this;
}

GameObject* GameObject::pos(double x, double y, double w, double h){
	this->_pos.x = x;
	this->_pos.y = y;
	this->_pos.w = w;
	this->_pos.h = h;
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
	// Get texture size
	int tempW, tempH;
	SDL_QueryTexture(t, NULL, NULL, &tempW, &tempH);
	SDL_Rect rect = {0, 0, tempW, tempH};
	// Set texture position
	this->texPos(rect);
	this->_texture = t;
	return this;
}

GameObject* GameObject::active(bool a){
	this->_active = a;
	return this;
}
