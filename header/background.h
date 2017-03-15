#include "gameobject.h"
#include <SDL2/SDL.h>

#ifndef BACKGROUND_H
#define BACKGROUND_H
class Background : public GameObject{
public:
	Background(std::string, SDL_Renderer*);
	void draw(SDL_Renderer* r);
};
#endif