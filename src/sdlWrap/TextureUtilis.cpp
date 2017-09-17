//
// Created by dario on 07/09/17.
//

#include "Texture.hpp"

namespace sdl
{
std::list<Texture *> coverArea(const Texture& instance, const SDL_Rect &area)
{
	return coverArea(instance, area.x, area.y, area.w, area.h);
}

std::list<Texture *> coverArea(const Texture& instance, const int x, const int y, const unsigned int width, const unsigned int height)
{
	// Variabili
	std::list<Texture *> tiles = std::list<Texture*>();

	// Ciclo tutto e tutti
	for(unsigned int w = 0; w < width; w += instance.getPosition().w)
		for(unsigned int h = 0; h < height; h += instance.getPosition().h)
		{
			Texture *tile = new Texture(instance);
			tile->setPosition(w+x, h+y);
			tiles.push_back(tile);
		}

	return  tiles;
}

/**
 * Destroy in memory all references to the tiles.
 * After the list is empty;
 * @param tiles An std::list
 */
void destroyAreaList(std::list<Texture*> &tiles)
{
	for(auto i= tiles.begin(); i != tiles.end(); i++)
		delete *i;

	tiles.clear();
}
}