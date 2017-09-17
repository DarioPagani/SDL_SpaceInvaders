//
// Created by dario on 06/09/17.
//

#include <iostream>
#include <SDL2/SDL_image.h>

#include "utils.hpp"

namespace utilis
{

SDL_Texture *loadTexure(const char *const file, SDL_Renderer *const render)
{
	// Variabili
	SDL_Texture *texture = IMG_LoadTexture(render,file);

	if(!texture)
	{
		logConsole("Errore caricando il file!");
		abort();
	}

	return  texture;
}

void logConsole(std::ostream &ostream, const std::string &logMessage)
{
	ostream << __TIME__ << " Error in SDL:\t" << logMessage << std::endl;
}

void logConsole(std::ostream &ostream, const char *const logMessage)
{
	logConsole(ostream, std::string(logMessage));
}

void logConsole(const std::string &logMessage)
{
	logConsole(std::clog, logMessage);
}

void logConsole(const char *const logMessage)
{
	logConsole(std::clog, logMessage);
}

/**
 * Renders a SDL_Texture inside an SDL_Render in a specific point!
 * @param toRender
 * @param renderer
 * @param x
 * @param y
 */
void renderTexture(SDL_Texture *const toRender, SDL_Renderer *const renderer, const int x, const int y)
{
	renderTexture(toRender, renderer, x, y, -1,-1);
}

void renderTexture(SDL_Texture *const toRender, SDL_Renderer *const renderer, const int x, const int y, const int w,
				   const int h)
{
	SDL_Rect textureWrap = {0};
	textureWrap.x = x;
	textureWrap.y = y;
	if(w > 0)
		textureWrap.w = w;

	if(h > 0)
		textureWrap.h = h;

	SDL_QueryTexture(toRender, nullptr, nullptr, &textureWrap.w, &textureWrap.h);
	SDL_RenderCopy(renderer, toRender, nullptr, &textureWrap);
}



}