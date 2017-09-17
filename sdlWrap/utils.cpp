//
// Created by dario on 11/09/17.
//
#include <iostream>
#include <SDL_ttf.h>
#include "sdlWrap.hpp"

namespace sdl
{

bool running = 0;

int init() throw()
{
	SDL_SetError("Init...");

	std::clog << "Init SDL 2 environment!                    ";
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::clog << "[ FAIL ]\n";
		throw Exception(SDL_GetError(), __LINE__ - 1, __FILE__);
	}

	std::clog <<     "[  0K  ]\n";

	std::clog << "Init SDL 2 TTF extensions environment!     ";
	if(TTF_Init())
	{
		std::clog << "[ FAIL ]\n";
		throw Exception(SDL_GetError(), __LINE__ - 1, __FILE__);
	}

	std::clog <<     "[  0K  ]\n";

	running = 1;

	return 0;
}

void dispose()
{
	std::clog << "Quitting SDL 2 TTF extension!\n";
	TTF_Quit();
	std::clog << "Quitting SDL 2 environment!\n";
	SDL_Quit();
	std::clog << "All quit. No errors!\n";
	running = 0;
}

bool isRunning()
{
	return running;
}

}