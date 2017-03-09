#include <string>
#include <SDL2/SDL.h>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
class GameObject{
    public:
    	GameObject(std::string, SDL_Texture*);
    	void draw(SDL_Renderer*);
    	std::string name();
    	SDL_Texture* tex();
    	bool active();
    	int x();
    	int y();
    	int w();
    	int h();
    	SDL_Rect* pos();
    	SDL_Rect* texPos();
    	GameObject* name(std::string);
    	GameObject* tex(SDL_Texture*); //Todo: Overload to set _texPos too
    	GameObject* active(bool);
    	GameObject* x(int);
    	GameObject* y(int);
    	GameObject* w(int);
    	GameObject* h(int);
    	GameObject* pos(SDL_Rect);
    	GameObject* texPos(SDL_Rect);
    private:
        std::string _name;
        SDL_Texture *_texture;
        SDL_Rect _texPos; //TODO: Getter and Setter
        SDL_Rect _pos;
        bool _active;
};
#endif
