#include "gameobject.h"

// Constructors

GameObject::GameObject(){}

GameObject::GameObject(std::string n, SDL_Texture* t){
	this->name(n);
	this->tex(t);
	this->active(true);
}

// Getters

int GameObject::x(){
	return this->_rect.x;
}

int GameObject::y(){
	return this->_rect.y;
}

int GameObject::w(){
	return this->_rect.w;
}

int GameObject::h(){
	return this->_rect.h;
}

SDL_Rect GameObject::rect(){
	return this->_rect;
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

int GameObject::x(int n){
	this->_rect.x = n;
}

int GameObject::y(int n){
	this->_rect.y = n;
}

int GameObject::w(int n){
	this->_rect.w = n;
}

int GameObject::h(int n){
	this->_rect.h = n;
}

SDL_Rect GameObject::rect(SDL_Rect r){
	this->_rect = r;
}

void GameObject::name(std::string n){
	this->_name = n;
}

void GameObject::tex(SDL_Texture* t){
	this->_texture = t;
}

void GameObject::active(bool a){
	this->_active = a;
}
