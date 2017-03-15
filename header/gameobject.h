#include <string>
#include <SDL2/SDL.h>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
class GameObject{
	public:
		GameObject(std::string, SDL_Renderer*);
		GameObject(std::string, SDL_Renderer*, SDL_Texture*);
		virtual void update(double);
		void draw(SDL_Renderer*);
		// Getters
		std::string name();
		SDL_Texture* tex();
		bool active();
		double x();
		double y();
		double w();
		double h();
		SDL_Rect* pos();
		SDL_Rect* texPos();
		// Setters
		GameObject* name(std::string);
		GameObject* tex(SDL_Texture*); //Todo: Overload to set _texPos too
		GameObject* active(bool);
		GameObject* x(double);
		GameObject* y(double);
		GameObject* w(double);
		GameObject* h(double);
		GameObject* pos(SDL_Rect);
		GameObject* pos(double x, double y, double w, double h);
		GameObject* texPos(SDL_Rect);
	protected:
		std::string _name;
		SDL_Texture *_texture;
		SDL_Rect _texPos; //TODO: Getter and Setter
		SDL_Rect _pos;
		double _x, _y, _w, _h;
		bool _active;
};
#endif
