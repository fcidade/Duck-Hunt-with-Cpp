#include "engine.h"
#include "graphs.h"
#include "duck.h"
#include "background.h"
#include "timer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <random>

/* Start the engine */
void Engine::init(){

	//Default screen sizes;
	this->width(680);
	this->height(460);

	/* Check if SDL2, SDL2_ttf and SDL2_image inits */
	if(SDL_Init(SDL_INIT_EVERYTHING) != -1){
		if(TTF_Init() != -1){
			if(IMG_Init(IMG_INIT_PNG) != -1){
				
				// Create window
				this->_window = SDL_CreateWindow("Duck++",
												SDL_WINDOWPOS_UNDEFINED,
												SDL_WINDOWPOS_UNDEFINED,
												this->width(),
												this->height(),
												SDL_WINDOW_SHOWN);
				if(this->_window){ // Check if window was successful created
					this->renderer(SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED));
					if(this->renderer()){ // Check if renderer was successful created
						SDL_SetRenderDrawColor(this->renderer(), 0xff, 0xff, 0xff, 0xff);
					}
				}

			}else{
				std::cout << "engine.cpp: Failed to init SDL Image" << std::endl << SDL_GetError() << std::endl;
				this->quit(2);
			}
		}else{
			std::cout << "engine.cpp: Failed to init SDL TTF" << std::endl << SDL_GetError() << std::endl;
			this->quit(2);
		}
	}else{
		std::cout << "engine.cpp: Failed to init SDL" << std::endl << SDL_GetError() << std::endl;
		this->quit(2);
	}

	// Instantiate objects
	
	{
		auto background = std::make_shared<Background>("Background", this->renderer());
		background->x(0)->y(0)->w(this->width())->h(this->height());
		_objects.push_back(background);
	}

	{
		auto duckA = std::make_shared<Duck>("Duck A", this->renderer());
		_objects.push_back(duckA);
	}

	srand(static_cast<unsigned int>(time(0)));

	//font = TTF_OpenFont("Munro.ttf", 24);

	//Interface Text
	/*SDL_Color white = {255,255,255};

	unsigned int interface_y = SCREEN_H - (SCREEN_H/8.5);
	r_ammo = {SCREEN_W / 10, interface_y, 0, 0};
	r_score = {SCREEN_W - (SCREEN_W / 4.5), interface_y, 0, 0};
	r_round = {SCREEN_W/10, SCREEN_H - SCREEN_H/5, 0, 0};
	s_ammo = TTF_RenderText_Shaded(font, "3", white, {0,0,0});
	s_score = TTF_RenderText_Shaded(font, "0", white, {0,0,0});
	s_round = TTF_RenderText_Solid(font, "1", white);
	s_static_text[0] = TTF_RenderText_Solid(font, "R = ", white);
	s_static_text[1] = TTF_RenderText_Solid(font, "Hit", white);
	s_static_text[2] = TTF_RenderText_Solid(font, "Score", white);
	s_static_text[3] = TTF_RenderText_Solid(font, "Ammo", white);

	//Load Sprites
	r_hit = {SCREEN_W/3, interface_y, 0, 0};

	std::string sprites[3] = {"sprites/background.gif", "sprites/duck.gif", "sprites/interface.gif"};
	background = IMG_Load(sprites[0].c_str());
	duck_skins[0] = IMG_Load(sprites[1].c_str());
	s_ducks_interface = IMG_Load(sprites[2].c_str());

	const int SPRITE_W = 77;
	const int SPRITE_H = 77;

	clip[0] = {0*0, 0, SPRITE_W, SPRITE_H};
	clip[1] = {SPRITE_W*1, 0, SPRITE_W, SPRITE_H};
	clip[2] = {SPRITE_W*2, 0, SPRITE_W, SPRITE_H};

	r_duck_interface[ALIVE] = {0, 20, 18, 20};
	r_duck_interface[DEAD] = {0, 68, 18, 20};
	r_duck_interface[ACTUAL] = {0, 106, 18, 20};

	//SET ENEMY SIZE
	ENEMY_W = clip[0].w;
	ENEMY_H = clip[0].h;*/


	this->loop();

}

void Engine::loop(){

	//Game::Start();

	double deltaTime = 0.0;
	double clock = SDL_GetTicks(); //Chage it to my timer class
	double renderTime = 0;

	while(true){

		deltaTime = SDL_GetTicks() - clock;
		clock = SDL_GetTicks();

		SDL_PollEvent(&this->_event);

		switch(this->_event.type){
			case SDL_QUIT:
				this->quit(0);
				break;
		}

		for(auto obj : this->_objects){
			obj->update(deltaTime/10);
		}

		if(renderTime >= (1.0f/60.0f)){
			this->draw();
			renderTime -= (1.0f/60.0f);
		}
		renderTime += deltaTime;
		

	}

	/*for(int i=0; i<ducks.size(); i++){
		ducks[i].Move();
	}

	if(event.type == SDL_MOUSEBUTTONDOWN && !isLocked){
		isLocked = true;
		int cx = event.motion.x;
		int cy = event.motion.y;
		if(Player::ammo > 0){
			Shoot(cx, cy);
		}else
			std::cout << "Out of ammo." << std::endl;
	}else if(event.type == SDL_MOUSEBUTTONUP){
		isLocked = false;
	}
	*/
}

void Engine::draw(){

	SDL_RenderClear(this->renderer());

	for(auto obj : this->_objects){
		obj->draw(this->renderer());
	}

	//apply_surface(0, 0, background, screen, NULL);

	/*AnimateDucks(ducks, screen, clip, 3);

	//INTERFACE

	apply_surface(r_ammo.x, r_ammo.y, s_ammo, screen, NULL);
	apply_surface(r_score.x+20, r_score.y, s_score, screen, NULL);
	apply_surface(r_round.x+40, r_round.y+9, s_round, screen, NULL);

	for(int i=0; i<10; i++){
		apply_surface((r_hit.x/10)*i+SCREEN_W/3, r_hit.y, s_ducks_interface, screen, &r_duck_interface[ducks_interface[i]]);
	}

	apply_surface(r_round.x, r_round.y+9, s_static_text[0], screen, NULL);
	apply_surface(r_hit.x - 50, r_hit.y, s_static_text[1], screen, NULL);
	apply_surface(r_score.x + 22, r_score.y + 20, s_static_text[2], screen, NULL);
	apply_surface(r_ammo.x - 2, r_ammo.y + 20, s_static_text[3], screen, NULL);*/

	SDL_RenderPresent(this->renderer());

}

void Engine::quit(int flag){
	SDL_DestroyRenderer(this->renderer());
	SDL_DestroyWindow(this->_window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	exit(flag);
}

// Getter
size_t Engine::width(){
	return this->_screen_width;
}
size_t Engine::height(){
	return this->_screen_height;
}

SDL_Renderer* Engine::renderer(){
	return this->_renderer;
}

// Setter
Engine* Engine::width(size_t w){
	this->_screen_width = w;
	return this;
}
Engine* Engine::height(size_t h){
	this->_screen_height = h;
	return this;
}

Engine* Engine::renderer(SDL_Renderer* r){
	this->_renderer = r;
	return this;
}