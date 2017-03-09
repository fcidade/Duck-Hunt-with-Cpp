#include "gameobject.h"
#include <SDL2/SDL.h>

#ifndef DUCK_H
#define DUCK_H
class Duck : public GameObject{
    public:
    	Duck(std::string, SDL_Texture*);
        void loop();
        void create();
};
#endif