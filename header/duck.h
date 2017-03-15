#include "gameobject.h"
#include "timer.h"
#include <SDL2/SDL.h>

#ifndef DUCK_H
#define DUCK_H
class Duck : public GameObject{
	public:
		Duck(std::string, SDL_Renderer*);
		void update(double) override;
	private:
		int _dir, _vel;
		Timer _dirTimer;
};
#endif