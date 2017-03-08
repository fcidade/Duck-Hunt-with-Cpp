#include <string>
#include <SDL2/SDL.h>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
class GameObject{
    public:
    	GameObject();
    	GameObject(std::string, SDL_Texture*);
    	std::string name();
    	SDL_Texture* tex();
    	bool active();
    	int x();
    	int y();
    	int w();
    	int h();
    	SDL_Rect rect();
    	void name(std::string);
    	void tex(SDL_Texture*);
    	void active(bool);
    	int x(int);
    	int y(int);
    	int w(int);
    	int h(int);
    	SDL_Rect rect(SDL_Rect);
    private:
        std::string _name;
        SDL_Texture *_texture;
        bool _active;
        SDL_Rect _rect;
};
#endif
