#include "graphs.h"
#include <iostream>
#include <SDL2/SDL_image.h>

namespace Graphs{

	std::map<std::string, SDL_Texture*> files;

	SDL_Texture* load(SDL_Renderer *renderer, std::string path){
		SDL_Texture *tex;
		// Search if the file already exists in the map
		auto it = files.find(std::string(path));
		// If it exist, return texture;
		if(it != files.end()){
			return it->second;
		}else{
			// If it doesn't exist, load the image file into a surface
			SDL_Surface *surface = IMG_Load(path.c_str());
			if(surface){
				// If nothing goes wrong, create a texture from surface
				tex = SDL_CreateTextureFromSurface(renderer, surface);
				if(!tex){
					std::cout << "graphs.cpp: Could not create texture" << std::endl;
				}
				SDL_FreeSurface(surface);
			}else{
				std::cout << "graphs.cpp: Could not load surface" << std::endl;
			}
			// Insert the file into the map
			files.insert(std::pair<std::string, SDL_Texture*>(std::string(path), tex));
		}
		return tex;
	}
};