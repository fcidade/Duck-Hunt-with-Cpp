#include <SDL2/SDL.h>
#include <string>
#include <map>

namespace Graphs{

	extern std::map<std::string, SDL_Texture*> files;

	SDL_Texture* load(SDL_Renderer *renderer, std::string path);

};